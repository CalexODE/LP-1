func.o:funcionario.cpp funcionario.h
	g++ funcionario.cpp -c

emp.o:empresa.cpp empresa.h
	g++ empresa.cpp -c

main: main.cpp funcionario.o empresa.o
	g++ main.cpp funcionario.o empresa.o -o main

clear:
	rm *.o
	rm main
