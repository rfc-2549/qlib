/* fdprintf: write format to a file descriptor. */
/* This also provides asprintf() which does exactly the same as the
 * GNU extension. fdprintf() uses the asprintf() version provided
 * here. */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../inc/qlib/colors.h"
#include "../inc/qlib/fdprintf.h"


int
vasprintf(char **string, const char *fmt, va_list ap)
{
	int size = 0;
	va_list args;
	va_copy(args, ap);
	size = vsnprintf(NULL, 0, fmt, args);
	*string = malloc(size + 1); /* + 1 because \0 */
	if(string == NULL) {
		perror("qlib vasprintf");
		return -1;
	}
	vsprintf(*string, fmt, ap);
	va_end(ap);
	return size;
}

int
asprintf(char **string, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int size = vasprintf(string, fmt, ap);
	va_end(ap);
	return size;
}

int
vfdprintf(int fd, const char *fmt, va_list ap)
{
	char *str = NULL;
	int size = vasprintf(&str, fmt, ap);
	if(write(fd, str, size + 1) <= 0) {
		perror("vfdprintf");
		free(str);
		return -1;
	}
	free(str);
	return size;
}

int
fdprintf(int fd, const char *fmt, ...)
{
	va_list args;
	int size = 0;
	va_start(args, fmt);
	size = vfdprintf(fd, fmt, args);
	va_end(args);
	return size;
}

#ifdef testing
int
main(void)
{
	fdprintf(1, "%s %i\n", "test", 32); /* STDOUT */
	fdprintf(2, "%s %i\n", "test", 32); /* STDERR */
	char *string = NULL;
	asprintf(&string,"Hello world! %i",42);
	puts(string);
	free(string);
	return 0;
}
#endif
