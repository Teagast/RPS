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
class State // Класс стойки
{
public:
	int id; // Идентификатор стойки
	bool vaible[10]; //Доступные стойки
	int type; // Тип стойки: 0-Стойка-замах; 1-Стойка-удар; 2-Защитная стойка; 3-Стойка блок
	int stamin_cost; // К-во затраченной выносливости на стойку
	int stamin_max; // К-во выносливости, которое можно потратить на стойку дополнительно
	double damage; // Коэффициент урона стойки
	double time_to_state; // Время для перехода в стойку
	int stamin_in=0; // Входное число выносливости выбранное пользователем
	string  call_state_1, call_state_2, call_state_3;
	State(int Id, string V, int T, int  SC, int SM, double D, double time, string Call1, string Call2, string Call3) // Инициализация стойки
	{
		id = Id;
		for (int i; i <= 10; i++)
		{
			vaible[i] =V[i];
		}
		type = T; 
		stamin_cost = SC; 
		stamin_max = SM;
		damage = D;
		time_to_state = time;
		call_state_1 = Call1;
		call_state_2 = Call2;
		call_state_3 = Call3;
	}
	void Call_state_work(int Enemy_strength,int Enemy_constitution,int Enemy_dexterity,int Enemy_wisdom,int Enemy_intellect,int *Enemy_blood_s,int *Enemy_stamina_s, int Strength, int Constitution,int Dexterity,int Wisdom,int Intellect,int *Blood,int *Stamina)
	{
		switch (type)
		{
		case 0: //Срабатывание стойки замаха
			cout << "Сколько вкладываем силы? Максимум силы - " << stamin_max << '\n';
repeat:		cout << "Вкладываем: ";
			cin >> stamin_in;
			double fix_time = global_time;
			if (stamin_in <= stamin_max)
			{
				while (global_time - fix_time < time_to_state) //пока стойка не завершится, происходит проверка
				{


				}
			}
			else
			{
				cout << "Вы ввели что-то не то! Введите число от 0 до " << stamin_max;
				goto repeat;
			}
		case 1: //Срабатывание стойки удара

		case 2: //Срабатывание защитной стойки

		case 3: //Срабатывание блока

		}
	}
	void Call_state_1() // Вызов описания текущей стойки
	{
		cout << call_state_1;
	}
	void Call_state_2() // Вызов описания стойки в которые можно перейти
	{
		cout << call_state_2;
	}
	void Call_state_2()// Вызов описания протекающей стойки
	{
		cout << call_state_3;
	}
	
}; 
State Non_battle_0(0, "0100010000", 0, 0, 0, 0, 2.5, " в небоевой стойке.", "Перейти в небоевую стойку.", " переходит в небоевую стойку."); //Небоевая стойка с оружием в ножнах
State In_batle_1(1, "1011111000", 0, 1, 0, 0.25, 1.0, " вынул оружие и держит опущенным.", "Вынуть оружие.", " вынимает оружие."); //Боевая стойка с оружием на готове
State Z_hit_k_2(2, "1101101000", 0, 10,100, 0.5, 0.7, " замахнулся для колющего удара.", "Замахнуться для колющего удара.", " замахивается для колющего удара."); //Замах на колющий удар
State Z_hit_r_3(3, "111001000", 0, 10, 100, 0.5, 0.7, " замахнулся для режущего удара.", "Замахнуться для режущего удара.", " замахивается для режущего удара."); //Замах на режущий удар
State Hit_k_4(4, "0000000011", 1, 20, 100, 0.5, 0.3, " совершает колющий удар!", "Нанести колющий удар.", " совершает колющий удар!"); //Колющий удар
State Hit_k_5(5, "0000000110", 1, 20, 100, 0.5, 0.3, " совершает режущий удар!", "Нанести режущий удар.", " совершает режущий удар!"); //Режущий удар
State Deff_6(6, "1111110100", 2, 5, 300, 0.3, 0.5, " принял защитную стойку.","Принять защитную стойку.", " принимает защитную стойку."); //Защитная стойка
State X_weapon_7(7, "0111001000", 3, 0, 500, 0.3, 0, " скрестил меч с мечом противника.", "Пасхалочка","Пасхалочка"); //Скрещенные мечи
State Block_hit_def_8(8, "011111000", 3, 0, 200, 0.6, 0, " отбил удар противника.", "Пасхалочка", "Пасхалочка");//Стойка отбитого удара(отбивающий)
State Block_hit_att_9(9, "011100100", 3, 0, 200, 0, 0," не смог нанести удар, противник отбил его!","Пасхалочка", "Пасхалочка");//Стойка отбитого удара(атакющий)
State mass_state[10] = {Non_battle_0,In_batle_1,Z_hit_k_2,Z_hit_r_3,Hit_k_4,Hit_k_5,Deff_6,X_weapon_7,Block_hit_def_8,Block_hit_att_9}; // массив стоек
 	
	
