.SILENT:

CO=g++
OBJS_QT = main.o applicgaragewindow.o moc_applicgaragewindow.o
PROGRAMS = ApplicGarage
OBJS = Classes/Modele.o Classes/Voiture.o Classes/Option.o Classes/Personne.o Classes/Intervenant.o Classes/Client.o Classes/Employe.o Classes/Exception.o Classes/OptionException.o Classes/PasswordException.o Classes/Vecteur.o Classes/Iterateur.o Classes/VecteurTrie.o Classes/Garage.o

all:	$(PROGRAMS)

ApplicGarage:	$(OBJS_QT) $(OBJS)
		echo Creation de ApplicGarage...
		$(CO) -Wl,-O1 -o ApplicGarage $(OBJS_QT) $(OBJS) /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread 					
		#rm main.o

main.o:	main.cpp 
		echo Creation de main.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o main.o main.cpp

applicgaragewindow.o:	applicgaragewindow.cpp applicgaragewindow.h ui_applicgaragewindow.h
		echo Creation de applicgaragewindow.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o applicgaragewindow.o applicgaragewindow.cpp

moc_applicgaragewindow.o:	moc_applicgaragewindow.cpp applicgaragewindow.h
		echo Creation de moc_applicgaragewindow.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o moc_applicgaragewindow.o moc_applicgaragewindow.cpp

Classes/Garage.o:	Classes/Garage.cpp Classes/Garage.h
	g++ -c Classes/Garage.cpp -o Classes/Garage.o

Classes/VecteurTrie.o:	Classes/VecteurTrie.cpp Classes/VecteurTrie.h
	g++ -c Classes/VecteurTrie.cpp -o Classes/VecteurTrie.o

Classes/Iterateur.o:	Classes/Iterateur.cpp Classes/Iterateur.h
	g++ -c Classes/Iterateur.cpp -o Classes/Iterateur.o

Classes/Vecteur.o:	Classes/Vecteur.cpp Classes/Vecteur.h
	g++ -c Classes/Vecteur.cpp -o Classes/Vecteur.o

Classes/PasswordException.o:	Classes/PasswordException.cpp Classes/PasswordException.h
	g++ -c Classes/PasswordException.cpp -o Classes/PasswordException.o

Classes/OptionException.o:	Classes/OptionException.cpp Classes/OptionException.h
	g++ -c Classes/OptionException.cpp -o Classes/OptionException.o

Classes/Exception.o:	Classes/Exception.cpp Classes/Exception.h
	g++ -c Classes/Exception.cpp -o Classes/Exception.o

Classes/Employe.o:	Classes/Employe.cpp Classes/Employe.h
	g++ -c Classes/Employe.cpp -o Classes/Employe.o

Classes/Client.o:	Classes/Client.cpp Classes/Client.h
	g++ -c Classes/Client.cpp -o Classes/Client.o

Classes/Intervenant.o:	Classes/Intervenant.cpp Classes/Intervenant.h
	g++ -c Classes/Intervenant.cpp -o Classes/Intervenant.o

Classes/Personne.o:	Classes/Personne.cpp Classes/Personne.h
	g++ -c Classes/Personne.cpp -o Classes/Personne.o

Classes/Option.o:	Classes/Option.cpp Classes/Option.h
	g++ -c Classes/Option.cpp -o Classes/Option.o

Classes/Voiture.o:	Classes/Voiture.cpp Classes/Voiture.h
	g++ -c Classes/Voiture.cpp -o Classes/Voiture.o 

Classes/Modele.o:	Classes/Modele.cpp Classes/Modele.h
	g++ -c Classes/Modele.cpp -o Classes/Modele.o 

clean:
	echo "Suppression des .o"
	@rm -f $(OBJS_QT) core
	rm Classes/*.o

clobber:	clean
	@rm -f tags $(PROGRAMS) *~ *.log
