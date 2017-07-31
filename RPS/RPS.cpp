// RPS.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "targetver.h"
#include "iostream"
#include "Player.h"
#include "Enemy.h"
#include "Function.h"
#include "State.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <regex>   
#include <fstream>
using namespace std;
float global_time = 0; // Глобальное время
bool hit_flag = false; // Флаг состоявшегося удара
void main()
{
	setlocale(LC_ALL, "Rus");
	int d, s, c, i, w, b, st, la, ra, dice;
	string name;
	cout << "Введите параметры персонажа 1\n";
	cout << "Ловкость=";
	cin >> d;
	cout << "Сила=";
	cin >> s;
	cout << "Телосложение=";
	cin >> c;
	cout << "Интеллект=";
	cin >> i;
	cout << "Мудрость=";
	cin >> w;
	cout << "Имя персонажа-";
	cin >> name;
	Player Main_player(d, s, c, i, w, 0, 1, name);
	system("cls");
	system("pause");
	Enemy Enemy_first(8, 10, 9, 8, 9, 0, 0, "Бродяга");
	Enemy *En = &Enemy_first;
	cout << Enemy_first.name <<'\n';
	if (check(Main_player.dexterity, Enemy_first.dexterity))
		Main_player.Turn(Enemy_first);
	else Enemy_first.Turn();



}

