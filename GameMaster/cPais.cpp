#include "cPais.h"

cLista<cPais> *cPais::listaPaises = new cLista<cPais>(16);

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
	int opcion = 0, OpcionTropaTuya = 0, fin = 0, sinTROPA = 0, sinTROPAmia = 0, Otropas = 0, estado = 0, i = 1, cVecinos = 0;
	string salir, clase_slc, clase_tuya, atras;
	cPais * PaisParaAtacar = NULL;
	cTropaCaballero * miTropaC;
	cTropaArquero *miTropaA;
	cTropaMago * miTropaM;

	system("cls");
	getchar();

	do
	{
		if (jugador == 1)
		{
			cout << "----------------------------------------------" << endl;
			cout << "    Jugador 1" << " atacando con "<< nombre;
			if (estado > 1)
			{
				cout << " a " << PaisParaAtacar->getCodigo() << endl;
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
				cout << " a " << PaisParaAtacar->getCodigo() << endl;
			}
			else {
				cout << endl;
			}
			cout << "----------------------------------------------" << endl << endl;
		}


		switch (estado)
		{
		case 0:
			
			cout << "Paises limitrofes para atacar: " << endl << endl;
			cVecinos = vecinos->ListarParaAtacar(nomb);
			if (cVecinos == 0)
			{
				cout << "***No tiene paises vecinos enemigos***" << endl << endl;
				system("Pause");
				return("atras");
			}
			cout << endl << "si quiere ir para atras presione 0 (cero), de lo contrario toque cualquier tecla:";
			cin >> atras;
			if (atras == "0")
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

		case 1:


			PaisParaAtacar = vecinos->AtacarVecino(nomb, opcion);

			cout << "Usted eligio atacar al pais: " << PaisParaAtacar->getCodigo() << endl << endl;

			PaisParaAtacar->PrintTropas(); 

			cout << "si desea continuar presione enter, de lo contrario pulse cualquier tecla";

			if (_getch() != 13)
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

		case 2:

			PaisParaAtacar->PrintTropas();
			
			cout << endl << "Elija la clase la cual quiere atacar:";
			cin >> clase_slc;

			estado = 3;
	
			system("cls");

			break;
			
		case 3:

						
			if (clase_slc == "CABALLERO" || clase_slc == "Caballero" || clase_slc == "caballero" && PaisParaAtacar->getCantTcaballero() != 0) // **********atacas a los caballeros enemigos*********
			{

				PaisParaAtacar->PrintTropasCaballero();

				if (sinTROPA == 0)
				{
					cout << endl << "Elija la tropa que quiere atacar:"; // elegis la tropa enemigo de la clase caballero para atacar
					cin >> Otropas;
					if (Otropas == 0) getchar();
		
				}
				else
				{
					cout << endl << "Elija la tropa que quiere atacar:" << Otropas;
				}

				if (Otropas - 1 < PaisParaAtacar->getCantTcaballero() && Otropas != 0)
				{
				
					cout << endl << "Tropas Disponibles Para Realizar ataque:" << endl << endl; //mostras las tropas disponibles en el pais con el que atacas
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
												
						if (OpcionTropaTuya-1 < ListaTropasCaballeros->getCA() && OpcionTropaTuya != 0)
						{
						miTropaC = ListaTropasCaballeros->getItem(OpcionTropaTuya - 1);

						fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaC->Ataque(), "CABALLERO", "CABALLERO");
						i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					
					}
					else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero" && ListaTropasArquero->getCA() != 0) //si atacas con arqueros
					{
						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						if (OpcionTropaTuya == 0)
						getchar();
						
						if (OpcionTropaTuya-1 < ListaTropasArquero->getCA() && OpcionTropaTuya != 0)
						{
						miTropaA = ListaTropasArquero->getItem(OpcionTropaTuya - 1);

						fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque(), "CABALLERO", "ARQUERO");
						i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}

					}
					else if (clase_tuya == "MAGO" || clase_tuya == "Mago" || clase_tuya == "mago" && ListaTropasMago->getCA() != 0) //si atacas con magos
					{

						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						if (OpcionTropaTuya == 0) getchar();

						if (OpcionTropaTuya-1 < ListaTropasMago->getCA() && OpcionTropaTuya != 0)
						{
						miTropaM = ListaTropasMago->getItem(OpcionTropaTuya - 1);
						fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaM->Ataque(), "CABALLERO", "MAGO");
						i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else
					{
						sinTROPA = 1;
						system("cls");
					}


				}
				else
				{
					system("cls");
				}
			
			}
			else if (clase_slc == "ARQUERO" || clase_slc == "Arquero" || clase_slc == "arquero" && PaisParaAtacar->getCantTarquro() != 0)// **********atacas a los arqueros enemigos*********
			{
				PaisParaAtacar->PrintTropasArquero();

				if (sinTROPA == 0)
				{
					cout << endl << "Elija la tropa que quiere atacar:"; // elegis la tropa enemigo de la clase caballero para atacar
					cin.clear();
					cin >> Otropas;
					if (Otropas == 0) getchar();

				}
				else
				{
					cout << endl << "Elija la tropa que quiere atacar:" << Otropas;
				}


				if (Otropas - 1 < PaisParaAtacar->getCantTarquro() && Otropas != 0)
				{
					
					cout << endl << "Tropas Disponibles Para Realizar ataque:" << endl << endl; //mostras las tropas disponibles en el pais con el que atacas
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

						if (OpcionTropaTuya-1 < ListaTropasCaballeros->getCA() && OpcionTropaTuya != 0)
						{
							miTropaC = ListaTropasCaballeros->getItem(OpcionTropaTuya - 1);

							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaC->Ataque(), "ARQUERO", "CABALLERO");
							i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero" && ListaTropasArquero->getCA() != 0) //si atacas con arqueros
					{
						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						getchar();

						if (OpcionTropaTuya-1 < ListaTropasArquero->getCA() && OpcionTropaTuya != 0)
						{
							miTropaA = ListaTropasArquero->getItem(OpcionTropaTuya - 1);

							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque(), "ARQUERO", "ARQUERO");
							i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else if (clase_tuya == "MAGO" || clase_tuya == "Mago" || clase_tuya == "mago" && ListaTropasMago->getCA() != 0) //si atacas con magos
					{

						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						if (OpcionTropaTuya == 0) getchar();

						if (OpcionTropaTuya-1 < ListaTropasMago->getCA() && OpcionTropaTuya != 0)
						{
							miTropaM = ListaTropasMago->getItem(OpcionTropaTuya - 1);
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaM->Ataque(), "ARQUERO", "MAGO");
							i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else
					{
						sinTROPA = 1;
						system("cls");
					}

				}
				else
				{
					system("cls");
				}
							   				
			}
			else if (clase_slc == "MAGO" || clase_slc == "Mago" || clase_slc == "mago" && PaisParaAtacar->getCantTMago() != 0) // **********atacas a los magos enemigos*********
			{
				PaisParaAtacar->PrintTropasMago();

				if (sinTROPA == 0)
				{
					cout << endl << "Elija la tropa que quiere atacar:"; // elegis la tropa enemigo de la clase caballero para atacar
					cin >> Otropas;
					if (Otropas == 0) getchar();
									
				}
				else
				{
					cout << endl << "Elija la tropa que quiere atacar:" << Otropas;
				}

				if (Otropas - 1 < PaisParaAtacar->getCantTMago() && Otropas != 0)
				{
					cout << endl << "Tropas Disponibles Para Realizar ataque:" << endl << endl; //mostras las tropas disponibles en el pais con el que atacas
					PrintTropas();

					cout << "Elija la clase: "; //seleccionar clase con la que atacas
					cin >> clase_tuya;

					if (clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero" && ListaTropasCaballeros->getCA() != 0) //si atacas con caballeros
					{
						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						if (OpcionTropaTuya == 0)
							getchar();

						if (OpcionTropaTuya-1 < ListaTropasCaballeros->getCA() && OpcionTropaTuya != 0)
						{
							miTropaC = ListaTropasCaballeros->getItem(OpcionTropaTuya - 1);

							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaC->Ataque(), "MAGO", "CABALLERO");
							i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero" && ListaTropasArquero->getCA() != 0) //si atacas con arqueros
					{
						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						getchar();

						if (OpcionTropaTuya-1 < ListaTropasArquero->getCA() && OpcionTropaTuya != 0)
						{
							miTropaA = ListaTropasArquero->getItem(OpcionTropaTuya - 1);

							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaA->Ataque(), "MAGO", "ARQUERO");
							i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else if (clase_tuya == "MAGO" || clase_tuya == "Mago" || clase_tuya == "mago" && ListaTropasMago->getCA() != 0) //si atacas con magos
					{

						cout << endl << "Con cual tropa quiere atacar: ";
						cin >> OpcionTropaTuya;
						if (OpcionTropaTuya == 0) getchar();

						if (OpcionTropaTuya-1 < ListaTropasMago->getCA() && OpcionTropaTuya != 0)
						{
							miTropaM = ListaTropasMago->getItem(OpcionTropaTuya - 1);
							fin = PaisParaAtacar->Atacado(Otropas - 1, miTropaM->Ataque(), "MAGO", "MAGO");
							i = 0;
						}
						else
						{
							sinTROPA = 1;
							system("cls");
						}
					}
					else
					{
						sinTROPA = 1;
						system("cls");
					}


				}
				else
				{
					system("cls");
				}
			

			}else
			{
			estado = 2;
			system("cls");
			}
		
			break;

		default:
			break;
		}//termina el switch
		

	} while (i != 0);


	system("pause");

	if (fin == 1)// ganaste el pais
	{	
		
		cout << endl << "******************************************";
		cout << endl << "Enhorabuena, ganaste el pais " << PaisParaAtacar->getCodigo() << endl;
		cout << "******************************************" << endl << endl;

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

		if ((clase_tuya == "CABALLERO" || clase_tuya == "Caballero" || clase_tuya == "caballero")) //si atacas con caballeros
		{
			cout << endl << "Con cual tropa quiere pasar: ";
			cin >> OpcionTropaTuya;

			miTropaC = ListaTropasCaballeros->getItem(OpcionTropaTuya - 1);

			PaisParaAtacar->AgregarTropaCaballero(miTropaC);
			ListaTropasCaballeros->QuitarenPos(OpcionTropaTuya - 1);

		}
		else if (clase_tuya == "ARQUERO" || clase_tuya == "Arquero" || clase_tuya == "arquero") //si atacas con arqueros
		{
			cout << endl << "Con cual tropa quiere atacar: ";
			cin >> OpcionTropaTuya;

			miTropaA = ListaTropasArquero->getItem(OpcionTropaTuya - 1);

			PaisParaAtacar->AgregarTropaArquero(miTropaA);
			ListaTropasArquero->QuitarenPos(OpcionTropaTuya - 1);
		}
		else if (clase_tuya == "MAGO" || clase_tuya == "Mago" || clase_tuya == "mago") //si atacas con magos
		{

			cout << endl << "Con cual tropa quiere atacar: ";
			cin >> OpcionTropaTuya;

			miTropaM = ListaTropasMago->getItem(OpcionTropaTuya - 1);

			PaisParaAtacar->AgregarTropaMago(miTropaM);

			ListaTropasMago->QuitarenPos(OpcionTropaTuya - 1);
		}

		return(PaisParaAtacar->getCodigo());
	}
	else
	{
		return("0");
	}

	

}

int cPais::Atacado(int ntropa, int dano, string claseTAtacada, string claseTAtacante)
{
	cTropaCaballero * tropaCaballero;
	cTropaArquero * tropaArquero;
	cTropaMago * tropaMago;
	int eliminar=1;

	if (claseTAtacada == "CABALLERO")
	{
		tropaCaballero = ListaTropasCaballeros->getItem(ntropa);
		eliminar = tropaCaballero->RecibirAtaqueTropa(dano, claseTAtacante);

		if (eliminar == 0)
		{
			ListaTropasCaballeros->Eliminar(ntropa);
			cout << endl << "---------Tropa Eliminada------" << endl << endl;

			if (ListaTropasCaballeros->getCA() == 0 && ListaTropasArquero->getCA() == 0 && ListaTropasMago->getCA() == 0)
			{
				
				return (1);

			}
		
		}
		else
		{
			return (0);
		}
		

	}
	else if (claseTAtacada == "ARQUERO")
	{
		tropaArquero = ListaTropasArquero->getItem(ntropa);
		eliminar = tropaArquero->RecibirAtaqueTropa(dano, claseTAtacante);

		if (eliminar == 0)
		{
			ListaTropasArquero->Eliminar(ntropa);
			cout << endl << "---------Tropa Eliminada------" << endl;
			if (ListaTropasCaballeros->getCA() == 0 && ListaTropasArquero->getCA() == 0 && ListaTropasMago->getCA() == 0)
			{

				return (1);

			}
			else
			{
				return (0);
			}
			
		}
		else
		{
			return (0);
		}

		
	}
	else if (claseTAtacada == "MAGO") 
	{
		tropaMago = ListaTropasMago->getItem(ntropa);
		eliminar = tropaMago->RecibirAtaqueTropa(dano, claseTAtacante);

		if (eliminar == 0)
		{
			ListaTropasMago->Eliminar(ntropa);
			cout << endl << "---------Tropa Eliminada------" << endl;
			if (ListaTropasCaballeros->getCA() == 0 && ListaTropasArquero->getCA() == 0 && ListaTropasMago->getCA() == 0)
			{

				return (1);

			}
			else
			{
				return (0);
			}
		}
		else
		{
			return (0);
		}
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
		cout << "\t";
		ListaTropasCaballeros->Listar();
		cout << endl;
	}

	if (ListaTropasArquero->getCA() != 0)
	{
		cout << "\t";
		ListaTropasArquero->Listar();
		cout << endl;
	}
	
	if (ListaTropasMago->getCA() != 0)
	{
		cout << "\t";
		ListaTropasMago->Listar();
		cout << endl;
	}
	
	
}

void cPais::printTodos()
{
	listaPaises->Listar();
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

