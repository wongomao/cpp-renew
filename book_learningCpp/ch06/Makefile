main: fileFind.o
	g++ -o main.exe fileFind.o -std=c++2b
fileFind.o: fileFind.cpp
	g++ -c fileFind.cpp -std=c++2b
all: fileFind.o
	g++ -o main.exe fileFind.o -std=c++2b
clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe