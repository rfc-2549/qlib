/* fdprintf: write format to a file descriptor. */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <qlib/fdprintf.h>

int
vfdprintf(int fd, const char *fmt, va_list ap)
{
	va_list args;
	char *str = NULL;
	va_copy(args, ap);
	int size = vsnprintf(NULL, 0, fmt, args) + 1; /* For '\0' */

	/* if negative number is returned return error */
	if(size < 0) {
		perror("vfdprintf");
		return -1;
	}
	str = (char *)malloc(size);
	if(str == NULL) {
		perror("vfdprintf");
		return -1;
	}
	va_end(args);
	vsprintf(str, fmt, ap);
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
	return 0;
}
#endif
