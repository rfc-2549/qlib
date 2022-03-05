#include <stdio.h>

#include "qlib/tui.h"


void
gotoxy(int x, int y)
{
	/* I hate ANSI scape codes */
	printf("\033[%d;%dH",y,x);
}

int
mwprintf(int x, int y, const char *fmt, ...)
{
	int size = 0;
	va_list args;
	va_start(args, fmt);
	gotoxy(x,y);

	size = vprintf(fmt, args);
	fflush(stdout);
	return size;
	
}

#ifdef testing
#include <unistd.h>
#include <stdio.h>
int
main(void)
{

	int x = 0, y = 0;

	int pid = fork();
	if(pid == 0) { 		  /* Child */
		for(int i = 0; i < 1000; i++) {
			mwprintf(5,0,"%d",i);
			usleep(1000);
		}
	} else {
		for(int i = 0; i < 1000; i++) {
			mwprintf(6,0,"%d",i);
			usleep(1000);
		}
	}
	return 0;
}

#endif  /* testing */
