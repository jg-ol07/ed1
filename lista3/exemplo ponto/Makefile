CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

programa: main.o ponto2.o
	$(CC) $(CFLAGS) -o programa main.o ponto2.o -lm

main.o: main.c ponto.h
	$(CC) $(CFLAGS) -c main.c

ponto2.o: ponto2.c ponto.h
	$(CC) $(CFLAGS) -c ponto2.c

clean:
	rm -f *.o programa
