#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <ostream>
#include <windows.h>
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
	static HANDLE consoleHandle;

	void ImprimirMapa(void);

public:
	cJugador();
	cJugador(string nomb);

	void AgregarTropaArquero(cTropaArquero*ptr, int n);
	void AgregarTropaCaballero(cTropaCaballero*ptr, int n);
	void AgregarTropaMago(cTropaMago*ptr, int n);
	void setTropaEnPais(void);

	//cPais *DevolverPais(int p);
	
	string AtacarPais();
	
	int AgregarPais(cPais *ptr);
	cPais* quitarPais(string pais);

	string getNombre() { return nombre; }
	int getNumeroDePaises() { return listaPropiaPaises->getCA(); }
		
	void listarSusPaises(); // funcion de prueba
	void listarTropas(); //funcion de prueba
	void setTropasEnPaisesPrueba(int caballeros, int arqueros, int magos);//funcion de prueba

	~cJugador();
};

