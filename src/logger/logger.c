#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "logger.h"

/* More secure than Log4j! */

/* Levels */

#define DEBUG 0
#define INFO 1
#define NOTICE 2
#define WARNING 3
#define ERROR 4
#define CRIT 5
#define ALERT 6

void
init_logger(char *log_file)
{
	logger = fopen(log_file, "a+");
	return;
}

int
qlog(int level, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int pid = getpid();

	char *level_str = NULL;
	/* I know what a hash map is */
	switch(level) {
		case 0:
			level_str = "DEBUG";
			break;
		case 1:
			level_str = "INFO";
			break;
		case 2:
			level_str = "NOTICE";
			break;
		case 3:
			level_str = "WARNING";
			break;
		case 4:
			level_str = "ERROR";
			break;
		case 5:
			level_str = "CRIT";
			break;
		case 6:
			level_str = "ALERT";
			break;
	}
	fprintf(logger, "%s: (%i) ", level_str, pid);
	int size = vfprintf(logger, fmt, args);
	fputc('\n', logger);
	va_end(args);
	return size;
}

#ifdef testing
int
main(void)
{
	init_logger("qlib.log");
	qlog(DEBUG, "This is debug");
	qlog(INFO, "This is info");
	qlog(NOTICE, "This is notice");
	qlog(WARNING, "This is warning");
	qlog(CRIT, "This is crit");
	qlog(ALERT, "This is an alert");
	
	return 0;
}
#endif /* testing */
