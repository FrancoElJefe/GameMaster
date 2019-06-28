#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <ostream>
#include <time.h>
#include <windows.h>
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
	static int Np;
	cLista<cPais> * vecinos;
	static HANDLE consoleHandle;

public:	


	cPais();
	cPais(string nomb);

	void AgregarTropaCaballero(cTropaCaballero *ptr);
	void AgregarTropaArquero(cTropaArquero *ptr);
	void AgregarTropaMago(cTropaMago *ptr);
	cTropaCaballero * quitarTcaballero();
	cTropaArquero * quitarTarquero();
	cTropaMago * quitarTmago();
	void combinarTCaballero(cTropaCaballero * ptr, int Nt);
	void combinarTarquero(cTropaArquero * ptr, int Nt);
	void combinarTmago(cTropaMago * ptr, int Nt);

	void AgregarVecinos(cPais * ptr);

	void setJugador(string jug);

	string AtacarOtroPais(string nomb); //Yo Ataco
	int Atacado(int ntropa, int dano, string claseTAtacada, string claseTAtacante);  //Recibo Ataque
	int ContrataqueDeCaballeros(cTropaArquero* TropaEnemigaA, cTropaCaballero * TropaEnemigaC, cTropaMago * TropaEnemigaM, int Ntropa);

	int getNjugador() { return jugador; }
	const string getCodigo() { return nombre; }
	int getCantidadDeTropas() { return (ListaTropasArquero->getCA() + ListaTropasCaballeros->getCA() + ListaTropasMago->getCA()); }
	int getCantTarquro() { return ListaTropasArquero->getCA(); }
	int getCantTcaballero() { return ListaTropasCaballeros->getCA(); }
	int getCantTMago() { return ListaTropasMago->getCA(); }

	void PrintA(); // mostrar nombre de paises
	void PrintTropas();//funcion de prueba
	void printTodos();//funcion de prueba
		
	void ImprimirMapa(void);
	void PrintNombre();
	void PrintTropasCaballero();
	void PrintTropasArquero();
	void PrintTropasMago();
	void titulo(cPais * paisParaATACAR, int estado, string nombre, int jugador, HANDLE consoleHandle);
	~cPais();
};

/*
paises:

-argentina : chile, uruguay, brasil y peru (4)
-brasil : uruguay, argentina, peru y colombia (4)
-peru : colombia, brasil, argintina, chile (4)
-colombia : peru, brasil y mexico  (3)
-chile : peru, argentina y groenlandia (3)
-uruguay : argentina y brasil (2)
-canada : terranova , nueva york, oregon y yukon  (4)
- nueva york : terranova, canada , oregon y california (4)
-yukon : alaska, canada y oregon (3)
-alaska : yukon y oregon (2)
-groenlandia : labrador, nueva york y chile (3)
-oregon : yukon, alaska, canada, nueva york y california (5)
-california : nueva york, oregon y mexico (3)
-mexico : california y colombia (2)
-teranova : labrador, canada y nueva york (3)
-labrador : groenlandia y terranova (2)

*/