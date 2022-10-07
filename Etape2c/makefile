.SILENT:

Test2c:	Classes/modele.o Classes/voiture.o Classes/option.o Test2c.cpp
	g++ Test2c.cpp Classes/modele.o Classes/voiture.o Classes/option.o -o Test2c -D DEBUG 

Classes/option.o:	Classes/option.cpp Classes/option.h
	g++ -c Classes/option.cpp -o Classes/option.o

Classes/voiture.o:	Classes/voiture.cpp Classes/voiture.h
	g++ -c Classes/voiture.cpp -o Classes/voiture.o

Classes/modele.o:	Classes/modele.cpp Classes/modele.h
	g++ -c Classes/modele.cpp -o Classes/modele.o

clean:
	rm Classes/*.o Test2c
