#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cLista.h"
#include "cTropaCaballero.h"
#include "cTropaArquero.h"
#include "cTropaMago.h"
#include "cUnidadCaballero.h"
#include "cUnidadArquero.h"
#include "cUnidadMago.h"

using namespace std;

class cPais
{
	const string nombre;
	cLista<cTropaCaballero> * ListaTropasCaballeros;
	cLista<cTropaArquero> * ListaTropasArquero;
	cLista<cTropaMago> * ListaTropasMago;

	static cLista<cPais> * listaPaises;
	cLista<cPais> * vecinos;

public:
	cPais();

	void AgregarTropaCaballero(cUnidadCaballero *ptr);
	void AgregarTropaArquero(cUnidadArquero *ptr);
	void AgregarTropaMago(cUnidadMago *ptr);

	~cPais();
};

