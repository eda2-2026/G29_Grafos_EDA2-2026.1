CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/main.c src/grafo.c src/leitura.c src/bfs.c src/dfs.c src/dijkstra.c
OUT = campus

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)