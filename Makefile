CC=cc
CFLAGS= -Wall -g -O -fPIC -pedantic -I"inc/"
RM= rm -f
.PHONY: all clean

all: qlib.a

clean:
	$(RM) src/*.o *.a src/a.out

qlib.a: fdprintf.o xmalloc.o shuffle.o logger.o colors.o
	ar rsc qlib.a src/fdprintf.o src/xmalloc.o src/shuffle.o src/logger/logger.o

fdprintf.o: src/fdprintf.o
xmalloc.o:  src/xmalloc.o
shuffle.o: src/shuffle.o
logger.o: src/logger/logger.o
colors.o: src/colors.o
