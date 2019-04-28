func.o:funcionario.cpp funcionario.h
	g++ funcionario.cpp -c

emp.o:empresa.cpp empresa.h funcionario.o
	g++ empresa.cpp funcionario.o -c

main: main.cpp funcionario.o empresa.o
	g++ main.cpp funcionario.o empresa.o -o main

clear:
	rm *.o
	rm main
