#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
void file();
void draw();
void BGcolor(int code);
void ShowCur(bool CursorVisibility);
int main()
{
	int x;
	SetConsoleOutputCP(65001);
	cout << "Type your password: ";
	cin >> x;
	BGcolor(10);
	Sleep(1000);
	cout << "[Extracting files...]" << endl;
	if (x == 100)
	{
		BGcolor(15);
		for (int i = 0; i <= 100; i+=10)
		{
			cout << "...Loading " << i << "%" << endl;
			Sleep(500);
		}
		BGcolor(100);
	}
	cout << "Extract files Completed!..." << endl;

	cout << endl;
	file();
	system("pause");
}
void draw()
{
	BGcolor(14);
	Sleep(1000);
	system("TYPE C:\\Users\\datcy\\source\\repos\\Program_DSKL\\banner.txt");
	cout << endl;
}
void file()
{
	const char* filename = "../banner.txt";
	BGcolor(10);

	for (int i = 1; i < 5; i++)
	{
		ShowCur(0);
		ifstream file;
		file.open(filename, ios_base::in);
		string line;
		while (getline(file, line)) {
			cout << line << endl;
			Sleep(100);
		}
		file.close();
	}
}
void BGcolor(int code)
{
    static HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}