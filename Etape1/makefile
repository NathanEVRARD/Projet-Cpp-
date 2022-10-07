.SILENT:

Test1:	Test1.cpp Classes/modele.o
	echo "Creation de Test1"
	g++ Test1.cpp Classes/modele.o -o Test1 -I Classes/ #-D DEBUG

Classes/modele.o:	Classes/modele.cpp Classes/modele.h
	echo "Creation de Modele.o"
	g++  Classes/modele.cpp -c -o Classes/modele.o

clean:
	rm Classes/*.o Test1
