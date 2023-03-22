#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>

extern DWORD cWritten;
extern HANDLE hConsole;
extern CONSOLE_SCREEN_BUFFER_INFO screenInfo;

//class Graphics
//{
//public:
//    Graphics() 
//    {
//        GetConsoleScreenBufferInfo(hConsole, &screenInfo);
//    }
//
//    ~Graphics()
//    {
//        CloseHandle(hConsole);
//    }
//};

#endif CONSOLE_H