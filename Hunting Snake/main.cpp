#include<iostream>
#include"mylib.h"
#include <Windows.h>
#define MAX 100

using namespace std;
int MSSV = 8;
int Mssv[8] = { 2,3,1,2,0,2,1,0 };
int Toadox[MAX] = { 0 };
int Toadoy[MAX] = { 0 };

void OnLine();
void UnderLine();
void RightLine();
void LeftLine();
void Map();
void DefineSnake(int Toadox[], int Toadoy[]);
void Snake(int Toadox[], int Toadoy[]);
void AddToSnake(int a[], int x);
void DeleteToaDo(int a[], int vt);
void HandleSnake(int Toadox[], int Toadoy[], int x, int y, int& Xfruit, int& Yfruit);
void DeleteOldData(int Toadox[], int Toadoy[]);
bool GameOver(int Toadox[], int Toadoy[], int x0, int y0);
bool CheckFruit(int Xfruit, int Yfruit, int Toadox[], int Toadoy[]);
void ProduceFruit(int& Xfruit, int& Yfruit, int Toadox[], int Toadoy[]);
void Control(int Toadox[], int Toadoy[],int Xfruit,int yqua);
bool EatFruit(int Xfruit, int Yfruit, int x0, int y0);

//vẽ tường trên
void OnLine()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "*";
		x++;
	}
}

//vẽ tường dưới
void UnderLine()
{
	int x = 10, y = 26;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "*";
		x++;
	}
}

//vẽ tường phải
void RightLine()
{
	int x = 100, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "*";
		y++;
	}
}

//vẽ tường trái
void LeftLine()
{
	int x = 10, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "*";
		y++;
	}
}

//tạo map
void Map()
{
	SetColor(11);
	OnLine();
	UnderLine();
	RightLine();
	LeftLine();
	SetColor(7);
}

void DefineSnake(int Toadox[], int Toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < MSSV; i++)
	{
		Toadox[i] = x;
		Toadoy[i] = y;
		x--;
	}
}

//vẽ rắn
void Snake(int Toadox[], int Toadoy[])
{
	for (int i = 0; i < MSSV; i++)
	{
		gotoXY(Toadox[i], Toadoy[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "o";
		}
	}
}

//thêm 1 kí tự vào rắn
void AddToSnake(int a[], int x)
{
	for (int i = MSSV; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	MSSV++;
}

//xóa phần tử cuối cùng khi di chuyển sang ô khác
void DeleteToaDo(int a[], int vt)
{
	for (int i = vt; i < MSSV; i++)
	{
		a[i] = a[i + 1];
	}
	MSSV--;
}

void HandleSnake(int Toadox[], int Toadoy[], int x, int y,int & Xfruit,int & Yfruit)
{
	//Thêm tọa độ mới vào mảng
	AddToSnake(Toadox, x);
	AddToSnake(Toadoy, y);
	if (EatFruit(Xfruit, Yfruit, Toadox[0], Toadoy[0]) == false)
	{
		//xóa tọa độ cuối mảng
		DeleteToaDo(Toadox, MSSV -1);
		DeleteToaDo(Toadoy, MSSV -1);
	}
	else
	{
		MSSV--;
		ProduceFruit(Xfruit, Yfruit, Toadox, Toadoy);
	}
	//vẽ rắn
	Snake(Toadox, Toadoy);
}


void DeleteOldData(int Toadox[], int Toadoy[])
{
	for (int i = 0; i < MSSV; i++)
	{
		gotoXY(Toadox[i], Toadoy[i]);
		cout << " ";
	}
}



bool GameOver(int Toadox[], int Toadoy[], int x0, int y0)
{
	//rắn chạm tường trên
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	//rắn chạm tường dưới
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	//rắn chạm tường phải
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	//rắn chạm tường trái
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	//rắn chạm đuôi
	for (int i = 1; i < MSSV; i++)
	{
		if ((Toadox[0] == Toadox[i]) && (Toadoy[0] == Toadoy[i]))
		{
			return true;
		}
	}
	return false;
}

//Hàm kiểm tra xem quả lúc khởi tạo có bị rắn đè không 
bool CheckFruit(int Xfruit, int Yfruit, int Toadox[], int Toadoy[])
{
	for (int i = 0; i < MSSV; i++)
	{
		if ((Xfruit == Toadox[i]) && (Yfruit == Toadoy[i]))
		{
			return true; //ran de len qua
		}
	}
	return false;
}

//Tạo quả
void ProduceFruit(int & Xfruit, int & Yfruit,int Toadox[],int Toadoy[])
{
	do
	{
		//tọa độ x của quả nằm trong khoảng [11,99]
		Xfruit = rand() % (99 - 11 + 1) + 11;
		//toa do  y cua qua nam trong khoang [2,15]
		//tọa độ của y quả nằm trên khoảng [2,15]
		Yfruit = rand() % (15 - 2 + 1) + 2;
	} while (CheckFruit(Xfruit, Yfruit, Toadox, Toadoy)==true);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoXY(Xfruit, Yfruit);
	cout << "o";
	SetColor(7);
}

//điểu khiển rắn
void Control(int Toadox[], int Toadoy[],int xqua,int yqua)
{
	int x = 50, y = 13; //vị trí đầu tiên của rắn
	bool Gameover = false;
	int Check = 2;
	while (Gameover == false)
	{
		DeleteOldData(Toadox, Toadoy);
		//?i?u khi?n r?n
		if (_kbhit())
		{
			char Input = _getch();
			if (Input == -32)
			{
				char Input = _getch();
				if (Input == 72 && Check != 0) //đi lên
				{
					Check = 1;
				}
				else if (Input == 80 && Check != 1) // đi xuống
				{
					Check = 0;
				}
				else if (Input == 75 && Check != 2) // đi qua trái
				{
					Check = 3;
				}
				else if (Input == 77 && Check != 3) // đi qua phải
				{
					Check = 2;
				}
			}
		}
		if (Check == 0) //đi xuống
		{
			y++;
		}
		else if (Check == 1) // đi lên
		{
			y--;
		}
		else if (Check == 2) // đi sang ph?i
		{
			x++;
		}
		else if (Check == 3) // đi sang trái
		{
			x--;
		}
		HandleSnake(Toadox, Toadoy, x, y,xqua,yqua);
		Gameover = GameOver(Toadox, Toadoy, Toadox[0], Toadoy[0]);
		Sleep(150);
	}
}

bool EatFruit(int Xfruit,int Yfruit,int x0,int y0)
{
	
	if ((x0 == Xfruit) && (y0 == Yfruit))
	{
		return true; //ran an qua
	}
	return false;
}

int main() {
	int Toadox[MAX], Toadoy[MAX];
	Map();
	DefineSnake(Toadox, Toadoy);
	//ve ran
	Snake(Toadox, Toadoy);
	srand(time(NULL));
	int Xfruit = 0, Yfruit = 0;
	//tao qua
	ProduceFruit(Xfruit, Yfruit, Toadox, Toadoy);
	Control(Toadox, Toadoy, Xfruit, Yfruit);
	_getch();
	return 0;
}

