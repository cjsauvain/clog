#ifndef 	CLOG_H
# define	CLOG_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define CLOG_VERSION 		1.0.0

#define DEFAULT_LOG_LEVEL	LOG_INFO

#define	STDOUT				1
#define	STDERR				2
#define DEFAULT_FD_LOG		STDERR

#define BRED "\e[1;31m"
#define RED "\e[0;31m"
#define YEL "\e[0;33m"
#define BWHT "\e[1;37m"
#define BGRAY "\e[90m"
#define MAG "\e[0;35m"
#define RESET "\e[0m"

#define COLOR_STR_MAXLEN			7
#define RESET_STR_LEN				4
#define LOG_LEVEL_STR_MAXLEN		7

typedef enum {
	LOG_FATAL,
	LOG_ERROR,
	LOG_WARN,
	LOG_INFO,
	LOG_DEBUG,
	LOG_TRACE
}	e_logLevel;

void	setLogLevel(e_logLevel level);
void	logInternal(e_logLevel level, const char *msg, va_list args);
void	logFatal(const char *msg, ...);
void	logError(const char *msg, ...);
void	logWarn(const char *msg, ...);
void	logInfo(const char *msg, ...);
void	logDebug(const char *msg, ...);
void	logTrace(const char *msg, ...);
void    closeLogFile();
int 	setLogFile(int logFile);
int 	createLogFile(const char *filename);

#endif
