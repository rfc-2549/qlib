#ifndef FDPRINTF_H
#define FDPRINTF_H

#include <stdarg.h>

int
fdprintf(int fd, const char *fmt, ...);

int
vfdprintf(int fd, const char *fmt, va_list ap);

#endif /* FDPRINTF_H */
