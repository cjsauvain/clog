# Clog - Logging library for C Projects

Clog is a clean and modular logging library written in C.
It provides multiple log levels (Fatal, Error, Warn, Info, Debug, Trace) to help you debug and monitor your C applications easily.

## 🚀 Features

- Simple and intuitive API
- ANSI color-coded output
- Configurable log level filtering
- Can log to stdout or log file

## 📦 Installation

```bash
make && make install
```
**This command will:**
- copy clog.h header into /usr/local/include directory
- create /opt/customlibs and copy libclog.so into it
- create a symlink /usr/local/lib/libclog.so -> /opt/customlibs/libclog.so

## 🛠 Example

```c
#include <clog.h>

int main()
{
    log_set_level(LOG_DEBUG);

    logInfo("This is an info message");
    logDebug("This is a debug message");
    logError("This is an error message");
    logTrace("This is a trace message");
    return 0;
}
```

**Compile and link:**
```bash
gcc main.c -lclog
```
![Capture d'écran 2025-04-19 133653](https://github.com/user-attachments/assets/0ec6a676-0325-4a49-9fd1-40411348c0f5)
