#include "cTropaCaballero.h"

HANDLE cTropaCaballero::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

string cTropaCaballero::nombre = "CABALLERO";

cTropaCaballero::cTropaCaballero()
{
	srand(time(NULL));//inicializo los numeros random
	listaUnidades = new cLista<cUnidadCaballero>;
}

void cTropaCaballero::AgregarUnidades(int N)
{
	int HP = 0 ,AT = 0;

	for (int k = 0; k < N; k++)
	{
		HP = 80 + rand() % (101 - 80);
		AT = 30 + rand() % (41 - 30);
		listaUnidades->AgregarItem(new cUnidadCaballero(HP,AT));
	}
	
}

int cTropaCaballero::Ataque()
{
	int ATtotal = 0;
	cUnidadCaballero * unidad;

	for (int i = 0; i < listaUnidades->getCA(); i++) //acumula en una variable el ataque de todas las unidades
	{
		unidad = listaUnidades->getItem(i);

		ATtotal = ATtotal + unidad->Ataque();
	}

	return ATtotal;
}

int cTropaCaballero::RecibirAtaqueTropa(int dano, string clase)
{
	cUnidadCaballero * unidad;
	int aux = 0, TropasOriginales = 0;

	listaUnidades->OrdenarPorHp(); //ordena de menor a mayor dependiendo de su HP

	if (clase == "ARQUERO" || clase == "Arquero" || clase == "arquero") //si el ataque proviene de un arquero, el ataque pierde 25% ya que caballero es fuerte contra arquero
	{
		dano = dano - (25 * dano) / 100;
	}
	else if (clase == "MAGO" || clase == "Mago" || clase == "mago") //si el ataque proviene de un mago, el ataque gana 25% ya que mago es fuerte contra caballero
	{
		dano = dano + (25 * dano) / 100;
	}

	TropasOriginales = listaUnidades->getCA();

	for (int i = 0; i < listaUnidades->getCA(); i++)
	{
		unidad = listaUnidades->getItem(i);
		aux = unidad->RecibirAtaque(dano); //si le devuelve un numero negativo quiere decir que mato a la unidad 
										   //por lo cual se debe eliminar de la lista de tropa a la unidad
		if (aux <= 0)
		{
			listaUnidades->Eliminar(i);
			i--;
			aux = aux * (-1);
			dano = aux;
		}
		else
		{
			i = listaUnidades->getCA();
		}
	}

	if (listaUnidades->getCA() == 0) //si la cantidad de unidades en la lista es 0 quiere decir que se mato a la tropa, 
	{								 //jpor lo cual se retorna un 0 para indicar que se debe eliminar la tropa, de lo contrario se retorna un 1
		SetConsoleTextAttribute(consoleHandle, 14);
		cout << "Tropa de caballeros Eliminada" << endl;
		cout << "\t--------------------------------------" << endl << endl;
		return(0);
	}
	else
	{
		SetConsoleTextAttribute(consoleHandle, 14);
		cout << "se eliminaron " << TropasOriginales - listaUnidades->getCA() << " caballeros"<< endl;
		cout << "\t--------------------------------------" << endl << endl;
		SetConsoleTextAttribute(consoleHandle, 7);
		return(1);
		
	}
}

void cTropaCaballero::PrintA()
{
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
	cout << nombre;
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ": ";
	SetConsoleTextAttribute(consoleHandle, 6);
	cout << listaUnidades->getCA() << " unidades" << endl;
	SetConsoleTextAttribute(consoleHandle, 7);
}


cTropaCaballero::~cTropaCaballero()
{
	delete listaUnidades;
}
