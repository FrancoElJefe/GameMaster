#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cLista.h"
#include "cPais.h"

using namespace std;

class cContinente
{
	const int CantPaises;
	cLista<cPais> * listaPaises;
	const string nombre;

public:
	cContinente();
	cContinente(int N, string nomb);

	int getCaLista() { return listaPaises->getCA(); }

	void AgregarPaises(string * ptr);
	void AsignarVecinos(string nomb, string *ptr, int CV);

	cPais * BuscarPais(int n);
	cPais * BuscarPais(string codigo);

	void ListarPaises();

	~cContinente();
};

