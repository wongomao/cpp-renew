main: main10.o
	g++ -o main.exe main10.o -std=c++2a
main10.o: main10.cpp
	g++ -c main10.cpp -std=c++2a
all: main10.o
	g++ -o main.exe main10.o -std=c++2a
clean:
	@echo "Cleaning main10..."
	del -include *.o, *.exe