#pragma once
#include "targetver.h"
#include "iostream"
#include "Player.h"
#include "Enemy.h"
#include "Function.h"
#include "State.h"
#include"stdafx.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <regex>   
#include <fstream>
using namespace std;
class Enemy
{
public:
	int dexterity;
	int strength;
	int constitution;
	int intellect;
	int wisdom;
	int blood;
	int stamina;
	int left_arm_weapon;
	int right_arm_weapon;
	int state_now;
	int state_new;
	string name;
	Enemy(int D, int S, int C, int I, int W, int LA, int RA, string Name)
	{
		dexterity = D;
		strength = S;
		constitution = C;
		intellect = I;
		wisdom = W;
		left_arm_weapon = LA;
		right_arm_weapon - RA;
		name = Name;
		blood = 1000 + constitution * 100;
		stamina = 1000 + constitution * 100;
		state_now = 0;
	}
	void Turn()
	{

	}
};