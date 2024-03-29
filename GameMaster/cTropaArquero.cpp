#include "cTropaArquero.h"

HANDLE cTropaArquero::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

string cTropaArquero::nombre = "ARQUERO";

cTropaArquero::cTropaArquero()
{
	srand(time(NULL));//inicializo los numeros random
	listaUnidades = new cLista<cUnidadArquero>;
}

void cTropaArquero::AgregarUnidades(int n)
{
	int HP = 0, AT = 0;

	for (int k = 0; k < n; k++)
	{
		HP = 60 + rand() % (81 - 60);
		AT = 20 + rand() % (31 - 20);
		listaUnidades->AgregarItem(new cUnidadArquero(HP,AT));
	}
}
void cTropaArquero::AgregarUnidades(cUnidadArquero * ptr)
{
	listaUnidades->AgregarItem(ptr);
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
	int aux=0, TropasOriginales=0;
	
	listaUnidades->OrdenarPorHp(); //ordena de menor a mayor dependiendo de su HP

	if (clase == "MAGO" || clase == "Mago" || clase == "mago") //si el ataque proviene de un mago, el ataque pierde 25% ya que arquero es fuerte contra mago
	{
		dano = dano - (25 * dano) / 100;
	}
	else if (clase == "CABALLERO" || clase == "Caballero" || clase == "caballero") //si el ataque proviene de un caballero, el ataque gana 25% ya que caballero es fuerte contra arquero
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
		cout << "Tropa de arqueros Eliminada" << endl;
		cout << "\t--------------------------------------" << endl << endl;
		return(0);
	}
	else
	{
		cout << "se eliminaron " << TropasOriginales - listaUnidades->getCA() << " arqueros"<< endl;
		cout << "\t--------------------------------------" << endl << endl;
		SetConsoleTextAttribute(consoleHandle, 7);
		return(1);
	}

}


cUnidadArquero * cTropaArquero::CombinacionDeTropas()
{
	return listaUnidades->QuitarenPos(0);
}

void cTropaArquero::PrintA()
{
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
	cout << nombre;
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ": ";
	SetConsoleTextAttribute(consoleHandle, 6);
	cout << listaUnidades->getCA() << " unidades" << endl;
	SetConsoleTextAttribute(consoleHandle, 7);
}

cTropaArquero::~cTropaArquero()
{
	delete listaUnidades;
}
