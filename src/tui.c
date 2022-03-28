#include <stdio.h>
#include <sys/ioctl.h>

#include <qlib/colors.h>

/* Sets the cursor position in X = x and Y = y */

void
gotoxy(int x, int y)
{
	/* I hate ANSI scape codes */
	printf("\033[%d;%dH", y, x);
	return;
}

/* Gets terminal size (Rows and columns) */

void
get_term_size(int *lines, int *columns)
{
	struct winsize tty;
	ioctl(0, TIOCGWINSZ, &tty);

	*lines = tty.ws_row;
	*columns = tty.ws_col;

	return;
}

int
mwprintf(int x, int y, const char *fmt, ...)
{
	int size = 0;
	va_list args;
	va_start(args, fmt);
	gotoxy(x, y);

	size = vprintf(fmt, args);
	fflush(stdout);
	return size;
}

#include <qlib/colors.h>

int
mwcprintf(int x, int y, int color, int color2, char *fmt, ...)
{
	gotoxy(x, y);
	set_color(color);
	va_list args;
	va_start(args, fmt);
	int size = vcprintf(color, color2, fmt, args);
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
	if(pid == 0) { /* Child */
		for(int i = 0; i < 1000; i++) {
			mwprintf(0, 5, "%d", i);
			usleep(1000);
		}
	} else {
		for(int i = 0; i < 1000; i++) {
			mwprintf(0, 6, "%d", i);
			usleep(1000);
		}
	}

	mwcprintf(0, 5, RED_FG, BLUE_BG, "%s %i\n", "spurdo spärde", 0);
	set_color(RESET_FG & RESET_BG);
	get_term_size(&x, &y);
	printf("%d %d\n", x, y);
	return 0;
}
#endif /* testing */
