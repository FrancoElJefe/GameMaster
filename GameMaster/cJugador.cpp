#include "cJugador.h"



cJugador::cJugador()
{
	nombre = "";
	ListaTropaArqueros = new cLista<cTropaArquero>;
	ListaTropaCaballeros = new cLista<cTropaCaballero>;
	ListaTropaMagos = new cLista<cTropaMago>;
	listaPropiaPaises = new cLista<cPais>(8);
}

cJugador::cJugador(string nomb) : cJugador()
{
	nombre = nomb;
}

void cJugador::AgregarTropaArquero(cTropaArquero * ptr)
{
	ListaTropaArqueros->AgregarItem(ptr);
}

void cJugador::AgregarTropaCaballero(cTropaCaballero * ptr)
{
	ListaTropaCaballeros->AgregarItem(ptr);
}

void cJugador::AgregarTropaMago(cTropaMago * ptr)
{
	ListaTropaMagos->AgregarItem(ptr);
}


cJugador::~cJugador()
{
	delete ListaTropaArqueros;
	delete ListaTropaCaballeros;
	delete ListaTropaMagos;
}
