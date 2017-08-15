test: main.o
	g++ -g main.o -o test
main.o: main.cpp SelectSort.h SortTestHelper.h Sort.h
	g++ -g -c main.cpp -o main.o

.PHONY:
clean:
	rm -f *.o test

