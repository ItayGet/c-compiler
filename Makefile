CC = gcc
CFLAGS = -I.

LIBS = -lm

DEPS = 

OBJ = main.o tlnode.o tbnode.o lexer.o parser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

debug: CFLAGS += -g
debug: main

.PHONY: clean

clean:
	rm -f *.o *~ core *~
