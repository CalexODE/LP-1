soma.:o soma.cpp soma.h
	g++ soma.cpp -c

sub.o: sub.cpp sub.h
	g++ sub.cpp -c

mult.o: mult.cpp mult.h
	g++ mult.cpp -c

div.o: div.cpp div.h
	g++ div.cpp -c

menu.o: menu.cpp menu.h soma.o sub.o mult.o div.o
	g++ menu.cpp soma.o sub.o mult.o div.o -c

calculadora: menu.o calculadora.cpp
	g++ calculadora.cpp menu.o -o calculadora


clear:
	rm *.o