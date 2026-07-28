/*This file is responsible for the cross-platform calls of function based on platform
* It is a platform-dependent code's file, so there will be no issue in cross-platform compile
*/

#ifdef __WIN32
#include <windows.h>
#define plat_sleep(seconds) Sleep((seconds) * 1000)
#include <windows.h>

void clrscr(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hConsole == INVALID_HANDLE_VALUE)
        return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD topLeft = {0, 0};
    DWORD written;

    // Fill the entire screen with spaces
    FillConsoleOutputCharacter(
        hConsole,
        ' ',
        consoleSize,
        topLeft,
        &written
    );

    // Restore the original text attributes
    FillConsoleOutputAttribute(
        hConsole,
        csbi.wAttributes,
        consoleSize,
        topLeft,
        &written
    );

    // Move the cursor to the upper-left corner
    SetConsoleCursorPosition(hConsole, topLeft);
}

#else
#include <unistd.h>
#define plat_sleep(seconds) sleep(seconds)

#include <curses.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>

void clrscr(void)
{
    if (!isatty(STDOUT_FILENO))
        return;

    int status;
    setupterm(NULL, STDOUT_FILENO, &status);

    if (status == OK)
    {
        char *clear = tigetstr("clear");
        if (clear != (char *)-1 && clear != NULL)
            putp(clear);
    }
}

#endif
