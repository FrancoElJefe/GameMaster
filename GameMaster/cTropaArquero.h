#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <ostream>
#include <time.h>
#include "cUnidadArquero.h"
#include "cLista.h"

using namespace std;

class cTropaArquero
{
	int ATtropa;
	cLista<cUnidadArquero> * listaUnidades;
	static string nombre;
	static HANDLE consoleHandle;

public:
	cTropaArquero();

	void AgregarUnidades(int n);

	int Ataque();
	int RecibirAtaqueTropa(int dano, string clase);
	
	void PrintA();//funcion de prueba

	~cTropaArquero();
};

