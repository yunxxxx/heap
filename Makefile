OBJS=main.o heap.o util.o
DEBUG=-g
CC=g++
CFLAGS=-Wall -c $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=int

&(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

heap.o: heap.h heap.cpp
		 $(CC) $(CFLAGS) heap.cpp

util.o: util.h util.cpp
		 $(CC) $(CFLAGS) util.cpp

clean:
	rm *~ *.o $(EXE) -v