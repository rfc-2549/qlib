#ifndef LOGGER_H
#define LOGGER_H

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


#endif /* LOGGER_H */
