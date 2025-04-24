#include "clog.h"

extern	e_logLevel	currentLevel;

void	setLogLevel(e_logLevel level)
{
	if (level < LOG_FATAL)
		level = LOG_TRACE;
	else if (level > LOG_TRACE)
		level = LOG_FATAL;

	currentLevel = level;
}
