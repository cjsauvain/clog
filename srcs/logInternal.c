#include "clog.h"

__attribute__((visibility("hidden")))
e_logLevel	currentLevel = DEFAULT_LOG_LEVEL;
int			fdLog = DEFAULT_FD_LOG;

static void	getColorStr(e_logLevel level, char *colorStr)
{
	if (level == LOG_FATAL)
		strcpy(colorStr, BRED);
	if (level == LOG_ERROR)
		strcpy(colorStr, RED);
	if (level == LOG_WARN)
		strcpy(colorStr, YEL);
	if (level == LOG_INFO)
		strcpy(colorStr, BWHT);
	if (level == LOG_DEBUG)
		strcpy(colorStr, BGRAY);
	if (level == LOG_TRACE)
		strcpy(colorStr, MAG);
}

static void	getLogLevelStr(e_logLevel level, char *logLevelStr)
{
	if (level == LOG_FATAL)
		strcpy(logLevelStr, "[FATAL]");
	if (level == LOG_ERROR)
		strcpy(logLevelStr, "[ERROR]");
	if (level == LOG_WARN)
		strcpy(logLevelStr, "[WARN] ");
	if (level == LOG_INFO)
		strcpy(logLevelStr, "[INFO] ");
	if (level == LOG_DEBUG)
		strcpy(logLevelStr, "[DEBUG]");
	if (level == LOG_TRACE)
		strcpy(logLevelStr, "[TRACE]");
}

static void	writeColoredLogMessage(const char *msg, char *colorStr, \
							char *logLevelStr, size_t messageFullLength, \
							va_list args)
{
	char	fullMessage[messageFullLength + 2];

	snprintf(fullMessage, sizeof(fullMessage), "%s%s %s%s\n", \
				colorStr, logLevelStr, msg, RESET);
	vdprintf(fdLog, fullMessage, args);
}

static void	writeLogMessage(const char *msg, char *logLevelStr, va_list args)
{
	char	fullMessage[strlen(msg) + LOG_LEVEL_STR_MAXLEN + 3];

	snprintf(fullMessage, sizeof(fullMessage), "%s %s\n", logLevelStr, msg);
	vdprintf(fdLog, fullMessage, args);
}

void	logInternal(e_logLevel level, const char *msg, va_list args)
{
	char	colorStr[COLOR_STR_MAXLEN + 1];
	char	logLevelStr[LOG_LEVEL_STR_MAXLEN + 1];
	size_t	messageFullLenght;

	if (level > currentLevel)
		return ;
	getLogLevelStr(level, logLevelStr);
	if (fdLog != STDERR && fdLog != STDOUT)
	{
		writeLogMessage(msg, logLevelStr, args);
		return ;
	}
	getColorStr(level, colorStr);
	messageFullLenght = strlen(msg) + COLOR_STR_MAXLEN + LOG_LEVEL_STR_MAXLEN + RESET_STR_LEN + 1;
	writeColoredLogMessage(msg, colorStr, logLevelStr, messageFullLenght, args);
}
