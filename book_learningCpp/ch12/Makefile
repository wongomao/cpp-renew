main: main15.o
	g++ -o main.exe main15.o -std=c++2a
main15.o: main15.cpp
	g++ -c main15.cpp -std=c++2a
all: main15.o
	g++ -o main.exe main15.o -std=c++2a
clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe