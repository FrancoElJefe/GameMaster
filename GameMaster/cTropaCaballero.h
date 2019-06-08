#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cUnidadCaballero.h"
#include "cLista.h"

using namespace std;

class cTropaCaballero
{
	int ATtropa;
	cLista<cUnidadCaballero> * listaUnidades;
	static string nombre;

public:
	cTropaCaballero();

	void AgregarUnidades(cUnidadCaballero*ptr);
	int Ataque();
	int RecibirAtaqueTropa(int dano, string clase);

	~cTropaCaballero();
};

