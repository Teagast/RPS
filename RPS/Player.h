#pragma once
#include <string>
using namespace std;
class Player
{
public:
	int Dexterity;
	int Strength;
	int Constitution;
	int Intellect;
	int Wisdom;
	int Blood;
	int Stamina;
	int Left_Arm;
	int Right_Arm;
	int State;
	string Name;
	Player(int D, int S, int C, int I, int W, int LA, int RA, string name)
	{
		Dexterity = D;
		Strength = S;
		Constitution = C;
		Intellect = I;
		Wisdom = W;
		Left_Arm = LA;
		Right_Arm - RA;
		Name = name;
		Blood = 1000 + Constitution * 100;
		Stamina = 1000 + Constitution * 100;
		State = 0;
	}


	

};

