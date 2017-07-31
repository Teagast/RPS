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
		int dexterity; //��������
		int strength; //����
		int constitution; //������������
		int intellect; //���������
		int wisdom; //��������
		int blood; //�����
		int stamina; //������������
		int left_arm_weapon; // ������ ������ ����
		int right_arm_weapon; // ������ ����� ����
		int state_now; // ������� ������
		int state_new; // ���������� ������
		string name; // ��� ���������
		vector <int> state_id; // ������ ��������������� �����, ������� ����� ��������
	Player(int D, int S, int C, int I, int W, int LA, int RA, string Name) // �������� ���������
	{
		
		dexterity = D;
		strength = S;
		constitution = C;
		intellect = I;
		wisdom = W;
		left_arm_weapon = LA;
		right_arm_weapon - RA;
		name = Name;
		blood = 1000 + constitution * 100; // ����� ����� 1000+����*100
		stamina = 10000 +constitution * 100;
		state_now = 0; // ��������� ������ � ������� � ������
		state_id.push_back(0); //��� ����� ������ � ������� � ������
		state_id.push_back(1); //��� ����� ������ � ������� � �����
		state_id.push_back(2); //��� ����� ������������ ������� ��� �������� �����
		state_id.push_back(3); //��� ����� ������������ ������� ��� �������� �����
		state_id.push_back(4); //��� ����� ������ ������� ����
		state_id.push_back(5); //��� ����� ������ ������� ����
		state_id.push_back(6); //��� ����� �������� � �������� ������
		state_id.push_back(7); //��� ����� � ���������� ����
		state_id.push_back(8); //��� ����� � ������ �������� �����(����������)
		state_id.push_back(9); //��� ����� � ������ �������� �����(���������)
	}
	void Turn(Enemy &En) //��� ������
	{
		vector <int> state_buff; // ������������� �������� ����� ��� ������
		int j; // ���������� ��� �������� ������������� �����
repeat:	cout << name; 
		mass_state[state_now].Call_state_1(); // ������� ������� ������
		cout << '\n';
		cout << "�������� ��������:";
		for (int i = 0; i < 10; i++) // ������� ��� ��������� ������
		{
			if ((mass_state[state_now].vaible[i])&&(state_id[i])) // � ������ ������ ���� ����������� ������� �� ������� � � ������ ����� ��������
			{
				cout << j << ". ";
				mass_state[i].Call_state_2();
				cout << '\n';
				state_buff.push_back(mass_state[i].id);
				j++;
			}
		}
		cout << "�������� ��������: ";
		cin >> state_new; // ������ ����� ������
		state_new = state_buff[state_new];
		int enemy_dexterity = En.dexterity, enemy_strength=En.strength, enemy_constitution=En.constitution,enemy_wisdom=En.wisdom,enemy_intellect=En.intellect;// ��������� ������� �� ������ ���� �������� �������� � ������� ����� �����
		int *enemy_blood_s = &En.blood;//������� �� �������� ����� ��� ��� ���������
		int *enemy_stamina_s= &En.stamina;// ��������� �� �������� ������������ ��� ��� ���������
		int *blood_s = &blood;//��������� �� ����� ������
		int *stamina_s = &stamina;// ��������� �� ������������ ������
		if (mass_state[state_now].vaible[state_new]) // �������� ������ ����� � ������
		{
			system("cls");
			mass_state[state_new].Call_state_work(enemy_strength,enemy_constitution,enemy_dexterity,enemy_wisdom,enemy_intellect,enemy_blood_s,enemy_stamina_s,
				strength,constitution,dexterity,wisdom,intellect,blood_s,stamina_s); // �������� ������������ ������
		}
		else 
		{
			cout << "\n�� ����� ���-�� �� ��!" << '\n';
			goto repeat;
		};
	}

	

};



