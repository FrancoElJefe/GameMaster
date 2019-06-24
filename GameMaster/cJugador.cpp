#include "cJugador.h"

HANDLE cJugador::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

cJugador::cJugador()
{
	nombre = "";
	ListaTropaArqueros = new cLista<cTropaArquero>;
	ListaTropaCaballeros = new cLista<cTropaCaballero>;
	ListaTropaMagos = new cLista<cTropaMago>;
	listaPropiaPaises = new cLista<cPais>(16);
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
/*
cPais * cJugador::DevolverPais(int p)
{
	return listaPropiaPaises->getItem(p);
}
*/
void cJugador::setTropaEnPais(void)
{
	unsigned int opc = 0;
	int opc3=0, Tropas,check=0;
	string opc2;
	cPais * pais;

	

	Tropas = ListaTropaArqueros->getCA() + ListaTropaCaballeros->getCA() + ListaTropaMagos->getCA();	
	do
	{
		system("cls");
		cout << "\t\tDISTRIBUYE LAS TROPAS EN TUS PAISES" << endl << endl;
		cout << "---------" << endl;
		cout << nombre << endl;
		cout << "---------" << endl << endl;
		
		cout << "Tropas: "<< endl;
		ListaTropaCaballeros->Listar();
		cout << endl;
		ListaTropaArqueros->Listar();
		cout << endl;
		ListaTropaMagos->Listar();
		cout << endl;


		listaPropiaPaises->ListarV();
		
		opc = 0; 
		cout << endl;
		cout << "Seleccione el Pais que quiera agregar: ";
		cin.clear();
		cin >> opc;

		if (opc == 0)
		{
			getchar();
			
		}
		else
		{
			if (opc <= listaPropiaPaises->getCA()) {

				pais = listaPropiaPaises->getItem(opc - 1);
				do
				{
					system("cls");
					ListaTropaCaballeros->Listar();
					cout << endl;
					ListaTropaArqueros->Listar();
					cout << endl;
					ListaTropaMagos->Listar();
					cout << endl;
					if (check == 0)
					{
						cout << "Escriba la clase de tropa que desee: ";
						cin.clear();
						cin >> opc2;
					}
					else
					{
						cout << "Escriba la clase de tropa que desee: " << opc2 << endl;
					}
					

					if (opc2 == "CABALLERO" || opc2 == "Caballero" || opc2 == "caballero" || opc2 == "ARQUERO" || opc2 == "Arquero" || opc2 == "arquero" || opc2 == "MAGO" || opc2 == "Mago" || opc2 == "mago")
					{

						if (opc2 == "CABALLERO" || opc2 == "Caballero" || opc2 == "caballero")
						{
							ListaTropaCaballeros->Listar();
							cout << "Seleccione la tropa que desea agregar en " << pais->getCodigo() << ": ";
							cin.clear();
							cin >> opc3;
							if (opc3 == 0)
							{
								getchar();
								opc3 = 0;
							}

							if (opc3 != 0 && opc3 > 0 && opc3-1 < ListaTropaCaballeros->getCA())
							{
								pais->AgregarTropaCaballero(ListaTropaCaballeros->getItem(opc3 - 1));
								ListaTropaCaballeros->QuitarenPos(opc3 - 1);
								opc = 1;
							}
							else
							{
								check = 1;
							}
														
						}
						else
						{

							if (opc2 == "ARQUERO" || opc2 == "Arquero" || opc2 == "arquero")
							{
								ListaTropaArqueros->Listar();
								cout << "Seleccione la tropa que desea agregar en " << pais->getCodigo() << ": ";
								cin.clear();
								cin >> opc3;
								if (opc3 == 0)
								{
									getchar();
									opc3 = 0;
								}

								if (opc3 != 0 && opc3 > 0 && opc3-1 < ListaTropaArqueros->getCA())
								{
									pais->AgregarTropaArquero(ListaTropaArqueros->getItem(opc3 - 1));
									ListaTropaArqueros->QuitarenPos(opc3 - 1);
									opc = 1;
								}
								else
								{
									check = 1;
								}
								
							}
							else
							{
								if (opc2 == "MAGO" || opc2 == "Mago" || opc2 == "mago")
								{
									ListaTropaMagos->Listar();
									cout << "Seleccione la tropa que desea agregar en " << pais->getCodigo() << ": ";
									cin.clear();
									cin >> opc3;
									if (opc3 == 0)
									{
										getchar();
										opc3 = 0;
									}

									if (opc3 != 0 && opc3 > 0 && opc3-1 < ListaTropaMagos->getCA())
									{
										pais->AgregarTropaMago(ListaTropaMagos->getItem(opc3 - 1));
										ListaTropaMagos->QuitarenPos(opc3 - 1);
										opc = 1;
									}
									else
									{
										check = 1;
									}
									
								}
							}
						}
						
					}

				} while (opc != 1);

				check = 0;
				opc = 0;

				cout << endl;
				cout << pais->getCodigo();
				cout << endl;
				pais->PrintTropas();
				system("pause");
				Tropas--;
			}
		}

		system("cls");

	} while (Tropas != 0);

}

cPais* cJugador::quitarPais(string pais)
{
	return listaPropiaPaises->Quitar(pais);
}

string cJugador::AtacarPais()
{
	int opcion = 0,check = 0;
	string opcion2;
	string resultado;
	cPais * pais=NULL;

	do
	{

	cout << "---------" << endl;
	cout << nombre << endl;
	cout << "---------" << endl << endl;
	
	
	listaPropiaPaises->ListarV();

	cout << "Selecciona el pais con el que queres atacar, si quiere pasar presiona un numero mayor a la cantidad de paises que tiene"<< endl;
	cout << "Pais: ";
	cin.clear();
	cin >> opcion;
	if (opcion == 0)
	getchar();

	if (opcion > listaPropiaPaises->getCA())
	{
		return("0");

	}else if (opcion-1 < listaPropiaPaises->getCA() && opcion != 0)
	{
		pais = listaPropiaPaises->getItem(opcion - 1);

		check = pais->getCantidadDeTropas();
		if (check < 2)
		{
			SetConsoleTextAttribute(consoleHandle, FSCTL_GET_INTEGRITY_INFORMATION);
			cout << endl << "Reingrese opcion, se debe atacar con un pais que tenga mas de una tropa.";
			SetConsoleTextAttribute(consoleHandle, 7);
			cout << endl;

			system("pause");
			system("cls");
		}
	}
	else
	{
		system("cls");
	}
	

	} while (check<2);

	resultado = pais->AtacarOtroPais(nombre);

	if (resultado != "0")
	{

		return(resultado);
	}
	else if (resultado == "atras")
	{
		return("atras");
	}else
	{
		return("0");
	}

	   
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

	ptr->setJugador(nombre);

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

void cJugador::setTropasEnPaisesPrueba(int caballeros, int arqueros, int magos)
{
	cPais * pais;
	int cont = 0;

	for (int i = 0; i < 10; i++)
	{

		pais = listaPropiaPaises->getItem(cont);

		if (caballeros != 0)
		{
			pais->AgregarTropaCaballero(ListaTropaCaballeros->getItem(0));
			ListaTropaCaballeros->QuitarenPos(0);
			caballeros--;
		}	
		else if (arqueros != 0)
		{
			pais->AgregarTropaArquero(ListaTropaArqueros->getItem(0));
			ListaTropaArqueros->QuitarenPos(0);
			arqueros--;
		}
		else if (magos != 0)
		{
			pais->AgregarTropaMago(ListaTropaMagos->getItem(0));
			ListaTropaMagos->QuitarenPos(0);
			magos--;
		}
		
	

		cont++;

		if (cont > 7)
		{
			cont = 0;
		}

	}
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
	
	
	
