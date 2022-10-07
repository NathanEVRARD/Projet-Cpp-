.SILENT:

Test2a:	Classes/modele.o Classes/voiture.o Test2a.cpp
	g++ Test2a.cpp Classes/modele.o Classes/voiture.o -o Test2a -D DEBUG 

Classes/voiture.o:	Classes/voiture.cpp Classes/voiture.h
	g++ -c Classes/voiture.cpp -o Classes/voiture.o

Classes/modele.o:	Classes/modele.cpp Classes/modele.h
	g++ -c Classes/modele.cpp -o Classes/modele.o

clean:
	rm Classes/*.o Test2a
