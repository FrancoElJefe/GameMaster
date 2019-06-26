#include "cJugador.h"

HANDLE cJugador::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void cJugador::ImprimirMapa(void) // se imprime el mapuli
{
	string NomPaises[16] = { "Argentina", "Chile", "Uruguay" , "Brasil", "Peru", "Colombia", "Mexico", "California", "Oregon" , "Alaska", "Yukon", "Canada", "Nueva York", "Terranova", "Labrador", "Groenlandia" };

	cPais * pais = NULL;
	char Npais[16] = {' '};

	for (int i = 0; i < listaPropiaPaises->getCA(); i++)
	{
		pais = listaPropiaPaises->getItem(i);

		for (int k = 0; k < 16; k++)
		{
			if (pais->getCodigo() == NomPaises[k])
			{
				Npais[k] = pais->getNjugador()+48;//codigo ASCII
			}
		}
		
	}

	cout << "\t\t	                                                                                _________________" << endl;
	cout << "\t\t	                           ____________                                        |                 |" << endl;
	cout << "\t\t	                      ____/            |                                       |                 |" << endl;
	cout << "\t\t	 ____________________/    |            |                                       |                 |" << endl;
	cout << "\t\t	|            /            | CANADA(" << Npais[11] << ")  |              ___________              |  GROENLANDIA(" << Npais[15] << ") |" << endl;
	cout << "\t\t	| ALASKA(" << Npais[9] << ") /  YUKON(" << Npais[10] << ")   |            |             |           |             |                 |" << endl;
	cout << "\t\t\t|__________/______________|____________|______       |LABRADOR(" << Npais[14] << ")|-------------|                 |" << endl;
	cout << "\t\t	|                         |                   |______|___________|             |_________________|" << endl;
	cout << "\t\t	|                          |                                    |                  /" << endl;
	cout << "\t\t	|                           |__         TERRANOVA(" << Npais[13] << ")            |                 /" << endl;
	cout << "\t\t	 |          OREGON(" << Npais[8] << ")          |________________________________|                /" << endl;
	cout << "\t\t	  |                               |__                           |               /" << endl;
	cout << "\t\t	   |                                 |__    NUEVA YORK(" << Npais[12] << ")       /--------------/" << endl;
	cout << "\t\t	    |___________________________________|______________________/" << endl;
	cout << "\t\t	     |                                                        /" << endl;
	cout << "\t\t	      |                CALIFORNIA(" << Npais[7] << ")                         /" << endl;
	cout << "\t\t	       |____________________________________________________/" << endl;
	cout << "\t\t	                         |_                                /" << endl;
	cout << "\t\t	                           |__                            /" << endl;
	cout << "\t\t	                              |___                       /" << endl;
	cout << "\t\t	                                  |       MEXICO(" << Npais[6] << ")     |" << endl;
	cout << "\t\t	                                   | ___                | " << endl;
	cout << "\t\t	                                        |___            | " << endl;
	cout << "\t\t	                                            |           |" << endl;
	cout << "\t\t	                                             |__        |" << endl;
	cout << "\t\t	                                                |__     | " << endl;
	cout << "\t\t	                                                   |___ |" << endl;
	cout << "\t\t	                                                       ||__________________________________________" << endl;
	cout << "\t\t	                                                       /                 |                         |_" << endl;
	cout << "\t\t	                                                      /                  |                           |_" << endl;
	cout << "\t\t	                                                      |    COLOMBIA(" << Npais[5] << ")   |                             |_" << endl;
	cout << "\t\t	                                                      |__________________|                               |_" << endl;
	cout << "\t\t	                                                      |                   |_                               |_" << endl;
	cout << "\t\t	                                                      |                     |_        BRASIL(" << Npais[3] << ")              |" << endl;
	cout << "\t\t	                                                      |                       |_                            /" << endl;
	cout << "\t\t	                                                      |        PERU(" << Npais[4] << ")          |                          /" << endl;
	cout << "\t\t	                                                      |                         |                         /" << endl;
	cout << "\t\t	                                                      |_________________________|________________________/" << endl;
	cout << "\t\t	                                                      |            |                    |               /" << endl;
	cout << "\t\t	                                                      |            /                    |              /" << endl;
	cout << "\t\t	                                                      |           |                     | URUGUAY(" << Npais[2] << ")  |" << endl;
	cout << "\t\t	                                                      |           |                     |            /" << endl;
	cout << "\t\t	                                                      |   (" << Npais[1] << ")      |                    |           /" << endl;
	cout << "\t\t	                                                      |    C      /                      |_________|" << endl;
	cout << "\t\t	                                                      |    H      |                            |" << endl << endl;
	cout << "------------------------------------------------------------------------------|    I      |                            |" << endl << endl;
	cout << "\t\t                                                              |    L      |    ARGENTINA(" << Npais[0] << ")          _/" << endl;
	cout << "\t\t	                                                      |    E      /                         /" << endl;
	cout << "\t\t	                                                      |          /                       /" << endl;
	cout << "\t\t	                                                       |        /                      /" << endl;
	cout << "\t\t	                                                        |      /                     /" << endl;
	cout << "\t\t	                                                        |      |                   /" << endl;
	cout << "\t\t	                                                        |      |                 /" << endl;
	cout << "\t\t	                                                        |      |               /" << endl;
	cout << "\t\t	                                                        |      |             /" << endl;
	cout << "\t\t	                                                        |      |           /" << endl;
	cout << "\t\t	                                                         |      |         /" << endl;
	cout << "\t\t	                                                          |     |       /" << endl;
	cout << "\t\t	                                                           |    |     /" << endl;
	cout << "\t\t	                                                            |   |   /" << endl;
	cout << "\t\t	                                                              |_|_/" << endl;

	cout << endl;


}

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

void cJugador::setTropaEnPais(void)
{
	unsigned int opc = 0, combinacion=0, SeleccionDePais = 0;
	int opc3 = 0, Tropas = 0, check = 0, checkTropasEnToPaises = 0;
	int memoriaTropas[8][3] = { 0 };
	string opc2, CTropa;
	cPais * pais = NULL;
	cPais * aux = NULL;

	Tropas = ListaTropaArqueros->getCA() + ListaTropaCaballeros->getCA() + ListaTropaMagos->getCA();

	do
	{

		system("cls");

		ImprimirMapa();

		cout << "\t\t***********************************" << endl;
		cout << "\t\tDISTRIBUYE LAS TROPAS EN TUS PAISES" << endl;
		cout << "\t\t***********************************" << endl << endl;
		cout << "---------" << endl;
		cout << nombre << endl;
		cout << "---------" << endl << endl;

		cout << "Tropas: " << endl;
		ListaTropaCaballeros->Listar();
		cout << endl;
		ListaTropaArqueros->Listar();
		cout << endl;
		ListaTropaMagos->Listar();
		cout << endl;


		listaPropiaPaises->ListarV();
		cout << endl;
		cout << "Seleccione el Pais que quiera agregar: ";
		cin.clear();
		cin >> SeleccionDePais;

		if (SeleccionDePais == 0)
		{
			getchar();
			opc = 0;
		}
		else
		{
			if (SeleccionDePais - 1 < listaPropiaPaises->getCA()) {

				pais = listaPropiaPaises->getItem(SeleccionDePais - 1);

				do
				{
					for (int i = 0; i < listaPropiaPaises->getCA(); i++)
					{
						aux = listaPropiaPaises->getItem(i);
						if (aux->getCantidadDeTropas() == 0)
						{
							checkTropasEnToPaises = 1;//si entra por lo menos una vez, quiere decir que hay algun pais sin tropas
						}
					}

					system("cls");
					ListaTropaCaballeros->Listar();
					cout << endl;
					ListaTropaArqueros->Listar();
					cout << endl;
					ListaTropaMagos->Listar();
					cout << endl;
					if (check == 0)
					{
						cout << "Escriba la clase de tropa que desee, si quiere volver escriba ATRAS: ";
						cin.clear();
						cin >> opc2;
					}
					else
					{
						cout << "Escriba la clase de tropa que desee: " << opc2 << endl;
					}
									   					

					if (opc2 == "CABALLERO" || opc2 == "Caballero" || opc2 == "caballero")//se agregan caballeros
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
						else
						{
							if (opc3 - 1 < ListaTropaCaballeros->getCA())
							{

								if (pais->getCantTcaballero() != 0 && checkTropasEnToPaises == 0) // para combinar tropas de caballeros
								{
									cout << "Quiere combinar tropas, escriba si o no:";
									cin >> CTropa;

									if (CTropa == "si")
									{
										pais->PrintTropasCaballero();
										cout << "Tropa a combinar:";
										cin >> combinacion;

										if (opc3 - 1 < pais->getCantTcaballero()) {

											pais->combinarTCaballero(ListaTropaCaballeros->QuitarenPos(opc3 - 1), combinacion-1);											
											opc3 = 0;
											cout << endl;
											cout << pais->getCodigo();
											cout << endl;
											pais->PrintTropas();
											opc = 1;
											system("pause");
										}

									}
									else
									{
										pais->AgregarTropaCaballero(ListaTropaCaballeros->QuitarenPos(opc3 - 1));										
										opc3 = 0;
										cout << endl;
										cout << pais->getCodigo();
										cout << endl;
										pais->PrintTropas();
										memoriaTropas[SeleccionDePais - 1][0]++;
										opc = 1;
										system("pause");
									}
																	   
								}
								else
								{
									pais->AgregarTropaCaballero(ListaTropaCaballeros->QuitarenPos(opc3 - 1));
									opc3 = 0;
									cout << endl;
									cout << pais->getCodigo();
									cout << endl;
									pais->PrintTropas();
									memoriaTropas[SeleccionDePais - 1][0]++;
									opc = 1;
									system("pause");
								}
								
							}
							else
							{
								check = 1;
							}
						}


					}
					else if (opc2 == "ARQUERO" || opc2 == "Arquero" || opc2 == "arquero")//se agregan arqueros
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
						else
						{
							if (opc3 - 1 < ListaTropaArqueros->getCA())
							{
								if (pais->getCantTarquro() != 0 && checkTropasEnToPaises == 0) // para combinar tropa de arqueros
								{
									cout << endl << "Quiere combinar tropas, escriba si o no:";
									cin >> CTropa;

									if (CTropa == "si")
									{
										pais->PrintTropasArquero();
										cout << "Tropa a combinar:";
										cin >> combinacion;

										if (opc3 - 1 < pais->getCantTarquro()) {

											pais->combinarTarquero(ListaTropaArqueros->QuitarenPos(opc3 - 1), combinacion - 1);
											opc3 = 0;
											cout << endl;
											cout << pais->getCodigo();
											cout << endl;
											pais->PrintTropas();											
											opc = 1;
											system("pause");
										}

									}
									else
									{
										pais->AgregarTropaArquero(ListaTropaArqueros->QuitarenPos(opc3 - 1));
										opc3 = 0;
										cout << endl;
										cout << pais->getCodigo();
										cout << endl;
										pais->PrintTropas();
										memoriaTropas[SeleccionDePais - 1][1]++;
										opc = 1;

										system("pause");
									}
								}
								else
								{
									pais->AgregarTropaArquero(ListaTropaArqueros->QuitarenPos(opc3 - 1));
									opc3 = 0;
									cout << endl;
									cout << pais->getCodigo();
									cout << endl;
									pais->PrintTropas();
									memoriaTropas[SeleccionDePais - 1][1]++;
									opc = 1;

									system("pause");
								}
							}
							else
							{
								check = 1;
							}

						}
					}
					else if (opc2 == "MAGO" || opc2 == "Mago" || opc2 == "mago")//se agregan magos
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
						else
						{
							if (opc3 - 1 < ListaTropaMagos->getCA())
							{
								if (pais->getCantTMago() != 0 && checkTropasEnToPaises == 0) // para combinar tropa de magos
								{
									cout << endl << "Quiere combinar tropas, escriba si o no:";
									cin >> CTropa;

									if (CTropa == "si")
									{
										pais->PrintTropasMago();
										cout << "Tropa a combinar:";
										cin >> combinacion;

										if (opc3 - 1 < pais->getCantTMago()) {

											pais->combinarTmago(ListaTropaMagos->QuitarenPos(opc3 - 1), combinacion - 1);
											opc3 = 0;
											cout << endl;
											cout << pais->getCodigo();
											cout << endl;
											pais->PrintTropas();
											opc = 1;
											system("pause");
										}
										
									}
									else
									{
										pais->AgregarTropaMago(ListaTropaMagos->QuitarenPos(opc3 - 1));
										opc3 = 0;
										cout << endl;
										cout << pais->getCodigo();
										cout << endl;
										pais->PrintTropas();
										memoriaTropas[SeleccionDePais - 1][2]++;
										opc = 1;

										system("pause");
									}
								
								}
								else
								{
									pais->AgregarTropaMago(ListaTropaMagos->QuitarenPos(opc3 - 1));
									opc3 = 0;
									cout << endl;
									cout << pais->getCodigo();
									cout << endl;
									pais->PrintTropas();
									memoriaTropas[SeleccionDePais - 1][2]++;
									opc = 1;

									system("pause");
								}
							}
							else
							{
								check = 1;
							}
						}

					}else if (opc2 == "atras" || opc2 == "ATRAS")
					{
						opc = 1;
					}
					else
					{
						opc = 0;
					}



				} while (opc != 1);

				checkTropasEnToPaises = 0;
				opc = 0;
				check = 0;
				Tropas = ListaTropaArqueros->getCA() + ListaTropaCaballeros->getCA() + ListaTropaMagos->getCA();

			}
		}

		system("cls");

		//**************************** se evalua si se distribuyeron las tropas en los 8 paises *************************//
		if (Tropas == 0)
		{
			for (int i = 0; i < listaPropiaPaises->getCA(); i++)
			{
				pais = listaPropiaPaises->getItem(i);

				if (pais->getCantidadDeTropas() == 0) //si en algun pais no se pusieron tropas hay que resetearlas
				{
					SetConsoleTextAttribute(consoleHandle, FSCTL_GET_INTEGRITY_INFORMATION);
					cout << endl << "Debe distribuir las tropas de modo que todos los paises posean una de cualquier clase por lo menos." << endl;
					SetConsoleTextAttribute(consoleHandle, 7);
					cout << "REINGRESAR." << endl;
					system("Pause");
					i = listaPropiaPaises->getCA();
					Tropas = 1;

				}

			}

			if (Tropas == 1)// despues de ver si algun pais quedo sin tropas, si la variable Tropas esta en 1 se quitan las tropas de los paises y se las agrega a la listas del jugador
			{

				for (int i = 0; i < 8; i++)
				{
					pais = listaPropiaPaises->getItem(i);

					for (int k = 0; k < 3; k++)
					{
						if (memoriaTropas[i][k] >= 1)
						{
							for (int j = 0; j < memoriaTropas[i][k]; j++)
							{								

								if (k == 0)//caballeo
								{
									ListaTropaCaballeros->AgregarItem(pais->quitarTcaballero());																		
								}
								else if (k == 1)//arquero
								{
									ListaTropaArqueros->AgregarItem(pais->quitarTarquero());
								}
								else //mago
								{
									ListaTropaMagos->AgregarItem(pais->quitarTmago());
								}
							}

						}

					}

				}

			}



		}
		//***************************************************************************************************************//

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
	
	
	
