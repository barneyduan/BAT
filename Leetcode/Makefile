test: main.o
	g++ -g main.o -o test
main.o: main.cpp Container_with_most_water.h
	g++ -g -c main.cpp -o main.o

.PHONY:
clean:
	rm -f *.o test