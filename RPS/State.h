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
class State // ����� ������
{
public:
	int id; // ������������� ������
	bool vaible[10]; //��������� ������
	int type; // ��� ������: 0-������-�����; 1-������-����; 2-�������� ������; 3-������ ����
	int stamin_cost; // �-�� ����������� ������������ �� ������
	int stamin_max; // �-�� ������������, ������� ����� ��������� �� ������ �������������
	double damage; // ����������� ����� ������
	double time_to_state; // ����� ��� �������� � ������
	int stamin_in=0; // ������� ����� ������������ ��������� �������������
	string  call_state_1, call_state_2, call_state_3;
	State(int Id, string V, int T, int  SC, int SM, double D, double time, string Call1, string Call2, string Call3) // ������������� ������
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
		case 0: //������������ ������ ������
			cout << "������� ���������� ����? �������� ���� - " << stamin_max << '\n';
repeat:		cout << "����������: ";
			cin >> stamin_in;
			double fix_time = global_time;
			if (stamin_in <= stamin_max)
			{
				while (global_time - fix_time < time_to_state) //���� ������ �� ����������, ���������� ��������
				{


				}
			}
			else
			{
				cout << "�� ����� ���-�� �� ��! ������� ����� �� 0 �� " << stamin_max;
				goto repeat;
			}
		case 1: //������������ ������ �����

		case 2: //������������ �������� ������

		case 3: //������������ �����

		}
	}
	void Call_state_1() // ����� �������� ������� ������
	{
		cout << call_state_1;
	}
	void Call_state_2() // ����� �������� ������ � ������� ����� �������
	{
		cout << call_state_2;
	}
	void Call_state_2()// ����� �������� ����������� ������
	{
		cout << call_state_3;
	}
	
}; 
State Non_battle_0(0, "0100010000", 0, 0, 0, 0, 2.5, " � �������� ������.", "������� � �������� ������.", " ��������� � �������� ������."); //�������� ������ � ������� � ������
State In_batle_1(1, "1011111000", 0, 1, 0, 0.25, 1.0, " ����� ������ � ������ ���������.", "������ ������.", " �������� ������."); //������ ������ � ������� �� ������
State Z_hit_k_2(2, "1101101000", 0, 10,100, 0.5, 0.7, " ���������� ��� �������� �����.", "����������� ��� �������� �����.", " ������������ ��� �������� �����."); //����� �� ������� ����
State Z_hit_r_3(3, "111001000", 0, 10, 100, 0.5, 0.7, " ���������� ��� �������� �����.", "����������� ��� �������� �����.", " ������������ ��� �������� �����."); //����� �� ������� ����
State Hit_k_4(4, "0000000011", 1, 20, 100, 0.5, 0.3, " ��������� ������� ����!", "������� ������� ����.", " ��������� ������� ����!"); //������� ����
State Hit_k_5(5, "0000000110", 1, 20, 100, 0.5, 0.3, " ��������� ������� ����!", "������� ������� ����.", " ��������� ������� ����!"); //������� ����
State Deff_6(6, "1111110100", 2, 5, 300, 0.3, 0.5, " ������ �������� ������.","������� �������� ������.", " ��������� �������� ������."); //�������� ������
State X_weapon_7(7, "0111001000", 3, 0, 500, 0.3, 0, " �������� ��� � ����� ����������.", "����������","����������"); //���������� ����
State Block_hit_def_8(8, "011111000", 3, 0, 200, 0.6, 0, " ����� ���� ����������.", "����������", "����������");//������ �������� �����(����������)
State Block_hit_att_9(9, "011100100", 3, 0, 200, 0, 0," �� ���� ������� ����, ��������� ����� ���!","����������", "����������");//������ �������� �����(��������)
State mass_state[10] = {Non_battle_0,In_batle_1,Z_hit_k_2,Z_hit_r_3,Hit_k_4,Hit_k_5,Deff_6,X_weapon_7,Block_hit_def_8,Block_hit_att_9}; // ������ �����
 	
	
