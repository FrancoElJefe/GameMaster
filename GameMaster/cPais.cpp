#include "cPais.h"


cPais::cPais()
{
	
	jugador = 0;
}

cPais::cPais(string nomb) : nombre(nomb)
{
	vecinos = new cLista<cPais>();
	ListaTropasArquero = new cLista<cTropaArquero>;
	ListaTropasCaballeros = new cLista<cTropaCaballero>;
	ListaTropasMago = new cLista<cTropaMago>;
	jugador = 0;
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

void cPais::setJugador(string jug)
{
	if (jug == "Jugador 1" )
	{
		jugador = 1;
	}	
	else
	{
		jugador = 2;
	}
}

void cPais::AtacarOtroPais(string nomb)
{
	int opcion = 0;
	cPais * PaisParaAtacar;

	cout << endl << "Paises limitrofes para atacar: " << endl;
	vecinos->ListarParaAtacar(nomb);
	cout << endl << "Pais a Atacar: ";
	cin >> opcion;

	PaisParaAtacar = vecinos->AtacarVecino(nomb, opcion);

	cout << endl << "usted eligio atacar al pais: " << PaisParaAtacar->getCodigo() << endl;

	PaisParaAtacar->PrintTropas();

	system("pause");

}


void cPais::PrintA()
{
	cout << nombre << endl;

	vecinos->ListarV();
	
}

void cPais::PrintTropas()
{
	ListaTropasCaballeros->Listar();
	cout << endl;
	ListaTropasArquero->Listar();
	cout << endl;
	ListaTropasMago->Listar();

}

void cPais::PrintNombre()
{
	cout << nombre << endl;
}

cPais::~cPais()
{
	delete ListaTropasCaballeros;
	delete ListaTropasArquero;
	delete ListaTropasMago;
}
