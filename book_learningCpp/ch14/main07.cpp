#include <iostream>
#include <windows.h>

void doTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << color << ": hi" << std::endl;
}

int main()
{
    // std::cout << "\033[1;32m*\033[0m" << std::endl; // uncompilable
    // how to do colors in windows:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    std::cout << "hi" << std::endl;

    SetConsoleTextAttribute(hConsole, 7);
    std::cout << "----------------------------------------" << std::endl;

    for (int i = 1; i < 30; i++)
    {
        doTextColor(i);
    }
    std::cout << "----------------------------------------" << std::endl;

    doTextColor(6); // yellow
    doTextColor(9); // blue
    doTextColor(12); // red

    doTextColor(7); // return to normal


    return 0;
}