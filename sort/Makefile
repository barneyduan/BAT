test: main.o SelectSort.o
	g++ -g main.o SelectSort.o -o test
main.o: main.cpp SelectSort.h
	g++ -g -c main.cpp -o main.o
clean:
	rm -f *.o test

