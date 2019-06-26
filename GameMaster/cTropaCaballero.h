#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include <windows.h>
#include <time.h>
#include "cUnidadCaballero.h"
#include "cLista.h"

using namespace std;

class cTropaCaballero
{
	int ATtropa;
	cLista<cUnidadCaballero> * listaUnidades;
	static string nombre;
	static HANDLE consoleHandle;

public:
	cTropaCaballero();

	void AgregarUnidades(int N);
	void AgregarUnidades(cUnidadCaballero * ptr);
	int Ataque();
	int RecibirAtaqueTropa(int dano, string clase);

	int getCUnidades() { return listaUnidades->getCA(); }

	cUnidadCaballero * CombinacionDeTropas();
	


	void PrintA();//funcion de prueba

	~cTropaCaballero();
};

