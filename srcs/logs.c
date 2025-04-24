#include "clog.h"

void	logFatal(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	logInternal(LOG_FATAL, msg, args);
	va_end(args);
}

void	logError(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	logInternal(LOG_ERROR, msg, args);
	va_end(args);
}

void	logWarn(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	logInternal(LOG_WARN, msg, args);
	va_end(args);
}

void	logInfo(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	logInternal(LOG_INFO, msg, args);
	va_end(args);
}

void	logDebug(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	logInternal(LOG_DEBUG, msg, args);
	va_end(args);
}

void	logTrace(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	logInternal(LOG_TRACE, msg, args);
	va_end(args);
}
