CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -g -O2
EXEC = ./tp02

$(EXEC): main.cpp graph
	$(CC) $(CFLAGS) main.cpp graph.o -o $(EXEC)

graph.o:
	$(CC) $(CFLAGS) graph.cpp -c

clean:
	rm -rf *.o $(EXEC)