/* qlib header file */
#ifndef QLIB_H
#define QLIB_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* fdprintf.c */
int
fdprintf(int fd, const char *fmt, ...);

int
vfdprintf(int fd, const char *fmt, va_list ap);

/* xmalloc.c */

void
*xmalloc(size_t size, void(handle)());

void
*xcalloc(size_t nmemb, size_t size, void(handle)());

void
*xrealloc(void *ptr, size_t size, void(handle)());

/* shuffle.c */

void
shuffle(void *base, size_t len, size_t nmemb);

/* logger/logger.c */

/* Levels */

#define DEBUG 0
#define INFO 1
#define NOTICE 2
#define WARNING 3
#define ERROR 4
#define CRIT 5
#define ALERT 6

FILE *logger = NULL;

void
init_logger(char *log_file);

int
qlog(int level, char *fmt, ...);


#endif /* QLIB_h */
