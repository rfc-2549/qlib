CC=cc
CFLAGS= -Wall -g -O -fPIC -pedantic -I"inc/"
RM= rm -f
OBJ = obj/fdprintf.o obj/xmalloc.o obj/shuffle.o obj/logger.o obj/colors.o

.PHONY: all clean

all: qlib.a

clean:
	$(RM) obj/*.o *.a src/a.out

qlib.a: obj/fdprintf.o obj/xmalloc.o obj/shuffle.o obj/logger.o obj/colors.o
	ar rsc qlib.a obj/fdprintf.o obj/xmalloc.o obj/shuffle.o obj/logger.o

obj/fdprintf.o: src/fdprintf.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@  $<
obj/xmalloc.o:  src/xmalloc.c
	$(CC) $(CFLAGS) -c -o $@  $<
obj/shuffle.o:  src/shuffle.c
	$(CC) $(CFLAGS) -c -o $@  $<
obj/logger.o:   src/logger/logger.c
	$(CC) $(CFLAGS) -c -o $@  $<
obj/colors.o:   src/colors.c
	$(CC) $(CFLAGS) -c -o $@  $<
