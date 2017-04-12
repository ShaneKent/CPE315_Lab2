CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g
MAIN = lab2
OBJS = lab2.o part1.o part2.o part3.o part4.o part5.o part6.o part7.o

all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

lab2.o : lab2.c lab2.h
	$(CC) $(CFLAGS) -c lab2.c

part1.o : part1.c part1.h
	$(CC) $(CFLAGS) -c part1.c

part2.o : part2.c part2.h
	$(CC) $(CFLAGS) -c part2.c

part3.o : part3.c part3.h
	$(CC) $(CFLAGS) -c part3.c

part4.o : part4.c part4.h
	$(CC) $(CFLAGS) -c part4.c

part5.o : part5.c part5.h
	$(CC) $(CFLAGS) -c part5.c

part6.o : part6.c part6.h
	$(CC) $(CFLAGS) -c part6.c

part7.o : part7.c part7.h
	$(CC) $(CFLAGS) -c part7.c

clean : 
	rm *.o $(MAIN)
