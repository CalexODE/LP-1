
CLP = classePrint

classePrint.o: $(CLP).h $(CLP).cpp
	g++ $(CLP).cpp -c

main: $(CLP).o main.cpp
	g++ main.cpp $(CLP).o -o main

clear:
	rm *.o
	rm main

