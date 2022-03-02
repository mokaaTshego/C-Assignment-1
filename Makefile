# This is a Makefile comment
CC=g++
# the compiler

LIBS=-lm -lX
# the libraries we will ref

assignment1driver.exe: assignment1driver.o assignment1.o
	g++ assignment1driver.o assignment1.o -o assignment1driver.exe -std=c++2a

assignment1driver.o: assignment1driver.cpp
	g++ -c assignment1driver.cpp -o assignment1driver.o -std=c++2a

assignment1.o: assignment1.cpp assignment1.h
	g++ -c assignment1.cpp -o assignment1.o -std=c++2a


run:
	./assignment1driver.exe

clean:
	@rm -f *.o
	@rm assignment1driver.exe
