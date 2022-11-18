#include "Exception.h"

//---------------  CONSTRUCTEURS  --------------------------

Exception::Exception()
{
	#ifdef DEBUG
	  cout << "Constructeur par defaut ! (Exception)" << endl << endl;
	#endif

	setMessage("message d'erreur");
}

Exception::Exception(string m)
{
	#ifdef DEBUG
	  cout << "Constructeur d'initialisation ! (Exception)" << endl << endl;
	#endif

	setMessage(m);
}

Exception::Exception(Exception& e)
{
	#ifdef DEBUG
	  cout << "Constructeur de copie ! (Exception)" << endl << endl;
	#endif

	setMessage(e.getMessage());
}

//---------------  DESTRUCTEUR   ---------------------------

Exception::~Exception()
{
	#ifdef DEBUG
	  cout << "Destructeur ! (Exception)" << endl << endl;
	#endif
}

//--------------  SETTERS ET GETTERS  ----------------------

void Exception::setMessage(string m)
{
	message = m;
}

string Exception::getMessage() const
{
	return message;
}