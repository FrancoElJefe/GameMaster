#include "cUnidadArquero.h"



cUnidadArquero::cUnidadArquero():cClases(80,30)
{
}

cUnidadArquero::cUnidadArquero(int hp, int at) : cClases(hp, at)
{
}

int cUnidadArquero::Ataque()
{
	return cClases::getAT();
}

int cUnidadArquero::RecibirAtaque(int Dano)
{
	int HP = 0;

	HP = cClases::getHP();

	cClases::setHp(HP - Dano);

	return (HP - Dano);
	
}


cUnidadArquero::~cUnidadArquero()
{
}
