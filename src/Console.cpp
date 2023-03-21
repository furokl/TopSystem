#include "Console.h"

DWORD cWritten = DWORD();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screenInfo = CONSOLE_SCREEN_BUFFER_INFO();