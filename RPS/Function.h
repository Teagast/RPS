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
int dice;
bool check(int variable1, int variable2) // Проверка двух атрибутов
{
	srand(time(NULL));
	dice = rand() % 100;
	variable1 *= 10;
	variable2 *= 10;
	if (variable1 > variable2)
		return(true);
	else  return (false); 
}

