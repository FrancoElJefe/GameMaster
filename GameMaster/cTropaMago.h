#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cUnidadMago.h"
#include "cLista.h"

using namespace std;

class cTropaMago
{
	int ATtropa;
	cLista<cUnidadMago> * listaUnidades;
	static string nombre;

public:
	cTropaMago();

	void AgregarUnidades(cUnidadMago*ptr);
	int Ataque();
	int RecibirAtaqueTropa(int dano, string clase);

	~cTropaMago();
};

