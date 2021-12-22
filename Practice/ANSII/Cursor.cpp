#include <iostream>
#include <windows.h>

// hide cursor
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void showCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
using namespace std;

namespace ConsoleColor {

    char clearLine[] = { 0x1b, '[', '2', 'J', 0x00 };
    char moveBack(int n) {
        cout << "\033[" << n << "D";
        return '\0';
    }

    char moveForward(int n) {
        cout << "\033[" << n << "C";
        return '\0';
    }

    char moveUp(int n) {
        cout << "\033[" << n << "A";
        return '\0';
    }

    char moveDown(int n) {
        cout << "\033[" << n << "B";
        return '\0';
    }

    char moveTo(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
        return '\0';
    }

    char scrollUp(int n) {
        cout << "\033[" << n << "S";
        return '\0';
    }

    char scrollDown(int n) {
        cout << "\033[" << n << "T";
        return '\0';
    }

    char clearScreen() {
        cout << "\033[2J";
        return '\0';
    }


    char setColor(int color) {
        cout << "\033[0;" << color << "m";
        return '\0';
    }

    char setBackgroundColor(int r, int g, int b) {
        cout << "\033[48;2" << r << ";" << g << ";" << b << "m";
        return '\0';
    }

    char resetColor() {
        cout << "\033[0m";
        return '\0';
    }

    
};


bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

using namespace ConsoleColor;
int main(){

    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;
    cout << "MY NAME IS: KULU" << moveBack(4) << "UMER" << endl;

    cout << "MY NAME IS: KULU";
    moveBack(1);
    moveBack(1);
    moveBack(1);
    moveBack(1);
    cout << "U";
    cout << "M";
    cout << "E";
    cout << "R";
    cout << endl;

    unsigned long long int n = 0;
    hideCursor();
    for (size_t i = 0; i < 958465346645; i++)
    {
        if (isPrime(i))
        {
            cout << setBackgroundColor(i%100, i%100, i%100) << "                                                                                                                                   " << resetColor() << '\r';
        }
    }
    showCursor();
    

    
    return 0;
}