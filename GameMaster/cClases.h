#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

class cClases
{
	int HP;
	int AT;

public:
	cClases();
	cClases(int hp, int at);

	void setHp(int hp);

	virtual int Ataque() = 0;
	virtual int RecibirAtaque(int Dano) = 0;
	
	int getHP() { return HP; }
	int getAT() { return AT; }

	~cClases();
};

