#include <stdio.h>

#include <qlib/colors.h>

void
set_color(int color)
{
	printf(PREFIX_FMT, color);
}

int
vcprintf(int fg, int bg, const char *fmt, va_list ap)
{
	set_color(fg);
	if(bg) /* If bg is 0 we don't wanna touch it */
		set_color(bg);
	va_list args;
	va_copy(args, ap);
	int size = vprintf(fmt, args);

	return size;
}

int
cprintf(int fg, int bg, const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int size = vcprintf(fg,bg,fmt,args);
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
	
	cprintf(RED_FG,0,"Hello world! %i\n",42);
	set_color(RESET_BG);
	set_color(RESET_FG);
	
	return 0;
}

#endif /* testing */
