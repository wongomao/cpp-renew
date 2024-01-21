main: slots.o
	g++ -o main.exe slots.o -std=c++2b
slots.o: slots.cpp
	g++ -c slots.cpp -std=c++2b
all: slots.o
	g++ -o main.exe slots.o -std=c++2b
clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe