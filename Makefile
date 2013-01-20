CFLAGS= -Wall -c

all: proj3

proj3: main.o skip_list.o rectangle.o
	g++ main.o skip_list.o rectangle.o -o proj3
main.o: main.cpp
	g++ $(CFLAGS) main.cpp
skip_list.o: skip_list.cpp
	g++ $(CFLAGS) skip_list.cpp
rectangle.o: rectangle.cpp
	g++ $(CFLAGS) rectangle.cpp
clean:
	rm -rf rectangle.o skip_list.o  main.o
