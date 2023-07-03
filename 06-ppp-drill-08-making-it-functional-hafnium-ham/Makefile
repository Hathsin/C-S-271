use: use.o my.o
	g++ -std=c++11 -o use use.o my.o

use.o:
	g++ -std=c++11 -c -o use.o use.cpp

my.o:
	g++ -std=c++11 -c -o my.o my.cpp

clean:
	rm -f use
	rm -f *.o