#ifndef FDPRINTF_H
#define FDPRINTF_H

#include <stdarg.h>

/* Gives string the format that you gave the function. This is like
 * sprintf() or snprintf except that asprintf() automatically
 * malloc()s the string to have exactly the necessary file. So string
 * should be free()'d when you're done with it. */

int
asprintf(char **string, const char *fmt, ...);

/* Same as asprintf() but with va_list instead of variable
 * parameters. */
int
vasprintf(char **string, const char *fmt, va_list ap);

/* Writes formatted output to a file descriptor */

int
fdprintf(int fd, const char *fmt, ...);

/* Writes formatted output to a file descriptor but uses va_list
 * instead of variable parameters. */

int
vfdprintf(int fd, const char *fmt, va_list ap);

#endif /* FDPRINTF_H */
