CC=cc
CFLAGS= -Wall -O -fPIC -pedantic -I"inc/"
RM= rm -f
OBJ = obj/fdprintf.o obj/xmalloc.o obj/shuffle.o obj/logger.o	\
	obj/colors.o obj/tui.o obj/rand.o obj/strings.o

.PHONY: all clean install install-shared

all: qlib.a

clean:
	$(RM) obj/*.o *.so *.a src/a.out 

install:
	mkdir -p /usr/include/qlib
	cp    inc/qlib/*.h /usr/include/qlib/
	cp    libqlib.a /usr/lib
	cp    src/queue/queue.h /usr/include/qlib

install-shared: shared
	cp libqlib.so /usr/lib

uninstall:
	$(RM) -r /usr/include/qlib
	$(RM) /usr/lib/libqlib.*

qlib.a: $(OBJ)
	ar rsc libqlib.a $(OBJ)

shared: $(OBJ) qlib.a
	$(CC) -shared -o libqlib.so $(OBJ)

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
obj/tui.o:	src/tui.c
	$(CC) $(CFLAGS) -c -o $@ $<
obj/rand.o:	src/rand.c
	$(CC) $(CFLAGS) -c -o $@ $<
obj/strings.o:	src/strings.c
	$(CC) $(CFLAGS) -c -o $@ $<

