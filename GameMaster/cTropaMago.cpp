#include "cTropaMago.h"

HANDLE cTropaMago::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

string cTropaMago::nombre = "MAGO";

cTropaMago::cTropaMago()
{
	listaUnidades = new cLista<cUnidadMago>;
}

void cTropaMago::AgregarUnidades(int n)
{
	for (int k = 0; k < n; k++)
	{
		listaUnidades->AgregarItem(new cUnidadMago);
	}
}

int cTropaMago::Ataque()
{
	int ATtotal = 0;
	cUnidadMago * unidad;

	for (int i = 0; i < listaUnidades->getCA(); i++) //acumula en una variable el ataque de todas las unidades
	{
		unidad = listaUnidades->getItem(i);

		ATtotal = ATtotal + unidad->Ataque();
	}

	return ATtotal;
}

int cTropaMago::RecibirAtaqueTropa(int dano, string clase)
{
	cUnidadMago * unidad;
	int aux = 0, TropasOriginales=0;

	listaUnidades->OrdenarPorHp(); //ordena de menor a mayor dependiendo de su HP

	if (clase == "CABALLERO" || clase == "Caballero" || clase == "caballero") //si el ataque proviene de un caballero, el ataque pierde 25% ya que mago es fuerte contra caballero
	{
		dano = dano - (25 * dano) / 100;
	}
	else if (clase == "ARQUERO" || clase == "Arquero" || clase == "arquero") //si el ataque proviene de un arquero, el ataque gana 25% ya que arquero es fuerte contra mago
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
		cout << "Tropa de magos Eliminada" << endl;
		cout << "\t--------------------------------------" << endl << endl;
		SetConsoleTextAttribute(consoleHandle, 7);
		return(0);
	}
	else
	{
		cout << "se eliminaron " << TropasOriginales - listaUnidades->getCA() << " magos" << endl;
		cout << "\t--------------------------------------" << endl << endl;
		SetConsoleTextAttribute(consoleHandle, 7);
		return(1);
	}
}


void cTropaMago::PrintA()
{
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
	cout << nombre;
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ": ";
	SetConsoleTextAttribute(consoleHandle, 6); 
	cout << listaUnidades->getCA() << " unidades" << endl; 
	SetConsoleTextAttribute(consoleHandle, 7);
}

cTropaMago::~cTropaMago()
{
	delete listaUnidades;
}
