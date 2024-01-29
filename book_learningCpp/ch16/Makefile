CC = g++
CFLAGS = -Wall -std=c++2b
OBJS = main03.o math_utils.o

main : $(OBJS)
	$(CC) -o main.exe $(OBJS) $(CFLAGS)

main03.o : main03.cpp
	$(CC) -c main03.cpp $(CFLAGS)
math_utils.o : math_utils.cpp
	$(CC) -c math_utils.cpp $(CFLAGS)

clean :
	@echo "Cleaning all..."
	del -include *.o, *.exe