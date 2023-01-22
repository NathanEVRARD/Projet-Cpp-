#include "applicgaragewindow.h"
#include "ui_applicgaragewindow.h"
#include "Classes/Garage.h"
#include "Classes/OptionException.h"
#include "Classes/PasswordException.h"
#include <QMessageBox>
#include <QInputDialog>
#include <sstream>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int indOption = 0;

#define REPERTOIRE_IMAGES "images/"

ApplicGarageWindow::ApplicGarageWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::ApplicGarageWindow)
{
    ui->setupUi(this);

    // Configuration de la table des options (projet en cours)
    ui->tableWidgetOptions->setColumnCount(3);
    ui->tableWidgetOptions->setRowCount(5);
    for (int i=0 ; i<5 ; i++) ui->tableWidgetOptions->setRowHeight(i,10);
    QStringList labelsTableOptions;
    labelsTableOptions << "Code" << "Prix" << "Intitulé";
    ui->tableWidgetOptions->setHorizontalHeaderLabels(labelsTableOptions);
    ui->tableWidgetOptions->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetOptions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetOptions->horizontalHeader()->setVisible(true);
    ui->tableWidgetOptions->horizontalHeader()->setDefaultSectionSize(60);
    ui->tableWidgetOptions->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetOptions->verticalHeader()->setVisible(false);
    ui->tableWidgetOptions->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des employes (Personnel Garage)
    ui->tableWidgetEmployes->setColumnCount(4);
    ui->tableWidgetEmployes->setRowCount(0);
    QStringList labelsTableEmployes;
    labelsTableEmployes << "Numéro" << "Nom" << "Prénom" << "Fonction";
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(labelsTableEmployes);
    ui->tableWidgetEmployes->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetEmployes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEmployes->horizontalHeader()->setVisible(true);
    ui->tableWidgetEmployes->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetEmployes->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetEmployes->verticalHeader()->setVisible(false);
    ui->tableWidgetEmployes->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des clients
    ui->tableWidgetClients->setColumnCount(4);
    ui->tableWidgetClients->setRowCount(0);
    QStringList labelsTableClients;
    labelsTableClients << "Numéro" << "Nom" << "Prénom" << "GSM";
    ui->tableWidgetClients->setHorizontalHeaderLabels(labelsTableClients);
    ui->tableWidgetClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetClients->horizontalHeader()->setVisible(true);
    ui->tableWidgetClients->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetClients->verticalHeader()->setVisible(false);
    ui->tableWidgetClients->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des contrats
    ui->tableWidgetContrats->setColumnCount(4);
    ui->tableWidgetContrats->setRowCount(0);
    QStringList labelsTableContrats;
    labelsTableContrats << "Numéro" << "Vendeur" << "Client" << "Voiture";
    ui->tableWidgetContrats->setHorizontalHeaderLabels(labelsTableContrats);
    ui->tableWidgetContrats->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetContrats->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetContrats->horizontalHeader()->setVisible(true);
    ui->tableWidgetContrats->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetContrats->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetContrats->verticalHeader()->setVisible(false);
    ui->tableWidgetContrats->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    setRole(0);

    // Importation des modeles (étape 10)
    Garage::getInstance().importeModeles("../FichiersCSV/Modeles.csv");
    Garage::getInstance().importeOptions("../FichiersCSV/Options.csv");
    Modele m;
    Option o;
    for(int i = 0; i < Garage::getInstance().nbModeles(); i++)
    {
        m = (Garage::getInstance().getModele(i));
        ajouteModeleDisponible(m.getNom(), m.getPrixDeBase());
    }

    // Importation des options (étape 10)
    for(int i = 0; i < Garage::getInstance().nbOptions(); i++)
    {
        o = (Garage::getInstance().getOption(i));
        ajouteOptionDisponible(o.getIntitule().c_str(), o.getPrix());
    }

    // Ouverture (et/ou creation) du fichier Garage.data (étape 12)
    // TO DO
    ifstream fichier("Garage.data",ios::in | ios::binary);

    if(fichier.is_open())
    {
        Garage::getInstance().Load(fichier);
        fichier.close();
    }

    majTableEmployes();
    majTableClients();
}

ApplicGarageWindow::~ApplicGarageWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Titre de la fenêtre (ne pas modifier) //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setTitre(string titre)
{
    this->setWindowTitle(titre.c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Gestion des roles (ne pas modifier) ////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setRole(int val)
{
    // val = 0 --> personne n'est loggé
    // val = 1 --> un administratif est loggé
    // val = 2 --> un vendeur loggé
    // val = 3 --> on a accès à tout

    if (val == 0)
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(false);
        ui->actionReset_Mot_de_passe->setEnabled(false);
        ui->menuEmployes->setEnabled(false);
        ui->menuClients->setEnabled(false);
        ui->menuVoiture->setEnabled(false);
        ui->comboBoxModelesDisponibles->setEnabled(false);
        ui->comboBoxOptionsDisponibles->setEnabled(false);
        ui->pushButtonOuvrirProjet->setEnabled(false);
        ui->pushButtonNouveauProjet->setEnabled(false);
        ui->pushButtonReduction->setEnabled(false);
        ui->pushButtonEnregistrerProjet->setEnabled(false);
        ui->pushButtonAjouterOption->setEnabled(false);
        ui->pushButtonSupprimerOption->setEnabled(false);
        ui->pushButtonChoisirModele->setEnabled(false);
        ui->pushButtonVisualiserVoiture->setEnabled(false);
        ui->pushButtonNouveauContrat->setEnabled(false);
        ui->pushButtonSupprimerContrat->setEnabled(false);
    }

    if (val == 1)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionReset_Mot_de_passe->setEnabled(true);
        ui->menuEmployes->setEnabled(true);
        ui->menuClients->setEnabled(false);
        ui->menuVoiture->setEnabled(false);
        ui->comboBoxModelesDisponibles->setEnabled(false);
        ui->comboBoxOptionsDisponibles->setEnabled(false);
        ui->pushButtonOuvrirProjet->setEnabled(false);
        ui->pushButtonNouveauProjet->setEnabled(false);
        ui->pushButtonReduction->setEnabled(false);
        ui->pushButtonEnregistrerProjet->setEnabled(false);
        ui->pushButtonAjouterOption->setEnabled(false);
        ui->pushButtonSupprimerOption->setEnabled(false);
        ui->pushButtonChoisirModele->setEnabled(false);
        ui->pushButtonVisualiserVoiture->setEnabled(true);
        ui->pushButtonNouveauContrat->setEnabled(false);
        ui->pushButtonSupprimerContrat->setEnabled(true);
    }

    if (val == 2)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionReset_Mot_de_passe->setEnabled(true);
        ui->menuEmployes->setEnabled(false);
        ui->menuClients->setEnabled(true);
        ui->menuVoiture->setEnabled(true);
        ui->comboBoxModelesDisponibles->setEnabled(true);
        ui->comboBoxOptionsDisponibles->setEnabled(true);
        ui->pushButtonOuvrirProjet->setEnabled(true);
        ui->pushButtonNouveauProjet->setEnabled(true);
        ui->pushButtonReduction->setEnabled(true);
        ui->pushButtonEnregistrerProjet->setEnabled(true);
        ui->pushButtonAjouterOption->setEnabled(true);
        ui->pushButtonSupprimerOption->setEnabled(true);
        ui->pushButtonChoisirModele->setEnabled(true);
        ui->pushButtonVisualiserVoiture->setEnabled(true);
        ui->pushButtonNouveauContrat->setEnabled(true);
        ui->pushButtonSupprimerContrat->setEnabled(true);
    }

    if (val == 3)
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(true);
        ui->actionReset_Mot_de_passe->setEnabled(true);
        ui->menuEmployes->setEnabled(true);
        ui->menuClients->setEnabled(true);
        ui->menuVoiture->setEnabled(true);
        ui->comboBoxModelesDisponibles->setEnabled(true);
        ui->comboBoxOptionsDisponibles->setEnabled(true);
        ui->pushButtonOuvrirProjet->setEnabled(true);
        ui->pushButtonNouveauProjet->setEnabled(true);
        ui->pushButtonReduction->setEnabled(true);
        ui->pushButtonEnregistrerProjet->setEnabled(true);
        ui->pushButtonAjouterOption->setEnabled(true);
        ui->pushButtonSupprimerOption->setEnabled(true);
        ui->pushButtonChoisirModele->setEnabled(true);
        ui->pushButtonVisualiserVoiture->setEnabled(true);
        ui->pushButtonNouveauContrat->setEnabled(true);
        ui->pushButtonSupprimerContrat->setEnabled(true);
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Table des options du projet en cours (ne pas modifier) /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setTableOption(int indice,string code,string intitule,float prix)
{
    // Modifie l'option de la ligne correspondant à l'indice fourni dans la table des options de l'interface graphique
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(code.c_str());
    ui->tableWidgetOptions->setItem(indice,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    char tmp[20];
    sprintf(tmp,"%.2f",prix);
    if (prix < 0.0) item->setText("");
    else item->setText(tmp);
    ui->tableWidgetOptions->setItem(indice,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(intitule.c_str());
    ui->tableWidgetOptions->setItem(indice,2,item);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableOption()
{
    for (int i=0 ; i<5 ; i++) setTableOption(i);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceOptionSelectionneeTable() const
{
    // retourne l'indice de l'option selectionnee dans la table des options
    QModelIndexList liste = ui->tableWidgetOptions->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combobox des modèles disponibles (ne pas modifier) /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteModeleDisponible(const char* nom,float prixDeBase)
{
    // ajoute un modèle dans le combobox correspondant (juste le nom et le prix)
    stringstream ss;
    char temp[20];
    sprintf(temp,"%.2f",prixDeBase);
    ss << nom << " (" << temp << ")";
    ui->comboBoxModelesDisponibles->addItem(ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videComboboxModelesDisponibles()
{
    ui->comboBoxModelesDisponibles->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceModeleSelectionneCombobox() const
{
    // retourne l'indice du modèle selectionné dans le combobox des modèles
    return ui->comboBoxModelesDisponibles->currentIndex();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combox des options disponibles (ne pas modifier) ///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteOptionDisponible(string intitule,float prix)
{
    // ajoute une option dans le combobox correspondant
    stringstream ss;
    char temp[20];
    sprintf(temp,"%.2f",prix);
    ss << intitule << " (" << temp << ")";
    ui->comboBoxOptionsDisponibles->addItem(ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videComboboxOptionsDisponibles()
{
    ui->comboBoxOptionsDisponibles->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceOptionSelectionneeCombobox() const
{
    // retourne l'indice de l'option selectionnée dans le combobox des options
    return ui->comboBoxOptionsDisponibles->currentIndex();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Gestion du Projet en cours (ne pas modifier) ///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setNomProjetEnCours(string nom)
{
    // Remplit le champ nom de l'interface graphique avec le nom reçu
    ui->lineEditNomProjet->setText(nom.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicGarageWindow::getNomProjetEnCours() const
{
    return ui->lineEditNomProjet->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setModele(string nom,int puissance,int moteur,float prixDeBase,string imageModele)
{
    // Remplit les champs correspondants dans l'interface graphique
    // pour le moteur (int) : 0=Essence, 1=Diesel, 2=Electrique, 3=Hybride
    ui->lineEditNomModele->setText(nom.c_str());
    ui->lineEditPuissance->setText(to_string(puissance).c_str());
    char tmp[20];
    sprintf(tmp,"%.2f",prixDeBase);
    ui->lineEditPrixDeBase->setText(tmp);

    ui->radioButtonEssence->setChecked(false);
    ui->radioButtonDiesel->setChecked(false);
    ui->radioButtonElectrique->setChecked(false);
    ui->radioButtonHybride->setChecked(false);

    if (moteur == 0) ui->radioButtonEssence->setChecked(true);
    if (moteur == 1) ui->radioButtonDiesel->setChecked(true);
    if (moteur == 2) ui->radioButtonElectrique->setChecked(true);
    if (moteur == 3) ui->radioButtonHybride->setChecked(true);

    // Met à jour l'image du modèle
    string cheminComplet = REPERTOIRE_IMAGES + imageModele;
    QLabel* label = new QLabel();
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    label->setScaledContents(true);
    QPixmap *pixmap_img = new QPixmap(cheminComplet.c_str());
    label->setPixmap(*pixmap_img);
    label->resize(label->pixmap()->size());
    ui->scrollArea->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setPrix(float prix)
{
  char tmp[20];
  sprintf(tmp,"%.2f",prix);
  ui->lineEditPrix->setText(tmp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Employes (ne pas modifier) //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteTupleTableEmployes(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char numero[20];
    strcpy(numero,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char nom[40];
    strcpy(nom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char prenom[40];
    strcpy(prenom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char fonction[40];
    strcpy(fonction,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetEmployes->rowCount();
    nbLignes++;
    ui->tableWidgetEmployes->setRowCount(nbLignes);
    ui->tableWidgetEmployes->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(numero);
    ui->tableWidgetEmployes->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(nom);
    ui->tableWidgetEmployes->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(prenom);
    ui->tableWidgetEmployes->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(fonction);
    ui->tableWidgetEmployes->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableEmployes()
{
    ui->tableWidgetEmployes->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceEmployeSelectionne()
{
    QModelIndexList liste = ui->tableWidgetEmployes->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Clients (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteTupleTableClients(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char numero[20];
    strcpy(numero,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char nom[40];
    strcpy(nom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char prenom[40];
    strcpy(prenom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char gsm[40];
    strcpy(gsm,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetClients->rowCount();
    nbLignes++;
    ui->tableWidgetClients->setRowCount(nbLignes);
    ui->tableWidgetClients->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(numero);
    ui->tableWidgetClients->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(nom);
    ui->tableWidgetClients->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(prenom);
    ui->tableWidgetClients->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(gsm);
    ui->tableWidgetClients->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableClients()
{
    ui->tableWidgetClients->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceClientSelectionne()
{
    QModelIndexList liste = ui->tableWidgetClients->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Contrats (ne pas modifier) //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteTupleTableContrats(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char numero[20];
    strcpy(numero,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char vendeur[40];
    strcpy(vendeur,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char client[40];
    strcpy(client,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char voiture[40];
    strcpy(voiture,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetContrats->rowCount();
    nbLignes++;
    ui->tableWidgetContrats->setRowCount(nbLignes);
    ui->tableWidgetContrats->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(numero);
    ui->tableWidgetContrats->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(vendeur);
    ui->tableWidgetContrats->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(client);
    ui->tableWidgetContrats->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(voiture);
    ui->tableWidgetContrats->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableContrats()
{
    ui->tableWidgetContrats->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceContratSelectionne()
{
    QModelIndexList liste = ui->tableWidgetContrats->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::dialogueMessage(const char* titre,const char* message)
{
   QMessageBox::information(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::dialogueErreur(const char* titre,const char* message)
{
   QMessageBox::critical(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicGarageWindow::dialogueDemandeTexte(const char* titre,const char* question)
{
    QString chaine = QInputDialog::getText(this,titre,question);
    return chaine.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::dialogueDemandeInt(const char* titre,const char* question)
{
    return QInputDialog::getInt(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
float ApplicGarageWindow::dialogueDemandeFloat(const char* titre,const char* question)
{
    return QInputDialog::getDouble(this,titre,question);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionQuitter_triggered()
{
  // TO DO (étape 12)

    ofstream fichier("Garage.data", ios::out | ios::trunc | ios::binary);

    if(fichier.is_open())
    {
        Garage::getInstance().Save(fichier);
        fichier.close();
    }
  QApplication::exit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::closeEvent(QCloseEvent *event)
{
  if (event == NULL) {}  // pour éviter le warning
  // TO DO (étape 12)

    ofstream fichier("Garage.data", ios::out | ios::trunc | ios::binary);

    if(fichier.is_open())
    {
        Garage::getInstance().Save(fichier);
        fichier.close();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionNouveau_modele_triggered()
{
  // Saisie des informations (aucune vérification n'est faite --> à gérer si vous voulez)
  string nomModele = dialogueDemandeTexte("Nouveau modèle","Nom :");
  int puissance = dialogueDemandeInt("Nouveau modèle","Puissance :");
  int moteur = dialogueDemandeInt("Nouveau modèle :","Moteur (0=essence,1=diesel,2=électrique,3=hybride) :");
  float prixDeBase = dialogueDemandeFloat("Nouveau modèle","Prix de base :");
  string image = dialogueDemandeTexte("Nouveau modèle","Nom du fichier de l'image :");

  // TO DO (étape 9)
  Garage::getInstance().ajouteModele(Modele(nomModele.c_str(), puissance, (enum Moteur)moteur, prixDeBase, image));
  ajouteModeleDisponible(nomModele.c_str(), prixDeBase);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionNouvelle_option_triggered()
{
  // Saisie des informations (aucune vérification n'est faite --> à gérer si vous voulez)
  string code = dialogueDemandeTexte("Nouvelle option","Code :");
  string intitule = dialogueDemandeTexte("Nouvelle option","Intitule :");
  float prix = dialogueDemandeFloat("Nouvelle option","Prix :");

  // TO DO (étape 9)
  try
  {
      Garage::getInstance().ajouteOption(Option(code, intitule, prix));
      ajouteOptionDisponible(intitule.c_str(), prix);
  }
  catch(OptionException &o)
  {
    dialogueErreur("OptionException !", o.getMessage().c_str());
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionAjouterEmploye_triggered()
{
  // TO DO (étape 11)
    string nom = dialogueDemandeTexte("Nouvel employé", "Nom : ");
    string prenom = dialogueDemandeTexte("Nouvel employé", "Prénom : ");
    bool faux = 0;
    int fonctionInt;
    string fonctionString;
    do
    {
        if(faux)
            dialogueErreur("Erreur d'encodage !", "Veuillez saisir 1 ou 2 !");
        fonctionInt = dialogueDemandeInt("Nouvel employé", "Fonction\n(1) -> Vendeur\n(2) -> Administratif : ");
        faux = 1;
    }while(fonctionInt != 1 && fonctionInt != 2);

    string login = dialogueDemandeTexte("Nouvel employé", "Login :");

    if(fonctionInt == 1)
    {
        fonctionString = Employe::VENDEUR;
    }
    else
        fonctionString = Employe::ADMINISTRATIF;
    Garage::getInstance().ajouteEmploye(nom, prenom, login, fonctionString);
    majTableEmployes();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerEmploye_par_numero_triggered()
{
  // TO DO (étape 11)
    int num, faux = 0;
    do
    {
        if(faux)
            dialogueErreur("Erreur", "Veuillez choisir un numéro positif");
        num = dialogueDemandeInt("Suppression d'un employé", "Donnez le numéro de l'employé");
        faux = 1;
    }while(num < 0);

    Garage::getInstance().supprimeEmployeParNumero(num);
    majTableEmployes();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerEmploye_selection_triggered()
{
  // TO DO (étape 11)
    int indice = getIndiceEmployeSelectionne();
    if(indice == -1)
        dialogueErreur("Erreur de sélection", "Aucun employé sélectionné");
    else
    {
        Garage::getInstance().supprimeEmployeParIndice(indice);
        majTableEmployes();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionAjouterClient_triggered()
{
  // TO DO (étape 11)
    bool faux = 0;
    string nom = dialogueDemandeTexte("Nouveau client", "Nom : ");
    string prenom = dialogueDemandeTexte("Nouveau client", "Prénom : ");
    string gsm;
    do
    {
        if(faux)
            dialogueErreur("Erreur", "Entrez un numéro de gsm valide !");
        gsm = dialogueDemandeTexte("Nouveau client", "Gsm : ");
        faux = 1;
    }while(gsm.size() != 10);
    

    Garage::getInstance().ajouteClient(nom, prenom, gsm);
    majTableClients();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerClient_par_numero_triggered()
{
  // TO DO (étape 11)
    int num, faux = 0;
    do
    {
        if(faux)
            dialogueErreur("Erreur", "Veuillez choisir un numéro positif");
        num = dialogueDemandeInt("Suppression d'un client", "Donnez le numéro du client");
        faux = 1;
    }while(num < 0);

    Garage::getInstance().supprimeClientParNumero(num);
    majTableClients();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerClient_selection_triggered()
{
  // TO DO (étape 11)
    int indice = getIndiceClientSelectionne();
    if(indice == -1)
        dialogueErreur("Erreur de sélection", "Aucun client sélectionné");
    else
    {
        Garage::getInstance().supprimeClientParIndice(indice);
        majTableClients();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionLogin_triggered()
{
  // TO DO (étape 11)
    string login = dialogueDemandeTexte("Connexion", "Login :");
    string mdp, mdpVerif;
    int i;
    Iterateur<Employe> it(Garage::getInstance().getEmployes());
    for(it.reset(), i = 0; !it.end() && login != ((Employe)it).getLogin(); it++, i++);
    if(!it.end())
    {
        Garage::employeLogged = new Employe(Garage::getInstance().getEmployes()[i]);
        try
        {
            mdp = Garage::getInstance().getEmployes()[i].getMotDePasse();

            mdpVerif = dialogueDemandeTexte("Authentification", "Mot de passe :");
            if(mdp == mdpVerif)
            {
                setTitre("Application Garage - " + Garage::getInstance().getEmployes()[i].getNom() + " " + Garage::getInstance().getEmployes()[i].getPrenom());
                if(Garage::getInstance().getEmployes()[i].getFonction() == Employe::VENDEUR)
                    setRole(2);
                else if(Garage::getInstance().getEmployes()[i].getFonction() == Employe::ADMINISTRATIF)
                    setRole(1);
            }
            else
                dialogueErreur("Connexion échouée", "Mot de passe incorrect !");
        }
        catch(...)
        {
            dialogueMessage("Mot de passe non défini", "Veuillez choisir un mot de passe");
            try
            {
                mdp = dialogueDemandeTexte("Choix du mot de passe", "Mot de passe :");
                Garage::getInstance().getEmployes()[i].setMotDePasse(mdp);
                setTitre("Application Garage - " + Garage::getInstance().getEmployes()[i].getNom() + " " + Garage::getInstance().getEmployes()[i].getPrenom());
                if(Garage::getInstance().getEmployes()[i].getFonction() == Employe::VENDEUR)
                    setRole(2);
                else if(Garage::getInstance().getEmployes()[i].getFonction() == Employe::ADMINISTRATIF)
                    setRole(1);
            }
            catch(PasswordException& p)
            {
                dialogueErreur("Mot de passe non valide !", p.getMessage().c_str());
            }
        }
    }
    else
        dialogueErreur("Connexion", "Login non valide !");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionLogout_triggered()
{
  // TO DO (étape 11)
    delete Garage::employeLogged;
    Garage::employeLogged = NULL;
    setTitre("");
    setRole(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionReset_Mot_de_passe_triggered()
{
  // TO DO (étape 11)
    Iterateur<Employe> it(Garage::getInstance().getEmployes());
    int i;
    for(it.reset(), i = 0; !it.end() && ((Employe)it).getNumero() != Garage::employeLogged->getNumero(); it++, i++);

    Garage::getInstance().getEmployes()[i].resetMotDePasse();
    dialogueMessage("Mot de passe réinitialisé", "Votre mot de passe a été réinitialisé");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonChoisirModele_clicked()
{
  // TO DO (étape 9)
    if(getIndiceModeleSelectionneCombobox() == -1)
        dialogueErreur("Modele !", "Pas de modele selectionne !");
    else
    {
        Modele m(Garage::getInstance().getModele(getIndiceModeleSelectionneCombobox()));
        Garage::getInstance().getProjetEnCours().setModele(m);
        setModele(m.getNom(), m.getPuissance(), m.getMoteur(), m.getPrixDeBase(), m.getImage());
        afficheOptionsEnCours();
        setPrix(Garage::getInstance().getProjetEnCours().getPrix());
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonAjouterOption_clicked()
{
  // TO DO (étape 9)
    try
    {
        if(getIndiceOptionSelectionneeCombobox() == -1)
        {
            dialogueErreur("Option !", "Aucune option sélectionée");
        }
        else if(getIndiceModeleSelectionneCombobox() == -1)
        {
            dialogueErreur("Modèle !", "Aucun modèle sélectionné");
        }
        else
        {
            Option op = Garage::getInstance().getOption(getIndiceOptionSelectionneeCombobox());
            Garage::getInstance().getProjetEnCours().AjouteOption(op);
            afficheOptionsEnCours();   
            setPrix(Garage::getInstance().getProjetEnCours().getPrix());
        }
    }
    catch(OptionException &o)
    {
        dialogueErreur("Option !", o.getMessage().c_str());
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonSupprimerOption_clicked()
{
  // TO DO (étape 9)

    if(getIndiceOptionSelectionneeTable() == -1)
        dialogueErreur("Option !", "Aucune option sélectionnée");
    else
    {
        try
        {
            if(Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()] != NULL)
            {
                Garage::getInstance().getProjetEnCours().RetireOption(Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()]->getCode());
                setTableOption(getIndiceOptionSelectionneeTable(), "", "", -1);
                setPrix(Garage::getInstance().getProjetEnCours().getPrix());
            }
            else
                dialogueErreur("Option", "Veuillez supprimer une option valide");
        }
        catch(OptionException &o)
        {
            dialogueErreur("Option !", o.getMessage().c_str());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonReduction_clicked()
{
  // TO DO (étape 9)

    if(getIndiceOptionSelectionneeTable() == -1)
        dialogueErreur("Option !", "Aucune option sélectionnée");
    else
    {
        try
        {
            if(Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()] != NULL)
            {
                (*Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()])--;
                setTableOption(getIndiceOptionSelectionneeTable(), Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()]->getCode(), Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()]->getIntitule(), Garage::getInstance().getProjetEnCours()[getIndiceOptionSelectionneeTable()]->getPrix());
                setPrix(Garage::getInstance().getProjetEnCours().getPrix());
            }
            else
                dialogueErreur("Option !", "Veuillez choisir une option valide à réduire");

        }
        catch(OptionException &o)
        {
            dialogueErreur("Option !", o.getMessage().c_str());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonEnregistrerProjet_clicked()
{
  // TO DO (étape 9)
    if(getNomProjetEnCours() != "")
    {
        string NomProjet = getNomProjetEnCours();
        Garage::getInstance().getProjetEnCours().setNom(NomProjet);
        Garage::getInstance().getProjetEnCours().Save();
    }
    else
        dialogueErreur("Nom Projet !", "Veuillez donner un nom au projet à enregistrer");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonOuvrirProjet_clicked()
{
  // TO DO (étape 9)
    if(getNomProjetEnCours() != "")
    {
        Garage::getInstance().resetProjetEnCours();
        Garage::getInstance().getProjetEnCours().Load("Projets/" + getNomProjetEnCours() + ".car");
        
        Modele m(Garage::getInstance().getProjetEnCours().getModele());
        setModele(m.getNom(), m.getPuissance(), m.getMoteur(), m.getPrixDeBase(), m.getImage());
        afficheOptionsEnCours();
    }
    else
        dialogueErreur("Nom Projet !", "Veuillez donner un nom au projet à ouvrir");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonNouveauProjet_clicked()
{
  // TO DO (étape 9)
       Garage::getInstance().resetProjetEnCours();
    afficheOptionsEnCours();
    Modele m(Garage::getInstance().getProjetEnCours().getModele());
    setModele(m.getNom(), m.getPuissance(), m.getMoteur(), m.getPrixDeBase(), m.getImage());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonNouveauContrat_clicked()
{
  // TO DO (étape 13)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonSupprimerContrat_clicked()
{
  // TO DO (étape 13)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonVisualiserVoiture_clicked()
{
  // TO DO (étape 13)

}

void ApplicGarageWindow::afficheOptionsEnCours()
{
    for(int i = 0; i < NBR_OPTIONS; i++)
    {
        if(Garage::getInstance().getProjetEnCours()[i] != NULL)
            setTableOption(i, Garage::getInstance().getProjetEnCours()[i]->getCode(), Garage::getInstance().getProjetEnCours()[i]->getIntitule(), Garage::getInstance().getProjetEnCours()[i]->getPrix());
        else
            setTableOption(i, "", "", -1);
    }
}

void ApplicGarageWindow::majTableEmployes()
{
    videTableEmployes();
    Iterateur<Employe> it(Garage::getInstance().getEmployes());
    for(it.reset(); !it.end(); it++)
    {
       ajouteTupleTableEmployes(((Employe)it).Tuple());
    }
}

void ApplicGarageWindow::majTableClients()
{
    videTableClients();
    Iterateur<Client> it(Garage::getInstance().getClients());
    for(it.reset(); !it.end(); it++)
    {
        ajouteTupleTableClients(((Client)it).Tuple());
    }
}