#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cClases.h"

using namespace std;

class cUnidadArquero : cClases
{

public:
	cUnidadArquero();
	cUnidadArquero(int hp, int at);

	virtual int Ataque();
	virtual int RecibirAtaque(int Dano);

	int getHP() { return cClases::getHP(); }

	~cUnidadArquero();
};

