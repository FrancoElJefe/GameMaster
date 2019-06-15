#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <ostream>
#include "cLista.h"
#include "cTropaCaballero.h"
#include "cTropaArquero.h"
#include "cTropaMago.h"


using namespace std;

class cPais
{
	const string nombre;
	int jugador;
	cLista<cTropaCaballero> * ListaTropasCaballeros;
	cLista<cTropaArquero> * ListaTropasArquero;
	cLista<cTropaMago> * ListaTropasMago;
	static cLista<cPais> * listaPaises;
	cLista<cPais> * vecinos;

public:
	
	cPais();
	cPais(string nomb);

	void AgregarTropaCaballero(cTropaCaballero *ptr);
	void AgregarTropaArquero(cTropaArquero *ptr);
	void AgregarTropaMago(cTropaMago *ptr);

	void AgregarVecinos(cPais * ptr);

	void setJugador(string jug);

	string AtacarOtroPais(string nomb); //Yo Ataco
	int Atacado(int ntropa, int dano, string claseTAtacada, string claseTAtacante);  //Recibo Ataque

	int getNjugador() { return jugador; }
	const string getCodigo() { return nombre; }
	int getCantidadDeTropas() { return (ListaTropasArquero->getCA() + ListaTropasCaballeros->getCA() + ListaTropasMago->getCA()); }
	int getCantTarquro() { return ListaTropasArquero->getCA(); }
	int getCantTcaballero() { return ListaTropasCaballeros->getCA(); }
	int getCantTMago() { return ListaTropasMago->getCA(); }

	void PrintA(); // mostrar nombre de paises
	void PrintTropas();//funcion de prueba
	void printTodos();//funcion de prueba
		
	void PrintNombre();
	void PrintTropasCaballero();
	void PrintTropasArquero();
	void PrintTropasMago();
	~cPais();
};

/*
paises:

-argentina : chile, uruguay, brasil y peru
-brasil : uruguay, argentina, peru y colombia
-peru : colombia, brasil, argintina, chile
-colombia : peru, brasil y mexico 
-chile : peru, argentina y groenlandia
-uruguay : argentina y brasil
-canada : terranova , nueva york, oregon y yukon
- nueva york : terranova, canada , oregon y california
-yukon : alaska, canada y oregon
-alaska : yukon y oregon
-groenlandia : labrador, nueva york y chile
-oregon : yukon, alaska, canada, nueva york y california
-california : nueva york, oregon y mexico
-mexico : california y colombia
-teranova : labrador, canada y nueva york
-labrador : groenlandia y terranova

*/