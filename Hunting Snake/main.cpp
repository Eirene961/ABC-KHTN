#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
//Fix the console window so that the user cannot resize it
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

}

//Set the console window size
void SetConsoleWindow(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//Move the console window to the specified position
void MoveWindow(int posx, int posy)
{
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

//Move the console window to the center of the screen
void MoveCenter()
{
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    int posx, posy;
    posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
        posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

        MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

//Hide the cursor

void HideCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

//Close console window
void CloseConsole() {
    HWND hWndConsole = GetConsoleWindow(); // Get the handle to the console window
    if (hWndConsole != NULL) {
        SendMessage(hWndConsole, WM_CLOSE, 0, 0); // Close the console window
    }
}

//Set the font size and font type of the console
void setCellSize(int x, int y) {
    CONSOLE_FONT_INFOEX cf = { 0 };
    cf.cbSize = sizeof cf;
    cf.dwFontSize.X = x;
    cf.dwFontSize.Y = y;
    wcscpy_s(cf.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

// Hàm thay đổi màu kí tu của console
void textColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    WORD wAttributes = (csbi.wAttributes & 0xFFF0) | (color & 0x000F);
    SetConsoleTextAttribute(hConsole, wAttributes);
}

// Hàm thay đổi màu nen của console
void backColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    WORD wAttributes = (csbi.wAttributes & 0xFF0F) | ((color << 4) & 0x00F0);
    SetConsoleTextAttribute(hConsole, wAttributes);
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//=========================================================================

// Set màu chữ và nền chữ
void setConsoleColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}

// Vẽ một đg thẳng từ điểm (x,y) có độ dài l theo trục X
void drawLineX(int x, int y, int l, int color) {
    setConsoleColor(color, color);
    gotoXY(x, y);
    for (int i = x; i < x + l; i++) {
        cout << " ";
    }
}
// Vẽ một đg thẳng từ điểm (x,y) có độ dài l theo trục Y
void drawLineY(int x, int y, int l, int color) {
    setConsoleColor(color, color);
    for (int i = y; i < y + l; i++) {
        gotoXY(x, i);
        cout << " ";
    }
}

//Vẽ hình chữ nhật rỗng từ điểm (x,y) rộng w cao h
void drawRect(int x, int y, int w, int h, int color) {
    drawLineX(x, y, w, color);
    drawLineX(x, y + h - 1, w, color);
    drawLineY(x, y, h, color);
    drawLineY(x + w - 1, y, h, color);
}

//Vẽ hình chữ nhật đặc từ điểm (x,y) rộng w cao h
void fillRect(int x, int y, int w, int h, int color) {
    setConsoleColor(color, color);
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            gotoXY(i, j);
            cout << " ";
        }
    }
}

//Vẽ chữ từ file txt từ điểm (x,y)
void drawTextFromFileTXT(const char* filename, int x, int y, int color) {
    fstream fin; fin.open(filename);
    if (!fin.is_open()) return;

    setConsoleColor(color, color);

    int _x = x, _y = y;
    char c;
    while (!fin.eof()) {
        fin.get(c);
        if (c == 'z') {
            gotoXY(_x++, _y);
            cout << " ";
        }
        else if (c == ' ') {
            _x++;
        }
        else if (c == '\n') {
            _y++;
            _x = x;
        }
    }
    fin.close();
}

int main()
{
    //Mấy hàm console lấy từ file của Báu
    FixConsoleWindow();
    HideCursor();
    setCellSize(15, 15);
    SetConsoleWindow(1270, 720);

    //Hiện tại chỉ có mấy hàm nên không chia file, để gộp lại chia luôn, chỉ test vậy thôi
    drawRect(2, 2, 70,40, 5);
    drawRect(71, 2, 20,40, 5);
    
    fillRect(3, 3, 68, 38, 2);
    fillRect(72, 3, 18, 38, 6);

    //Chưa biết in chữ bằng cách nào khác, nếu thấy không ổn thì dùng cout<<"NEW GAME";
    drawTextFromFileTXT("newgame.txt", 19, 13, 5);
    drawTextFromFileTXT("loadgame.txt", 18, 23, 5);

    setConsoleColor(3, 15);
    gotoXY(10, 10); cout << "NEWGAME";
    while (1);
	return 0;
}
