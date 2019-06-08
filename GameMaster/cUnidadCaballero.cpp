#include "cUnidadCaballero.h"



cUnidadCaballero::cUnidadCaballero() :cClases(100, 40)
{
}

cUnidadCaballero::cUnidadCaballero(int hp, int at) : cClases(hp, at)
{
}

int cUnidadCaballero::Ataque()
{
	return cClases::getAT();
}

int cUnidadCaballero::RecibirAtaque(int Dano)
{
	int HP = 0;

	HP = cClases::getHP();

	return (HP - Dano);
}


cUnidadCaballero::~cUnidadCaballero()
{
}
