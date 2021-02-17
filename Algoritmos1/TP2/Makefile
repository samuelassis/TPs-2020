CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -g -O2
EXEC = ./tp02

$(EXEC): main.cpp graph.o
	$(CC) $(CFLAGS) main.cpp graph.o -o $(EXEC)

graph.o:
	$(CC) $(CFLAGS) graphCP.cpp -c -o graph.o

clean:
	rm -rf *.o $(EXEC)