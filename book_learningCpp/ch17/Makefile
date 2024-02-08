CC = g++
CFLAGS = -Wall -std=c++2b
OBJS = main14.o

main : $(OBJS)
	$(CC) -o main.exe $(OBJS) $(CFLAGS)

main14.o : main14.cpp
	$(CC) -c main14.cpp $(CFLAGS)

clean :
	@echo "Cleaning all..."
	del -include *.o, *.exe