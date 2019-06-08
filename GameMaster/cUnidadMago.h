#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cClases.h"

using namespace std;

class cUnidadMago : public cClases
{
public:
	cUnidadMago();
	cUnidadMago(int hp, int at);

	virtual int Ataque();
	virtual int RecibirAtaque(int Dano);

	int getHP() { return cClases::getHP(); }

	~cUnidadMago();
};

