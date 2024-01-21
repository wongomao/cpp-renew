craps: craps02.o
	g++ -o craps.exe craps02.o -std=c++2b
craps02.o: craps02.cpp
	g++ -c craps02.cpp -std=c++2b
all: craps02.o
	g++ -o craps.exe craps02.o -std=c++2b
clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe