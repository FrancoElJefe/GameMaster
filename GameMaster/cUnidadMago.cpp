#include "cUnidadMago.h"



cUnidadMago::cUnidadMago() :cClases(60, 20)
{
}

cUnidadMago::cUnidadMago(int hp, int at) : cClases(hp, at)
{
}

int cUnidadMago::Ataque()
{
	return cClases::getAT();
}

int cUnidadMago::RecibirAtaque(int Dano)
{
	int HP = 0;

	HP = cClases::getHP();

	cClases::setHp(HP - Dano);

	return (HP - Dano);
}


cUnidadMago::~cUnidadMago()
{
}
