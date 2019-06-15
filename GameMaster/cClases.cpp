#include "cClases.h"



cClases::cClases()
{
	HP = 0;
	AT = 0;
}

cClases::cClases(int hp, int at):cClases()
{
	HP = hp;
	AT = at;
}

void cClases::setHp(int hp)
{
	HP = hp;
}


cClases::~cClases()
{
}
