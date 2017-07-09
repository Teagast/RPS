// RPS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Player.h"

using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	int D, S, C, I, W, B, St, LA, RA;
	string name;
	cout << "Введите параметры персонажа 1\n";
	cout << "Ловкость=";
	cin >> D;
	cout << "Сила=";
	cin >> S;
	cout << "Телосложение=";
	cin >> C;
	cout << "Интеллект=";
	cin >> I;
	cout << "Мудрость=";
	cin >> W;
	cout << "Имя персонажа-";
	cin >> name;
	cout << "Чем занята правая рука? 0- ничем, 1- меч. Правая=";
	cin >> RA;
	cout << "Чем занята левая рука? 0- ничем, 1- меч. Левая=";
	cin >> LA;
	Player Player1(D, S, C, I, W, LA, RA, name);
	system("cls");
	cout << "Создаем второго персонажа. \n";
	system("pause");
	cout << "Ловкость=";
	cin >> D;
	cout << "Сила=";
	cin >> S;
	cout << "Телосложение=";
	cin >> C;
	cout << "Интеллект=";
	cin >> I;
	cout << "Мудрость=";
	cin >> W;
	cout << "Имя персонажа-";
	cin >> name;
	cout << "Чем занята правая рука? 0- ничем, 1- меч. Правая=";
	cin >> RA;
	cout << "Чем занята левая рука? 0- ничем, 1- меч. Левая=";
	cin >> LA;
	Player Player2(D, S, C, I, W, LA, RA, name);


}

