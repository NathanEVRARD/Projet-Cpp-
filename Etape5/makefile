.SILENT:


Test5:	Classes/Modele.o Classes/Voiture.o Classes/Option.o Classes/Personne.o Classes/Intervenant.o Classes/Client.o Classes/Employe.o Classes/Exception.o Classes/OptionException.o Classes/PasswordException.o Test5.cpp
	g++ Test5.cpp -D DEBUG Classes/Modele.o Classes/Voiture.o Classes/Option.o Classes/Personne.o Classes/Intervenant.o Classes/Client.o Classes/Employe.o Classes/Exception.o Classes/OptionException.o Classes/PasswordException.o -o Test5

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
	rm Classes/*.o Test5
