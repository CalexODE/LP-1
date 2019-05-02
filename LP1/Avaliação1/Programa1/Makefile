func.o:funcionario.cpp funcionario.h
	g++ funcionario.cpp -c

emp.o:empresa.cpp empresa.h
	g++ empresa.cpp -c

menu.o:menu.cpp menu.hpp
	g++ menu.cpp -c

main: main.cpp funcionario.o empresa.o menu.o
	g++ main.cpp funcionario.o empresa.o menu.o -o main

clear:
	rm *.o
	rm main
