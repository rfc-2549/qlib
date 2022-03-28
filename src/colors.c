#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>

#include "../inc/qlib/colors.h"

/* Sets the color to the given color */

void
set_color(int color)
{
	printf(PREFIX_FMT, color);
}

/* like vprintf() but with colors.
 *
 * Not thread-safe, if you have 2 threads (one running printf(), and
 * thus, with default color, and other running vcprintf() with some
 * color, if they print at the same time, printf() will use the colors
 * used by vcprintf().
 *
 * To fix this, just use a simple mutex, and the problem will be
 * fixed, I've tested this.
 */

int
vcprintf(int fg, int bg, const char *fmt, va_list ap)
{
	set_color(fg);
	if(bg) /* If bg is 0 we don't wanna touch it */
		set_color(bg);
	va_list args;
	va_copy(args, ap);
	int size = vprintf(fmt, args);
	set_color(RESET_FG);
	set_color(RESET_BG);
	return size;
}

/* Same as vcprintf() but thread safe */
#include <pthread.h>

int
vcprintf_r(int fg, int bg, const char *fmt, va_list ap)
{
	flockfile(stdout);
	set_color(fg);
	if(bg) /* If bg is 0 we don't wanna touch it */
		set_color(bg);
	va_list args;
	va_copy(args, ap);
	
	int size = vprintf(fmt, args);
	
	
	set_color(RESET_FG);
	set_color(RESET_BG);
	funlockfile(stdout);
	return size;
}

/* Same as cprintf() but thread safe */

int
cprintf_r(int fg, int bg, const char *fmt, ...)
{
	va_list args;
	__builtin_va_start(args, fmt);
	int size = vcprintf_r(fg, bg, fmt, args);
	return size;
}

/* Same as vcprintf() but with variable arguments */

int
cprintf(int fg, int bg, const char *fmt, ...)
{
	va_list args;
	__builtin_va_start(args, fmt);
	int size = vcprintf(fg, bg, fmt, args);
	return size;
}

#ifdef testing

int
main(void)
{
	set_color(RED_FG);
	puts("This text should be red");

	set_color(YELLOW_FG);
	puts("This text should be yellow");

	set_color(RESET_FG);
	puts("This should be normal");

	set_color(RED_BG);
	puts("This should have red background");

	set_color(BLUE_BG);
	set_color(RED_FG);
	puts("This should have blue bg and red fg");

	set_color(RESET_BG);
	set_color(RESET_FG);
	puts("Should be normal");

	cprintf(RED_FG, 0, "Hello world! %i %s\n", 42, "spurdo sparde");
	set_color(RESET_BG);
	set_color(RESET_FG);
	
	return 0;
}

#endif /* testing */
