#include "cPais.h"


cPais::cPais()
{
}

cPais::cPais(string nomb) : nombre(nomb)
{
	vecinos = new cLista<cPais>();
	ListaTropasArquero = new cLista<cTropaArquero>;
	ListaTropasCaballeros = new cLista<cTropaCaballero>;
	ListaTropasMago = new cLista<cTropaMago>;
}

void cPais::AgregarTropaCaballero(cTropaCaballero * ptr)
{
	ListaTropasCaballeros->AgregarItem(ptr);
}

void cPais::AgregarTropaArquero(cTropaArquero * ptr)
{
	ListaTropasArquero->AgregarItem(ptr);
}

void cPais::AgregarTropaMago(cTropaMago * ptr)
{
	ListaTropasMago->AgregarItem(ptr);
}

void cPais::AgregarVecinos(cPais * ptr)
{
	vecinos->AgregarItem(ptr);
}


void cPais::PrintA()
{
	cout << nombre << endl;

	vecinos->ListarV();
	
}

void cPais::PrintNombre()
{
	cout << "-" << nombre << endl;
}

cPais::~cPais()
{
	
	delete ListaTropasCaballeros;
	delete ListaTropasArquero;
	delete ListaTropasMago;
}
