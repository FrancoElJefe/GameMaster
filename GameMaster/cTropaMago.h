#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include <time.h>
#include <windows.h>
#include "cUnidadMago.h"
#include "cLista.h"

using namespace std;

class cTropaMago
{
	int ATtropa;
	cLista<cUnidadMago> * listaUnidades;
	static string nombre;
	static HANDLE consoleHandle;

public:
	cTropaMago();

	void AgregarUnidades(int n);
	void AgregarUnidades(cUnidadMago * ptr);

	int Ataque();
	int RecibirAtaqueTropa(int dano, string clase);

	int getCUnidades() { return listaUnidades->getCA(); }

	cUnidadMago * CombinacionDeTropas();

	void PrintA();//funcion de prueba

	~cTropaMago();
};

