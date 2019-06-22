#include "cPais.h"

cLista<cPais> *cPais::listaPaises = new cLista<cPais>(16);
HANDLE cPais::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

typedef enum MyEnum {PLimitrofes=0, EPaisParaAtacar, EdeMiTropas, ETropaEnemiga, MagoContraArquero, MagoContraCaballero, MagoContraMago, ConquistasteElPais};

cPais::cPais()
{
	jugador = 0;
}

cPais::cPais(string nomb) : nombre(nomb)
{
	vecinos = new cLista<cPais>();
	ListaTropasArquero = new cLista<cTropaArquero>;
	ListaTropasCaballeros = new cLista<cTropaCaballero>;
	ListaTropasMago = new cLista<cTropaMago>;
	jugador = 0;
	listaPaises->AgregarItem(this);
	srand(time(NULL));//inicializo los numeros random
}

void cPais::AgregarTropaCaballero(cTropaCaballero * ptr)
{
	ListaTropasCaballeros->AgregarItem(ptr);
}

void cPais::AgregarTropaArquero(cTropaArquero * ptr)
{
	ListaTropasArquero->AgregarItem(ptr);
}

void cPais::AgregarTropaMago(cTropaMago * ptr)
{
	ListaTropasMago->AgregarItem(ptr);
}

void cPais::AgregarVecinos(cPais * ptr)
{
	vecinos->AgregarItem(ptr);
}

void cPais::setJugador(string jug)
{
	if (jug == "Jugador 1" )
	{
		jugador = 1;
	}	
	else
	{
		jugador = 2;
	}
}

string cPais::AtacarOtroPais(string nomb)
{
	int opcion = 0, OpcionTropaTuya = 0, fin = 0, sinTROPA = 0, sinTROPAmia = 0, Otropas = 0, estado = 0, i = 1, cVecinos = 0, eliminar = 0;
	string salir, clase_slc, clase_tuya;
	char atras;
	cPais * PaisParaAtacar = NULL;
	cTropaCaballero * miTropaC = NULL;
	cTropaArquero *miTropaA= NULL;
	cTropaMago * miTropaM = NULL;

	system("cls");
	getchar();

	do
	{
		
		
		switch (estado)
		{
		case PLimitrofes:

			titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);

			cout << "Paises limitrofes para atacar: " << endl << endl;
			cVecinos = vecinos->ListarParaAtacar(nomb);
			if (cVecinos == 0)
			{
				SetConsoleTextAttribute(consoleHandle, FSCTL_GET_INTEGRITY_INFORMATION);
				cout << "***No tiene paises vecinos enemigos***" << endl << endl;
				SetConsoleTextAttribute(consoleHandle, 7);

				system("Pause");
				return("atras");
			}
			
			cout << endl << "si quiere ir para atras presione retroceso <-, de lo contrario pulse cualquier tecla";
			atras = _getch();
			if (atras == '\0')
			atras = _getch();

			if (atras == '\b')
			{
				return("atras");
			}else
			{
				cout << endl << "Pais a Atacar: ";
				cin.clear();
				cin >> opcion;

				if (opcion - 1 <= cVecinos && opcion != 0) 
				estado = 1;
				
			}
			
					
			system("cls");
			break;

		case EPaisParaAtacar:

			titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);

			PaisParaAtacar = vecinos->AtacarVecino(nomb, opcion);

			cout << "Usted eligio atacar al pais: " << PaisParaAtacar->getCodigo() << endl << endl;

			PaisParaAtacar->PrintTropas(); 

			cout << "si desea continuar presione enter, de lo contrario pulse cualquier tecla";
			atras = _getch();
			if (atras == '\0')
			atras = _getch();

			
			if (atras != 13)
			{
				estado = 0;
				system("cls");
			}
			else
			{
				estado = 2;
				system("cls");
			}
			break;

		case EdeMiTropas:

			titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);

			cout << "Tropas Disponibles en "<< nombre<<" para Realizar el ataque:" << endl << endl; //mostras las tropas disponibles en el pais con el que atacas
			PrintTropas();

			cout << "Elija la clase: "; //seleccionar clase con la que atacas
			cin.clear();
			cin >> clase_tuya;

			if (clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero" && ListaTropasCaballeros->getCA() != 0) //si atacas con caballeros
			{
				cout << endl << "Con cual tropa quiere atacar: ";
				cin >> OpcionTropaTuya;
				if (OpcionTropaTuya == 0)
					getchar();

				if (OpcionTropaTuya - 1 < ListaTropasCaballeros->getCA() && OpcionTropaTuya != 0)
				{
					miTropaC = ListaTropasCaballeros->getItem(OpcionTropaTuya - 1);
					estado = ETropaEnemiga;
					
				}
				

			}
			else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero" && ListaTropasArquero->getCA() != 0) //si atacas con arqueros
			{
				cout << endl << "Con cual tropa quiere atacar: ";
				cin >> OpcionTropaTuya;
				if (OpcionTropaTuya == 0)
					getchar();

				if (OpcionTropaTuya - 1 < ListaTropasArquero->getCA() && OpcionTropaTuya != 0)
				{
					miTropaA = ListaTropasArquero->getItem(OpcionTropaTuya - 1);
					estado = ETropaEnemiga;
				}
				
			}
			else if (clase_tuya == "MAGO" || clase_tuya == "Mago" || clase_tuya == "mago" && ListaTropasMago->getCA() != 0) //si atacas con magos es un ataque en zona
			{

				cout << endl << "Con cual tropa quiere atacar: ";
				cin >> OpcionTropaTuya;
				if (OpcionTropaTuya == 0) getchar();

				if (OpcionTropaTuya - 1 < ListaTropasMago->getCA() && OpcionTropaTuya != 0)
				{
					miTropaM = ListaTropasMago->getItem(OpcionTropaTuya - 1);

					cout << endl << "Se atacaran a las siguientes tropas en " << PaisParaAtacar->getCodigo() << ":" << endl << endl;
					PaisParaAtacar->PrintTropas();
					cout << endl;
					system("pause");
					estado = MagoContraArquero;
				}
				
			}
			
			system("cls");

			break;
			
		case ETropaEnemiga:

			    titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);

				PaisParaAtacar->PrintTropas();

				cout << endl << "Elija la clase la cual quiere atacar:";
				cin >> clase_slc;

				if (clase_slc == "CABALLERO" || clase_slc == "Caballero" || clase_slc == "caballero" && PaisParaAtacar->getCantTcaballero() != 0) // **********atacas a los caballeros enemigos*********
				{
					cout << endl;
					PaisParaAtacar->PrintTropasCaballero();
				
					cout << endl << "Elija la tropa que quiere atacar:"; // elegis la tropa enemigo de la clase caballero para atacar
					cin >> Otropas;
					if (Otropas == 0) getchar();

					if (Otropas - 1 < PaisParaAtacar->getCantTcaballero() && Otropas != 0)
					{
						if (clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero")
						{
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaC->Ataque(), clase_slc, clase_tuya);
							if (fin == 0)
							{
								eliminar = PaisParaAtacar->ContrataqueDeCaballeros(NULL, miTropaC, NULL, Otropas - 1); // contraataque de los caballeros
								if (eliminar == 1)
								{
									ListaTropasCaballeros->Eliminar(OpcionTropaTuya - 1);
								}
							}
						}
						else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero")
						{
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque(), clase_slc, clase_tuya);
							//tiro un ranndom de 0 a 10 si el numero es 2 u 8 la tropa puede atacar otra vez con un 50% de aumento de dano 
							int num = rand() % 21;

							if (num % 2 == 0 && fin == 0)
							{
								SetConsoleTextAttribute(consoleHandle, EVENT_SYSTEM_FOREGROUND);
								cout << endl << "*****Los Arqueros efectuan un segundo ataque potenciado al 50%!!!*****" << endl;
								SetConsoleTextAttribute(consoleHandle, 7);
								fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque() + miTropaA->Ataque()*0.50, "CABALLERO", "ARQUERO");
							}

							if (fin == 0)
							{
								eliminar = PaisParaAtacar->ContrataqueDeCaballeros(miTropaA, NULL, NULL, Otropas - 1); // contraataque de los caballeros
								if (eliminar == 1)
								{
									ListaTropasCaballeros->Eliminar(OpcionTropaTuya - 1);
								}
							}

						}
						estado = ConquistasteElPais;
						system("pause");
					}
					else
					{
						system("cls");
					}

				}
				else if (clase_slc == "ARQUERO" || clase_slc == "Arquero" || clase_slc == "arquero" && PaisParaAtacar->getCantTarquro() != 0)// **********atacas a los arqueros enemigos*********
				{
					cout << endl;
					PaisParaAtacar->PrintTropasArquero();
					
					cout << endl << "Elija la tropa que quiere atacar:"; // elegis la tropa enemigo de la clase caballero para atacar
					cin >> Otropas;
					if (Otropas == 0) getchar();
					

					if (Otropas - 1 < PaisParaAtacar->getCantTarquro() && Otropas != 0)
					{
						if (clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero")
						{
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaC->Ataque(), clase_slc, clase_tuya);
							estado = ConquistasteElPais;
						}
						else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero")
						{
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque(), clase_slc, clase_tuya);

							//tiro un ranndom de 0 a 10 si el numero es 2 u 8 la tropa puede atacar otra vez con un 50% de aumento de dano 
							int num = rand() % 21;

							if (num % 2 == 0 && fin == 0)
							{
								SetConsoleTextAttribute(consoleHandle, EVENT_SYSTEM_FOREGROUND);
								cout << endl << "*****Los Arqueros efectuan un segundo ataque potenciado al 50%!!!*****" << endl;
								SetConsoleTextAttribute(consoleHandle, 7);
								fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque() + miTropaA->Ataque()*0.50, "ARQUERO", "ARQUERO");
							}
							estado = ConquistasteElPais;
						}
						system("pause");
					}					
					else
					{
						system("cls");
					}

				}
				else if (clase_slc == "MAGO" || clase_slc == "Mago" || clase_slc == "mago" && PaisParaAtacar->getCantTMago() != 0) // **********atacas a los magos enemigos*********
				{
					cout << endl;
					PaisParaAtacar->PrintTropasMago();

					cout << endl << "Elija la tropa que quiere atacar:"; // elegis la tropa enemigo de la clase caballero para atacar
					cin >> Otropas;
					if (Otropas == 0) getchar();

					if (Otropas - 1 < PaisParaAtacar->getCantTMago() && Otropas != 0)
					{
						if (clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero")
						{
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaC->Ataque(), clase_slc, clase_tuya);
							estado = ConquistasteElPais;
						}
						else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero")
						{
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque(), clase_slc, clase_tuya);

							//tiro un ranndom de 0 a 10 si el numero es 2 u 8 la tropa puede atacar otra vez con un 50% de aumento de dano 
							int num = rand() % 21;

							if (num % 2 == 0 && fin == 0)
							{
								SetConsoleTextAttribute(consoleHandle, EVENT_SYSTEM_FOREGROUND);
								cout << endl << "*****Los Arqueros efectuan un segundo ataque potenciado al 50%!!!*****" << endl;
								SetConsoleTextAttribute(consoleHandle, 7);
								fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque() + miTropaA->Ataque()*0.50, "MAGO", "ARQUERO");
							}

							estado = ConquistasteElPais;
						}
						system("pause");
					}
					else
					{
						system("cls");
					}

				}
				else
				{
				system("cls");
				}
						
			break;

			case MagoContraArquero:
				
				if (PaisParaAtacar->getCantTarquro() != 0)
				{
					titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);

					for (int i = 0; i < PaisParaAtacar->getCantTarquro(); i++)
					{
						fin = PaisParaAtacar->Atacado(i, miTropaM->Ataque(), "ARQUERO", clase_tuya);
					}
					system("Pause");
					
				}
				else
				{
					system("cls");
				}
						
				estado = MagoContraMago;

				break;

			case MagoContraMago:

				if (PaisParaAtacar->getCantTarquro() == 0)
				{
					titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);
				}
				
				if (PaisParaAtacar->getCantTMago() != 0)
				{
					for (int i = 0; i < PaisParaAtacar->getCantTMago(); i++)
					{
						fin = PaisParaAtacar->Atacado(i, miTropaM->Ataque(), "MAGO", clase_tuya);
					}
					system("pause");
				}

				estado = MagoContraCaballero;

				break;

			case MagoContraCaballero:

				if (PaisParaAtacar->getCantTMago() == 0)
				{
					titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);
				}


				if (PaisParaAtacar->getCantTcaballero() != 0)
				{
					for (int i = 0; i < PaisParaAtacar->getCantTcaballero(); i++)
					{
						fin = PaisParaAtacar->Atacado(i, miTropaM->Ataque(), "CABALLERO", clase_tuya);

						if (fin == 0)
						{
							eliminar = PaisParaAtacar->ContrataqueDeCaballeros(NULL, NULL, miTropaM, i); // contraataque de los caballeros
							if (eliminar == 1)
							{
								ListaTropasMago->Eliminar(OpcionTropaTuya - 1);
								i = PaisParaAtacar->getCantTcaballero();
							}
														
						}
					}
					system("Pause");
				}

				estado = ConquistasteElPais;

				break;

			case ConquistasteElPais:
				
				system("cls");
		

				if (fin == 2)// ganaste el pais
				{
					ImprimirMapa();

					//titulo(PaisParaAtacar, estado, nombre, jugador, consoleHandle);

					SetConsoleTextAttribute(consoleHandle, EVENT_SYSTEM_FOREGROUND);
					cout << endl << "******************************************";
					cout << endl << "Enhorabuena, ganaste el pais " << PaisParaAtacar->getCodigo() << endl;
					cout << "******************************************" << endl << endl;
					SetConsoleTextAttribute(consoleHandle, 7);

					cout << "Debes pasarle una tropa:" << endl << endl;
					if (ListaTropasCaballeros->getCA() != 0)
					{
						PrintTropasCaballero();
					}

					if (ListaTropasArquero->getCA() != 0)
					{
						PrintTropasArquero();
					}

					if (ListaTropasMago->getCA() != 0)
					{
						PrintTropasMago();
					}

					cout << endl << "Escriba la clase: ";
					cin >> clase_tuya;

					if ((clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero") && ListaTropasCaballeros->getCA() != 0)
					{
						cout << endl << "Cual tropa desea pasar: ";
						cin >> OpcionTropaTuya;

						miTropaC = ListaTropasCaballeros->getItem(OpcionTropaTuya - 1);
						PaisParaAtacar->AgregarTropaCaballero(miTropaC);
						ListaTropasCaballeros->QuitarenPos(OpcionTropaTuya - 1);

						system("pause");

						return(PaisParaAtacar->getCodigo());

					}
					else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero" && ListaTropasArquero->getCA() != 0)
					{
						cout << endl << "Cual tropa desea pasar: ";
						cin >> OpcionTropaTuya;

						miTropaA = ListaTropasArquero->getItem(OpcionTropaTuya - 1);
						PaisParaAtacar->AgregarTropaArquero(miTropaA);
						ListaTropasArquero->QuitarenPos(OpcionTropaTuya - 1);

						system("pause");

						return(PaisParaAtacar->getCodigo());
					}
					else if (clase_tuya == "MAGO" || clase_tuya == "Mago" || clase_tuya == "mago" && ListaTropasMago->getCA() != 0)
					{

						cout << endl << "Cual tropa desea pasar: ";
						cin >> OpcionTropaTuya;

						miTropaM = ListaTropasMago->getItem(OpcionTropaTuya - 1);
						PaisParaAtacar->AgregarTropaMago(miTropaM);
						ListaTropasMago->QuitarenPos(OpcionTropaTuya - 1);

						system("pause");

						return(PaisParaAtacar->getCodigo());
					}


				}
				else
				{
					return("0");
				}



			break;

		default:
			break;
		}//termina el switch
		

	} while (i != 0);


	
	

}

int cPais::Atacado(int ntropa, int dano, string claseTAtacada, string claseTAtacante)
{
	cTropaCaballero * tropaCaballero;
	cTropaArquero * tropaArquero;
	cTropaMago * tropaMago;
	int eliminar=1;


	if (claseTAtacada == "CABALLERO" || claseTAtacada == "Caballero" || claseTAtacada == "caballero")
	{
	
		tropaCaballero = ListaTropasCaballeros->getItem(ntropa);
		SetConsoleTextAttribute(consoleHandle, 14);
		cout << endl << "\t--------------------------------------" << endl;
		cout << "\tTropa " << ntropa + 1 << ": ";
		eliminar = tropaCaballero->RecibirAtaqueTropa(dano, claseTAtacante);

		if (eliminar == 0)
		{
			ListaTropasCaballeros->Eliminar(ntropa);

			if (ListaTropasCaballeros->getCA() == 0 && ListaTropasArquero->getCA() == 0 && ListaTropasMago->getCA() == 0)
			{				
				return (2);
			}

			if (ListaTropasCaballeros->getCA() == 0)
			{
				return(1);
			}
		
		}
		else
		{
			//se viene el contrataque
			return (0);
		}
		

	}
	else if (claseTAtacada == "ARQUERO" || claseTAtacada == "Arquero" || claseTAtacada == "arquero")
	{
		tropaArquero = ListaTropasArquero->getItem(ntropa);
		SetConsoleTextAttribute(consoleHandle, 14);
		cout << endl << "\t--------------------------------------" << endl;
		cout << "\tTropa " << ntropa +1<< ": ";
		eliminar = tropaArquero->RecibirAtaqueTropa(dano, claseTAtacante);

		if (eliminar == 0)
		{
			ListaTropasArquero->Eliminar(ntropa);
			if (ListaTropasCaballeros->getCA() == 0 && ListaTropasArquero->getCA() == 0 && ListaTropasMago->getCA() == 0)
			{
				return (2);
			}

			if (ListaTropasArquero->getCA() == 0)
			{
				return(1);
			}
			
		}
		else
		{
			return (0);
		}

		
	}
	else if (claseTAtacada == "MAGO" || claseTAtacada == "Mago" || claseTAtacada == "mago") // los magos atacan a todas las tropas de la clase 
	{
	
		tropaMago = ListaTropasMago->getItem(ntropa);
		SetConsoleTextAttribute(consoleHandle, 14);
		cout << endl << "\t--------------------------------------" << endl;
		cout << "\tTropa " << ntropa+1 << ": ";
		eliminar = tropaMago->RecibirAtaqueTropa(dano, claseTAtacante);

		if (eliminar == 0)
		{
			ListaTropasMago->Eliminar(ntropa);

			if (ListaTropasCaballeros->getCA() == 0 && ListaTropasArquero->getCA() == 0 && ListaTropasMago->getCA() == 0)
			{
				return (2);
			}

			if (ListaTropasMago->getCA() == 0)
			{
				return(1);
			}
		}
		else
		{
			return (0);
		}
	}

	
	
}

int cPais::ContrataqueDeCaballeros(cTropaArquero * TropaEnemigaA = NULL, cTropaCaballero * TropaEnemigaC = NULL, cTropaMago * TropaEnemigaM = NULL, int Ntropa = 0)
{
	int Eliminar = 0;
	cTropaCaballero * miTropa = NULL;

	miTropa = ListaTropasCaballeros->getItem(Ntropa);

	SetConsoleTextAttribute(consoleHandle, 14);

	if (TropaEnemigaA != NULL)
	{
		cout << endl << "\t-----------ContraAtaque---------------" << endl;
		cout << "\tTu Tropa " << Ntropa + 1 << ": ";
		Eliminar = TropaEnemigaA->RecibirAtaqueTropa(miTropa->Ataque() + miTropa->Ataque()*0.25, "CABALLERO");
		
	}
	else if (TropaEnemigaC != NULL)
	{
		cout << endl << "\t-----------ContraAtaque---------------" << endl;
		cout << "\tTu Tropa " << Ntropa + 1 << ": ";
		Eliminar = TropaEnemigaC->RecibirAtaqueTropa(miTropa->Ataque()+ miTropa->Ataque()*0.25, "CABALLERO");
	}
	else if (TropaEnemigaM != NULL)
	{
		cout << endl << "\t-----------ContraAtaque---------------" << endl;
		cout << "\tTu Tropa " << Ntropa + 1 << ": ";
		Eliminar = TropaEnemigaM->RecibirAtaqueTropa(miTropa->Ataque() + miTropa->Ataque()*0.25, "CABALLERO");
	}

	if (Eliminar == 0)
	{
		return (1); //le mataron las tropas en el contra ataque;
	}
	else
	{
		return(0);
	}

}

void cPais::PrintA()
{
	cout << nombre<< endl;
	vecinos->ListarV();
	
}

void cPais::PrintTropas()
{
	if (ListaTropasCaballeros->getCA() != 0)
	{
		ListaTropasCaballeros->Listar();
		cout << endl;
	}

	if (ListaTropasArquero->getCA() != 0)
	{
		ListaTropasArquero->Listar();
		cout << endl;
	}
	
	if (ListaTropasMago->getCA() != 0)
	{
		ListaTropasMago->Listar();
		cout << endl;
	}
	
	
}

void cPais::printTodos()
{
	listaPaises->Listar();
}

void cPais::ImprimirMapa(void)
{
	cPais * pais = NULL;
	int Npais[16];

	for (int i = 0; i < 16; i++)
	{
		pais = listaPaises->getItem(i);
		Npais[i] = pais->getNjugador();
	}
	SetConsoleTextAttribute(consoleHandle, 7);
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
	cout << "\t\t	                                                      |    L      |    ARGENTINA(" << Npais[0] << ")          _/" << endl;
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
	SetConsoleTextAttribute(consoleHandle, 7);
	
}

void cPais::PrintNombre()
{
	cout << nombre << endl;
}

void cPais::PrintTropasCaballero()
{
	ListaTropasCaballeros->Listar();
}

void cPais::PrintTropasArquero()
{
	ListaTropasArquero->Listar();
}

void cPais::PrintTropasMago()
{
	ListaTropasMago->Listar();
}
cPais::~cPais()
{
	delete ListaTropasCaballeros;
	delete ListaTropasArquero;
	delete ListaTropasMago;
}



void cPais::titulo(cPais * paisParaATACAR, int estado, string nombre, int jugador, HANDLE consoleHandle) {

	SetConsoleTextAttribute(consoleHandle, 7);
	SetConsoleTextAttribute(consoleHandle, 5);
	if (jugador == 1)
	{
		cout << "----------------------------------------------" << endl;
		cout << "    Jugador 1" << " atacando con " << nombre;
		if (estado > 1)
		{
			cout << " a " << paisParaATACAR->getCodigo() << endl;
		}
		else {
			cout << endl;
		}
		cout << "----------------------------------------------" << endl << endl;
	}
	else
	{
		cout << "----------------------------------------------" << endl;
		cout << "    Jugador 2" << " atacando con " << nombre;
		if (estado > 1)
		{
			cout << " a " << paisParaATACAR->getCodigo() << endl;
		}
		else {
			cout << endl;
		}
		cout << "----------------------------------------------" << endl << endl;
	}
	SetConsoleTextAttribute(consoleHandle, 7);


}