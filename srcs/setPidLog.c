#include "clog.h"

__attribute__((visibility("hidden")))
bool	PID_enabled = false;

void	setPidLog()
{
	PID_enabled = true;
}

void	unsetPidLog()
{
	PID_enabled = false;
}
