#pragma once
#include"stdafx.h"
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
class Player
{
public:
		int dexterity; //Ловкость
		int strength; //Сила
		int constitution; //Телосложение
		int intellect; //Интеллект
		int wisdom; //Мудрость
		int blood; //Кровь
		int stamina; //Выносливость
		int left_arm_weapon; // Оружие правой руки
		int right_arm_weapon; // Оружие левой руки
		int state_now; // Текущая стойка
		int state_new; // Переходная стойка
		string name; // Имя персонажа
		vector <int> state_id; // Вектор идентефикаторов стоек, которые умеет персонаж
	Player(int D, int S, int C, int I, int W, int LA, int RA, string Name) // Создание персонажа
	{
		
		dexterity = D;
		strength = S;
		constitution = C;
		intellect = I;
		wisdom = W;
		left_arm_weapon = LA;
		right_arm_weapon - RA;
		name = Name;
		blood = 1000 + constitution * 100; // Кровь равна 1000+Тело*100
		stamina = 10000 +constitution * 100;
		state_now = 0; // Начальная стойка с оружием в ножнах
		state_id.push_back(0); //Все умеют стоять с оружием в ножнах
		state_id.push_back(1); //Все умеют стоять с оружием в руках
		state_id.push_back(2); //Все умеют замахиваться оружием для колющего удара
		state_id.push_back(3); //Все умеют замахиваться оружием для режущего удара
		state_id.push_back(4); //Все умеют делать колющий удар
		state_id.push_back(5); //Все умеют делать режущий удар
		state_id.push_back(6); //Все умеют вставать в защитную стойку
		state_id.push_back(7); //Все умеют в скрещенные мечи
		state_id.push_back(8); //Все умеют в стойку отбитого удара(отбивающий)
		state_id.push_back(9); //Все умеют в стойку отбитого удара(атакующий)
	}
	void Turn(Enemy &En) //Ход игрока
	{
		vector <int> state_buff; // Промежуточное хранение стоек для вывода
		int j; // Переменная для подсчета высвечиваемых стоек
repeat:	cout << name; 
		mass_state[state_now].Call_state_1(); // Выводим текущую стойку
		cout << '\n';
		cout << "Выберите действие:";
		for (int i = 0; i < 10; i++) // Выводим все доступные стойки
		{
			if ((mass_state[state_now].vaible[i])&&(state_id[i])) // В стойку должна быть возможность перейти из текущей и её должен знать персонаж
			{
				cout << j << ". ";
				mass_state[i].Call_state_2();
				cout << '\n';
				state_buff.push_back(mass_state[i].id);
				j++;
			}
		}
		cout << "Выбираем действие: ";
		cin >> state_new; // Вводим новую стойку
		state_new = state_buff[state_new];
		int enemy_dexterity = En.dexterity, enemy_strength=En.strength, enemy_constitution=En.constitution,enemy_wisdom=En.wisdom,enemy_intellect=En.intellect;// параметры которые не должны быть изменены передаем в функцию через копию
		int *enemy_blood_s = &En.blood;//указата на параметр крови для его изменения
		int *enemy_stamina_s= &En.stamina;// указатель на параметр выносливости для его изменения
		int *blood_s = &blood;//указатель на кровь игрока
		int *stamina_s = &stamina;// указатель на выносливость игрока
		if (mass_state[state_now].vaible[state_new]) // Персонаж должен уметь в стойку
		{
			system("cls");
			mass_state[state_new].Call_state_work(enemy_strength,enemy_constitution,enemy_dexterity,enemy_wisdom,enemy_intellect,enemy_blood_s,enemy_stamina_s,
				strength,constitution,dexterity,wisdom,intellect,blood_s,stamina_s); // Вызывает срабатывание стойки
		}
		else 
		{
			cout << "\nВы ввели что-то не то!" << '\n';
			goto repeat;
		};
	}

	

};



