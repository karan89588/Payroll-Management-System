#include <windows.h>
using namespace std;
void windowSize(int x,int y)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, x, y, TRUE); // 800 width, 100 height

    // ...
}
