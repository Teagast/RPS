// RPS.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Player.h"

using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	int D, S, C, I, W, B, St, LA, RA;
	string name;
	cout << "������� ��������� ��������� 1\n";
	cout << "��������=";
	cin >> D;
	cout << "����=";
	cin >> S;
	cout << "������������=";
	cin >> C;
	cout << "���������=";
	cin >> I;
	cout << "��������=";
	cin >> W;
	cout << "��� ���������-";
	cin >> name;
	cout << "��� ������ ������ ����? 0- �����, 1- ���. ������=";
	cin >> RA;
	cout << "��� ������ ����� ����? 0- �����, 1- ���. �����=";
	cin >> LA;
	Player Player1(D, S, C, I, W, LA, RA, name);
	system("cls");
	cout << "������� ������� ���������. \n";
	system("pause");
	cout << "��������=";
	cin >> D;
	cout << "����=";
	cin >> S;
	cout << "������������=";
	cin >> C;
	cout << "���������=";
	cin >> I;
	cout << "��������=";
	cin >> W;
	cout << "��� ���������-";
	cin >> name;
	cout << "��� ������ ������ ����? 0- �����, 1- ���. ������=";
	cin >> RA;
	cout << "��� ������ ����� ����? 0- �����, 1- ���. �����=";
	cin >> LA;
	Player Player2(D, S, C, I, W, LA, RA, name);


}

