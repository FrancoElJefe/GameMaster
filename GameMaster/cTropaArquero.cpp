#include "cTropaArquero.h"

string cTropaArquero::nombre = "ARQUERO";

cTropaArquero::cTropaArquero()
{
	listaUnidades = new cLista<cUnidadArquero>;
}

void cTropaArquero::AgregarUnidades(int n)
{
	for (int k = 0; k < n; k++)
	{
		listaUnidades->AgregarItem(new cUnidadArquero);
	}
}
int cTropaArquero::Ataque()
{
	int ATtotal=0;
	cUnidadArquero * unidad;

	for (int i = 0; i < listaUnidades->getCA(); i++) //acumula en una variable el ataque de todas las unidades
	{
		unidad = listaUnidades->getItem(i);
		
		ATtotal = ATtotal + unidad->Ataque();
	}

	return ATtotal;
}

int cTropaArquero::RecibirAtaqueTropa(int dano, string clase)
{
	cUnidadArquero * unidad;
	int aux=0;
	
	listaUnidades->OrdenarPorHp(); //ordena de menor a mayor dependiendo de su HP

	if (clase == "MAGO") //si el ataque proviene de un mago, el ataque pierde 25% ya que arquero es fuerte contra mago
	{
		dano = dano - (25 * dano) / 100;
	}
	else if (clase == "CABALLERO") //si el ataque proviene de un caballero, el ataque gana 25% ya que caballero es fuerte contra arquero
	{
		dano = dano + (25 * dano) / 100;
	}

	for (int i = 0; i < listaUnidades->getCA(); i++)
	{
		unidad = listaUnidades->getItem(i);
		aux = unidad->RecibirAtaque(dano); //si le devuelve un numero negativo quiere decir que mato a la unidad 
												  //por lo cual se debe eliminar de la lista de tropa a la unidad
		if (aux < 0)
		{
			listaUnidades->Eliminar(i);
			aux = aux * (-1);
		}
		else
		{
			i = listaUnidades->getCA();
		}
	}

	if (listaUnidades->getCA() == 0) //si la cantidad de unidades en la lista es 0 quiere decir que se mato a la tropa, 
	{								 //jpor lo cual se retorna un 0 para indicar que se debe eliminar la tropa, de lo contrario se retorna un 1
		return(0);
	}
	else
	{
		return(1);
	}

}


void cTropaArquero::PrintA()
{
	cout << nombre << ": " << listaUnidades->getCA() << " unidades" << endl;
}

cTropaArquero::~cTropaArquero()
{
	delete listaUnidades;
}
