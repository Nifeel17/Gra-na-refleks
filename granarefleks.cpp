#include <iostream>
#include <chrono>
#include <windows.h>
#include <ctime>
#include <thread>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int punkty = 0;

char mapa[10][4] = {
	'O','O','O','O',
	'O','O','O','O',
	'O','O','O','O',
	'O','D','O','O',
	'O','O','O','O',
	'O','O','O','O',
	'O','O','O','O',
	'O','O','O','O',
	'O','O','O','O',
	'O','O','O','O'
};

void rysowanie() {
	int i = 0, j=0;
	SetConsoleTextAttribute(h, 15);
	cout << "F G H J" << endl;
	while (i < 10) {
		while (j < 4) {
			if (mapa[i][j] == 'S')
			{
				SetConsoleTextAttribute(h, 11);
			}
			else if (i==1) {
				SetConsoleTextAttribute(h, 5);
			}
			else {
				SetConsoleTextAttribute(h, 1);
			}
			cout << char(219) << char(219);
			j++;
		}
		cout << endl;
		j = 0;
		i++;
	}
	SetConsoleTextAttribute(h, 15);
	cout << "Punkty: " << punkty << endl;
}

void przestawienie() {
	int i = 0, a = rand() % 4;
	while (i < 9)
	{
		mapa[i][0] = mapa[i + 1][0];
		mapa[i][1] = mapa[i + 1][1];
		mapa[i][2] = mapa[i + 1][2];
		mapa[i][3] = mapa[i + 1][3];
		i++;
	}
	mapa[9][0] = 'O';
	mapa[9][1] = 'O';
	mapa[9][2] = 'O';
	mapa[9][3] = 'O';
	mapa[9][a] = 'S';
}

bool sprawdzenie() {
	if (mapa[0][0] == 'S' || mapa[0][1] == 'S' || mapa[0][2] == 'S' || mapa[0][3] == 'S') {
		return true;
	}
	else {
		return false;
	}
}

int predkosc() {
	if (punkty > 10) {
		return 8;
	}
	if (punkty > 20) {
		return 6;
	}
	if (punkty > 30) {
		return 4;
	}
	if (punkty > 40) {
		return 3;
	}
	if (punkty > 50) {
		return 2;
	}
	return 10;
}

int main()
{
	using namespace std::this_thread;
	using namespace std::chrono;
	srand(time(NULL));
	bool pozycja1, pozycja2, pozycja3, pozycja4, czyprzegral=false;
	int k=10, a = 0,i=0,j=0;
	while (true) {
		k = predkosc();
		pozycja1 = false;
		pozycja2 = false;
		pozycja3 = false;
		pozycja4 = false;
		przestawienie();
		rysowanie();
		czyprzegral=sprawdzenie();
		if (czyprzegral==true) {
			cout << "Przegrales" << endl;
			return 0;
		}
		i = 0;
		while (i < k)
		{
			sleep_for(microseconds(70000));
			if (GetAsyncKeyState('F')) {
				if (mapa[1][0]=='S') {
					mapa[1][0] = 'O';
					system("cls");
					punkty++;
					rysowanie();
				}
				else {
					cout << "Przegrales" << endl;
					return 0;
				}
			}
			if (GetAsyncKeyState('G')) {
				if (mapa[1][1] == 'S') {
					mapa[1][1] = 'O';
					system("cls");
					punkty++;
					rysowanie();
				}
				else {
					cout << "Przegrales" << endl;
					return 0;
				}
			}
			if (GetAsyncKeyState('H')) {
				if (mapa[1][2] == 'S') {
					mapa[1][2] = 'O';
					system("cls");
					punkty++;
					rysowanie();
				}
				else {
					cout << "Przegrales" << endl;
					return 0;
				}
			}
			if (GetAsyncKeyState('J')) {
				if (mapa[1][3] == 'S') {
					mapa[1][3] = 'O';
					system("cls");
					punkty++;
					rysowanie();
				}
				else {
					cout << "Przegrales" << endl;
					return 0;
				}
			}
			i++;
		}
		system("cls");
	}
}
