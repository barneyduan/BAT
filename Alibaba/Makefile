test: main.o
	g++ -std=c++11 -g main.o -o test
main.o: main.cpp Rabbit.h
	g++ -std=c++11 -g -c main.cpp -o main.o

.PHONY:
clean:
	rm -f *.o test