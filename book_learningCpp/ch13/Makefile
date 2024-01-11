main: main12.o
	g++ -o main.exe main12.o -std=c++2a
main12.o: main12.cpp
	g++ -c main12.cpp -std=c++2a
all: main12.o
	g++ -o main.exe main12.o -std=c++2a
clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe