// #include <Windows.h>
// #include <iostream>
 
// int main()
// {
//     // Grab a handle to the existing console and pass STD_OUTPUT_HANDLE to tell windows 
//     // we want the console screen buffer
//     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
 
//     // Set the console screen buffer size 
//     short columns = 50;
//     short rows = 10;
//     SetConsoleScreenBufferSize(consoleHandle, { columns, rows });
 
//     // CHAR_INFO stores information about a character such as the character to draw, its encoding and colour
//     // Store all our CHAR_INFOs into a 1D array
//     CHAR_INFO* buffer = new CHAR_INFO[columns * rows];
//     int multiple = 0;
     
//     // Its easier to think of it as a 2D array so we iterate throught using two for loops 
//     for (int row = 0; row < rows; row++)
//     {
//         for (int column = 0; column < columns; column++)
//         {
//             CHAR_INFO charInfo;
    
//             // if (column == 25 && row == 5)
//             // {
//             //     charInfo.Char.AsciiChar = rand() % 26 + 'a';
//             //     charInfo.Attributes = FOREGROUND_GREEN;
//             // }
//             // else
//             // {
//                 charInfo.Char.AsciiChar = ' ';
//                 charInfo.Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
//             // }
 
//             // We are iterating as if its a 2D array but its a 1D array so we have to calculate the index 
//             // e.g. when multiple is 0 our index is between (0,49) when we move to the next row we up the
//             // multiplier so we are now storing values in the range (50,99) and so on.
//             int index = column + (columns * multiple);
//             buffer[index] = charInfo;
//         }
//         multiple++;
//     }
 
//     SMALL_RECT srctReadRect;
//     SMALL_RECT srctWriteRect;
//     COORD coordBufSize;
//     COORD coordBufCoord;
 
//     coordBufSize.Y = rows;
//     coordBufSize.X = columns;
 
//     coordBufCoord.X = 0;
//     coordBufCoord.Y = 0;
 
//     srctWriteRect.Top = 0;
//     srctWriteRect.Left = 20;
//     srctWriteRect.Bottom = rows - 1;
//     srctWriteRect.Right = columns - 1;
//     SetConsoleTitleA("UMER MEHMOOD");
//     while (true)
//     {
//         // Draw to the console
//         WriteConsoleOutputA(
//             consoleHandle,          // screen buffer to write to
//             buffer,                 // buffer to copy from
//             coordBufSize,           // col-row size of buffer
//             coordBufCoord,          // top left src cell in buffer
//             &srctWriteRect);        // dest. screen buffer rectangle

//         // buffer[0].Char.AsciiChar = '\033['+ (rand() % 8 + 40 ) + 'm';
//         // buffer[columns * rows].Char.AsciiChar = '\033[0m';
//         for (size_t i = 0; i < rows * columns; i++)
//         {
//            buffer[i].Char.AsciiChar = '\033['+ (rand() % 8 + 40 ) + 'm';
//         }
//         buffer[columns *rows].Char.AsciiChar = '\033[0m';
//         Sleep(100);

//     }

 
//     return 0;
// }


#include <iostream>
using namespace std;
class EFG{
    int e;
    int f;
    int g;
    public:
    EFG(): e(-30), f(++e), g(f++){
        cout << "e = " << e << endl;
        cout << "f = " << f << endl;
        cout << "g = " << g << endl;
    };
};

int main(){
    EFG efg;
    system("pause");
    return 0;
}

