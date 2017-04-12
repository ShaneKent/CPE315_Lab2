CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g
MAIN = lab2
OBJS = lab2.o

all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

lab2.o : lab2.c
	$(CC) $(CFLAGS) -c lab2.c

clean : 
	rm *.o $(MAIN)
