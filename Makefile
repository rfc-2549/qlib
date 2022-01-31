CC=cc
CFLAGS= -Wall -g -O -fPIC
RM= rm -f
.PHONY: all clean

all: qlib.a

clean:
	$(RM) src/*.o *.a

qlib.a: fdprintf.o xmalloc.o
	ar rsc qlib.a src/fdprintf.o src/xmalloc.o

fdprintf.o: src/fdprintf.o
xmalloc.o:  src/xmalloc.o
