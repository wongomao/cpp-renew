CC = g++
CFLAGS = -Wall -std=c++2b
OBJS = craps03.o table.o player.o bet.o logger.o

craps: $(OBJS)
	$(CC) -o craps.exe $(OBJS) $(CFLAGS)

craps03.o: craps03.cpp
	$(CC) -c craps03.cpp $(CFLAGS)
table.o: table.cpp
	$(CC) -c table.cpp $(CFLAGS)
player.o: player.cpp
	$(CC) -c player.cpp $(CFLAGS)
bet.o: bet.cpp
	$(CC) -c bet.cpp $(CFLAGS)
logger.o: logger.cpp
	$(CC) -c logger.cpp $(CFLAGS)

clean:
	@echo "Cleaning all..."
	del -include *.o, *.exe