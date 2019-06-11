#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cUnidadArquero.h"
#include "cLista.h"

using namespace std;

class cTropaArquero
{
	int ATtropa;
	cLista<cUnidadArquero> * listaUnidades;
	static string nombre;

public:
	cTropaArquero();

	void AgregarUnidades(cUnidadArquero*ptr);
	int Ataque();
	int RecibirAtaqueTropa(int dano, string clase);


	void PrintA();//funcion de prueba

	~cTropaArquero();
};

