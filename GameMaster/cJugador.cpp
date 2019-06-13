#include "cJugador.h"



cJugador::cJugador()
{
	nombre = "";
	ListaTropaArqueros = new cLista<cTropaArquero>;
	ListaTropaCaballeros = new cLista<cTropaCaballero>;
	ListaTropaMagos = new cLista<cTropaMago>;
	listaPropiaPaises = new cLista<cPais>(9);
}

cJugador::cJugador(string nomb) : cJugador()
{
	nombre = nomb;
}

void cJugador::AgregarTropaArquero(cTropaArquero * ptr, int n)
{
	ptr->AgregarUnidades(n);
	ListaTropaArqueros->AgregarItem(ptr);
}

void cJugador::AgregarTropaCaballero(cTropaCaballero * ptr, int n)
{
	ptr->AgregarUnidades(n);
	ListaTropaCaballeros->AgregarItem(ptr);
}

void cJugador::AgregarTropaMago(cTropaMago * ptr, int n)
{
	ptr->AgregarUnidades(n);
	ListaTropaMagos->AgregarItem(ptr);
}

cPais * cJugador::DevolverPais(int p)
{
	return listaPropiaPaises->getItem(p);
}

void cJugador::setTropaEnPais(void)
{
	unsigned int opc = 0;
	int opc3=0, Tropas;
	string opc2;
	cPais * pais;

	Tropas = ListaTropaArqueros->getCA() + ListaTropaCaballeros->getCA() + ListaTropaMagos->getCA();	
	do
	{

		
		cout << "\t\tDISTRIBUYE LAS TROPAS EN TUS PAISES" << endl << endl;
		cout << "---------" << endl;
		cout << nombre << endl;
		cout << "---------" << endl << endl;
		listaPropiaPaises->ListarV();
		cout << endl;
		cout << "Seleccione el Pais que quiera agregar: ";
		cin >> opc;

		if (opc <= listaPropiaPaises->getCA()) {

			pais = listaPropiaPaises->getItem(opc - 1);
			opc = 0;
			do
			{
				system("cls");
				ListaTropaCaballeros->Listar();
				cout << endl;
				ListaTropaArqueros->Listar();
				cout << endl;
				ListaTropaMagos->Listar();
				cout << endl;
				cout << "Escriba la clase de tropa que desee: ";
				cin >> opc2;

				if (opc2 == "CABALLERO" || opc2 == "Caballero" || opc2 == "caballero" || opc2 == "ARQUERO" || opc2 == "Arquero" || opc2 == "arquero" || opc2 == "MAGO" || opc2 == "Mago" || opc2 == "mago")
				{
					opc = 1;
				}

			} while (opc != 1);

			if (opc2 == "CABALLERO" || opc2 == "Caballero" || opc2 == "caballero")
			{
				ListaTropaCaballeros->Listar();
				cout << "Seleccione la tropa que desea agregar en " << pais->getCodigo() << ": ";
				cin >> opc3;
				pais->AgregarTropaCaballero(ListaTropaCaballeros->getItem(opc3 - 1));
				ListaTropaCaballeros->QuitarenPos(opc3 - 1);
			}
			else
			{

				if (opc2 == "ARQUERO" || opc2 == "Arquero" || opc2 == "arquero")
				{
					ListaTropaArqueros->Listar();
					cout << "Seleccione la tropa que desea agregar en " << pais->getCodigo() << ": ";
					cin >> opc3;
					pais->AgregarTropaArquero(ListaTropaArqueros->getItem(opc3 - 1));
					ListaTropaArqueros->QuitarenPos(opc3 - 1);
				}
				else
				{
					if (opc2 == "MAGO" || opc2 == "Mago" || opc2 == "mago")
					{
						ListaTropaMagos->Listar();
						cout << "Seleccione la tropa que desea agregar en " << pais->getCodigo() << ": ";
						cin >> opc3;
						pais->AgregarTropaMago(ListaTropaMagos->getItem(opc3 - 1));
						ListaTropaMagos->QuitarenPos(opc3 - 1);
					}
				}
			}

			cout << endl;
			cout << pais->getCodigo();
			cout << endl;
			pais->PrintTropas();
			system("pause");
			Tropas--;
		}

		system("cls");

	} while (Tropas != 0);

}

void cJugador::AtacarPais()
{
	unsigned int opcion = 0;
	cPais * pais;

	listaPropiaPaises->ListarV();

	cout << "Seleccione el pais con el que queres atacar" << endl;
	cout << "Pais: ";
	cin >> opcion;

	pais = listaPropiaPaises->getItem(opcion-1);
	pais->AtacarOtroPais(nombre);

	   
}

int cJugador::AgregarPais(cPais * ptr)
{
	cPais * pais;

	for (int i = 0; i < listaPropiaPaises->getCA(); i++)
	{
		pais = listaPropiaPaises->getItem(i);

		if (ptr->getCodigo() == pais->getCodigo())
		{
			return 1;
		}

	}

	listaPropiaPaises->AgregarItem(ptr);

	return 0;
}


void cJugador::listarSusPaises()
{
	listaPropiaPaises->Listar();
}

void cJugador::listarTropas()
{
	cout << "Tropas de Caballeros" << endl;

	ListaTropaCaballeros->Listar();

	cout << "Tropas de Arqueros" << endl;

	ListaTropaArqueros->Listar();

	cout << "Tropas de Caballeros" << endl;

	ListaTropaMagos->Listar();

}

cJugador::~cJugador()
{
	if (ListaTropaCaballeros->getCA() !=0)
	{
		delete ListaTropaCaballeros;
	}

	if (ListaTropaArqueros->getCA() != 0)
	{
		delete ListaTropaArqueros;
	}

	if (ListaTropaMagos->getCA() != 0)
	{
		delete ListaTropaMagos;
	}

	}
	
	
	
