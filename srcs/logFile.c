#include "clog.h"

extern	int	fdLog;

void	closeLogFile()
{
	if (fdLog != STDERR && fdLog != STDOUT)
	{
		close(fdLog);
		fdLog = STDERR;
	}
}

int	setLogFile(int logFile)
{
	if (logFile < 0)
	{
		dprintf(STDERR, "Error setLogFile: Invalid fd\n");
		return -1;
	}
	if (fdLog != STDERR && fdLog != STDOUT)
		close(fdLog);
	fdLog = logFile;
	return 0;
}

int	createLogFile(const char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd == -1)
	{
		perror("Error createLogFile");
		return -1;
	}
	if (fdLog != STDERR && fdLog != STDOUT)
		close(fdLog);
	fdLog = fd;
	atexit(closeLogFile);
	return fd;
}
