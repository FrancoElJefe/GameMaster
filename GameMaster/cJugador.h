#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include "cLista.h"
#include "cTropaArquero.h"
#include "cTropaCaballero.h"
#include "cTropaMago.h"
#include "cPais.h"

using namespace std;

class cJugador
{
	string nombre;
	cLista<cTropaArquero> * ListaTropaArqueros;
	cLista<cTropaCaballero> * ListaTropaCaballeros;
	cLista<cTropaMago> * ListaTropaMagos;
	cLista<cPais> * listaPropiaPaises;

public:
	cJugador();
	cJugador(string nomb);

	void AgregarTropaArquero(cTropaArquero*ptr, int n);
	void AgregarTropaCaballero(cTropaCaballero*ptr, int n);
	void AgregarTropaMago(cTropaMago*ptr, int n);
	cPais *DevolverPais(int p);
	void setTropaEnPais(void);
	void quitarPais(string pais);

	string AtacarPais();
	
	int AgregarPais(cPais *ptr);

	string getNombre() { return nombre; }

	void listarSusPaises(); // funcion de prueba
	void listarTropas(); //funcion de prueba
	void setTropasEnPaisesPrueba(int caballeros, int arqueros, int magos);//funcion de prueba

	~cJugador();
};

