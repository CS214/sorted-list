OBJS= sorted-list.o

CC= gcc

CFLAGS= -Wall -g

sl: $(OBJS)
	$(CC) -o sl $(OBJS)

sorted-list.o: main.c sorted-list.c sorted-list.h
	$(CC) -c $(CFLAGS) sorted-list.c main.c sorted-list.h

clean:
	rm -f sl $(OBJS)