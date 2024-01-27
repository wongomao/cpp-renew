main: main16.o
	g++ -o main.exe main16.o -std=c++2b
main16.o: main16.cpp
	g++ -c main16.cpp -std=c++2b
all: main16.o
	g++ -o main.exe main16.o -std=c++2b
clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe