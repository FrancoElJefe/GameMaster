#include <stdio.h>
#include "stdlib.h"
#include <ostream>
#include "cLista.h"
#include<time.h>
//**************************
#include "cTropaCaballero.h"
#include "cUnidadCaballero.h"
#include "cTropaMago.h"
#include "cUnidadMago.h"
#include "cTropaArquero.h"
#include "cUnidadArquero.h"
//**************************
#include "cJugador.h"
#include "cContinente.h"


void CrearContinenteConPaises();
void AsignarVecinos(); // esta funcion asigna los vecinos a los distintos paises
void AsignarPaisesAJugadores();

void InicializacionDeVaribales();
void EleccionDeUnidades(cJugador * jugadorX); //el jugador elecciona 50 unidades constituedas por las tres facciones 
void AgruparUnidadesEnTropas(cJugador * jugadorX, int Tcaballeros, int Tarqueros, int Tmagos); // el jugador agrupa sus unidades en 10 tropas
void GeneradorDeTropasParaJugador(cJugador * jugadorX, int Tcaballeros, int Tarqueros, int Tmagos); // se generan las tropas y se las da al jugador

void ImprimirMapa(void);
void ReglasDelJuego(void);

void AgregarTropasEnPais();
void Inicio(void);
void ModoDeJuego(void);

void inicioPrueba(void);

void ataque();
void cambio_de_ronda();
void Resultados();

//void ocultarCursor();

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

cJugador * Jugador1 = new cJugador("Jugador 1");
cJugador * Jugador2 = new cJugador("Jugador 2");

cContinente * Continente = new cContinente(16, "America");

int Turnos = 0, Rondas = 0, IteradorDeRondas = 0;

int MaxUnidades = 0, caballeros = 0, magos = 0, arqueros = 0, opcion = 0, aux = 0, sobrecarga = 0, suma = 0; // variables de EleccionDeUnidades 

int TropasJugador1[10],TropasJugador2[10], NrTropa=0, Tcaballeros1=0, Tmagos1=0, Tarqueros1=0, Tcaballeros2 = 0, Tmagos2 = 0, Tarqueros2 = 0; // variables de AgruparUnidadesEnTropas , reutilizo el aux, opcion y MaxUnidades

int main(void) {
		
	srand(time(NULL));

	//Inicio(); //se crean el continente con los paises y los dos jugadores eligen las unidades y distribuyen las tropas

	inicioPrueba(); //se crean los paises en continente y luego se le asignana a cada jugador automaticamente, luego se crean tropas y se distribuyen en cada pais
					//es una funcion de prueba para poder probar los ataques

	do
	{

		ataque();

		if (IteradorDeRondas == 1)
		{
			Rondas--;
			if (Rondas == 0)
			{
				Turnos = 1;
			}
		}

		cambio_de_ronda();
		

	} while (Turnos != 1);
		

	Resultados();
		

	delete Jugador1;
	delete Jugador2;
	delete Continente;
	

	return 0;
}



void EleccionDeUnidades(cJugador * jugadorX)
{
	InicializacionDeVaribales();
	do
	{
		cout << "---------" << endl;
		cout << jugadorX->getNombre() << endl;
		cout << "---------" << endl << endl;
		cout << "Eleccion de Unidades: (MaxUnidades 50) // Unidades ACTUALES: " << MaxUnidades << endl << endl;
		cout << "1) 10-20 unidades si son"; 

		SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
		cout << " caballeros";
		SetConsoleTextAttribute(consoleHandle, 7);

		cout << endl << "2) 15 - 30 unidades si son";
		SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
		cout << " arqueros";
		SetConsoleTextAttribute(consoleHandle, 7);
		
		cout << endl << "3) 20 - 40 unidades si son";
		SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
		cout << " magos";
		SetConsoleTextAttribute(consoleHandle, 7);

		cout << endl << endl;

		SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
		cout << "Caballeros ";
		SetConsoleTextAttribute(consoleHandle, 7);
		cout << ": " << caballeros << endl;

		SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
		cout << "Arqueros ";
		SetConsoleTextAttribute(consoleHandle, 7);
		cout << ": " << arqueros << endl;

		SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
		cout << "Magos ";
		SetConsoleTextAttribute(consoleHandle, 7);
		cout << ": " << magos << endl << endl;
		
		cout << "Opcion: ";
		cin.clear();
		cin >> opcion;
		if (opcion == 0)
			getchar();

		if (opcion == 1)
		{
			if (caballeros != 20)
			{
				aux = caballeros;

				do
				{
					suma = 0;
					cout << "Cantidad de Caballeros: ";
					cin.clear();
					cin >> suma;
					if(suma==0)getchar();

					suma = suma + aux;
					sobrecarga = MaxUnidades + suma - aux;
					if (sobrecarga > 50)suma = 30;
										
				} while (suma > 20 );

				if (suma > 0)
				{
					MaxUnidades = MaxUnidades + suma - aux;
					caballeros = caballeros + suma - aux;
				}
				
			}
			else
			{
				cout << "Maxima unidades de Caballeros" << endl;
				getchar();
			}

		}
		else if (opcion == 2)
		{
			if (arqueros != 30)
			{
				aux = arqueros;
				do
				{
					suma = 0;
					cout << "Cantidad de Arqueros: ";
					cin.clear();
					cin >> suma;
					if (suma == 0)getchar();
					suma = suma + aux;
					sobrecarga = MaxUnidades + suma - aux;
					if (sobrecarga > 50)suma = 40;
				} while (suma > 30);

				if (suma > 0)
				{
					MaxUnidades = MaxUnidades + suma - aux;
					arqueros = arqueros + suma - aux;
				}
				
			}
			else
			{
				cout << "Maxima unidades de Arqueros" << endl;
				getchar();
			}

		}
		else if (opcion == 3)			
		{
			if (magos != 40)
			{
				aux = magos;
				do
				{
					suma = 0;
					cout << "Cantidad de Magos: ";
					cin.clear();
					cin >> suma;
					if (suma == 0)getchar();
					suma = suma + aux;
					sobrecarga = MaxUnidades + suma - aux;
					if (sobrecarga > 50)suma = 70;

				} while (suma > 40);

				if (suma > 0)
				{
					MaxUnidades = MaxUnidades + suma - aux;
					magos = magos + suma - aux;
				}
			}
			else
			{
				cout << "Maxima unidades de Magos" << endl;
				getchar();
			}			
			
		}

		system("cls");

		if (MaxUnidades == 50)
		{
			if (magos == 0 || arqueros == 0 || caballeros == 0)
			{
				system("cls");
				cout << "Se debe tener unidades de las tres clases, Reingrese." << endl << endl;
				NrTropa = 0;
				caballeros = 0;
				arqueros = 0;
				magos = 0;
				MaxUnidades = 0;
				system("pause");
				system("cls");
			}
			else if (magos < 20 || arqueros < 15 || caballeros < 10)
			{
				system("cls");
				cout << "Se debe tener por lo menos:" << endl << "-10 unidades de caballeros" << endl << "-15 unidades de arqueros" << endl << "-20 unidades de mago" << endl << "Reingrese" << endl << endl;
				NrTropa = 0;
				caballeros = 0;
				arqueros = 0;
				magos = 0;
				MaxUnidades = 0;
				system("pause");
				system("cls");
			}
		}
		

	} while (MaxUnidades != 50);

	system("cls");

}

void AgruparUnidadesEnTropas(cJugador * jugadorX, int Tcaballeros, int Tarqueros, int Tmagos)
{
	int check=0,numero=0, Tropas[10];

	MaxUnidades = caballeros;
	aux = arqueros;
	opcion = magos;
	   
	do
	{
		caballeros = MaxUnidades;
		arqueros = aux;
		magos = opcion;

		for (int i = 0; i < 10; i++)
		{
			
			cout << "Armado de las tropas: " << endl << endl;

			cout << "---------" << endl;
			cout << jugadorX->getNombre() << endl;
			cout << "---------" << endl << endl;

			SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
			cout << "Caballeros";
			SetConsoleTextAttribute(consoleHandle, 7);
			cout << ": " << caballeros << endl;
			SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
			cout << "Arqueros";
			SetConsoleTextAttribute(consoleHandle, 7);
			cout << ": " << arqueros << endl;
			SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
			cout << "Magos";
			SetConsoleTextAttribute(consoleHandle, 7);
			cout << ": " << magos << endl << endl;

			if (caballeros != 0)
			{
				do
				{
					numero = 0;
					SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
					cout << "Caballeros";
					SetConsoleTextAttribute(consoleHandle, 7);
					cout << ": " << endl;
					cout << "Tropa Nr " << i + 1 << ":";
					cin.clear();
					cin >> numero;
					if (numero == 0) {
						getchar();
						
					}
					else if(numero !=0 && numero <= caballeros)
					{
						Tropas[i] = numero;
					}
					else
					{
						if (caballeros - Tropas[i] < 0)Tropas[i] = -1;
					}
					
				} while (Tropas[i] <= 0);
				NrTropa++;
				caballeros = caballeros - Tropas[i];
				Tcaballeros++;
			}
			else if (arqueros != 0)
			{
				do
				{
					numero = 0;
					SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
					cout << "Arqueros";
					SetConsoleTextAttribute(consoleHandle, 7);
					cout << ": " << endl;
					cout << "Tropa Nr " << i + 1 << ":";
					cin.clear();
					cin >> numero;
					if (numero == 0) {
						getchar();
					}
					else if(numero!=0 && numero <= arqueros)
					{
						Tropas[i] = numero;
					}
					else
					{
						if (arqueros - Tropas[i] < 0)Tropas[i] = -1;
					}
					
				} while (Tropas[i] <= 0);
				NrTropa++;
				Tarqueros++;
				arqueros = arqueros - Tropas[i];
			}
			else if (magos != 0)
			{
				do
				{
					numero = 0;
					SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
					cout << "Magos";
					SetConsoleTextAttribute(consoleHandle, 7);
					cout << ": " << endl;
					cout << "Tropa Nr " << i + 1 << ":";
					cin.clear();
					cin >> numero;
					if (numero == 0) {
						getchar();
					}
					else if(numero!=0 && numero <= magos)
					{
						Tropas[i] = numero;
					}
					else
					{
						if (magos - Tropas[i] < 0)Tropas[i] = -1;
					}							
				} while (Tropas[i] <= 0);
				NrTropa++;
				Tmagos++;
				magos = magos - Tropas[i];
			}

			check = check + Tropas[i];
			system("cls");

		}//FOR
		

		if (check != 50)
		{
			cout << endl << endl;
			SetConsoleTextAttribute(consoleHandle,FSCTL_GET_INTEGRITY_INFORMATION);
			cout << "Se debe tener 10 tropas, reingrese"; 
			SetConsoleTextAttribute(consoleHandle, 7);
			cout << endl << endl;
			check = 0;
			Tcaballeros = 0;
			Tarqueros = 0;
			NrTropa = 0;
			Tmagos = 0;
			system("pause");
			system("cls");
		}

	} while (check != 50);

	if (jugadorX->getNombre() == "Jugador 1")
	{
		Tcaballeros1 = Tcaballeros;
		Tarqueros1 = Tarqueros;
		Tmagos1 = Tmagos;

		for (int i = 0; i < 10; i++)
		{
			TropasJugador1[i] = Tropas[i];
		}
	}
	else
	{
		Tcaballeros2 = Tcaballeros;
		Tarqueros2 = Tarqueros;
		Tmagos2 = Tmagos;
		for (int i = 0; i < 10; i++)
		{
			TropasJugador2[i] = Tropas[i];
		}
	}

	system("cls");

	

	
}

void GeneradorDeTropasParaJugador(cJugador * jugadorX, int Tcaballeros, int Tarqueros, int Tmagos)
{
	int Tropas[10];
	cout << endl;

	if (jugadorX->getNombre() == "Jugador 1")
	{
		for (int i = 0; i < 10; i++)
		{
			Tropas[i] = TropasJugador1[i];
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			Tropas[i] = TropasJugador2[i];
		}
	}
	
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
	cout << "Caballeros";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ": " << endl;
	for (int i = 0; i < Tcaballeros; i++)
	{   
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;
		jugadorX->AgregarTropaCaballero(new cTropaCaballero, Tropas[i]);
	}
	cout << endl;
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
	cout << "Arqueros";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ": " << endl;
	for (int i = Tcaballeros; i < Tarqueros + Tcaballeros; i++)
	{
		
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;
		jugadorX->AgregarTropaArquero(new cTropaArquero, Tropas[i]);
	}
	cout << endl;
	
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
	cout << "Magos";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ": " << endl;
	for (int i = Tarqueros + Tcaballeros; i < Tmagos + Tcaballeros + Tarqueros; i++)
	{	
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;
		jugadorX->AgregarTropaMago(new cTropaMago, Tropas[i]);
	}
	system("Pause");
	system("cls");
}

void ImprimirMapa(void)
{
	cPais * pais = NULL;
	int Npais[16];

	for (int i = 0; i < 16; i++)
	{
		pais = Continente->BuscarPais(i);
		Npais[i] = pais->getNjugador();
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

void ReglasDelJuego(void)
{
	cout << "---------------------------------------------" << endl;
	cout << "El juego se desarrolla de la siguiente forma:                               Felippelli - Pizarro - Chocano" << endl;
	cout << "---------------------------------------------" << endl << endl;
	cout << "Se distribuyen los 16 paises de America de manera aleatoria entre los dos jugadores, recibiendo ocho cada uno." << endl;
	cout << "Existen tres tipos de unidades : ";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
	cout << "caballeros ";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ", ";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
	cout << "arqueros ";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << "y ";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
	cout << "magos";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << ". Cada unidad tiene su propia vida(HP) y su propio ataque(AT)." << endl << "La asignacion inicial de vida y ataque es asignada de manera aleatoria teniendo en cuenta los siguientes rangos : " << endl << endl;
	
	cout << "-";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
	cout << "Caballeros:" << endl << endl;
	SetConsoleTextAttribute(consoleHandle, 7);

	cout << "\tVida entre 80 y 100" << endl;
	cout << "\tAtaque entre 30 y 40" << endl << endl;

	cout << "-";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
	cout << "Arqueros:" << endl << endl;
	SetConsoleTextAttribute(consoleHandle, 7);

	cout << "\tVida entre 60 y 80" << endl;
	cout << "\tAtaque entre 20 y 30" << endl << endl;

	cout << "-";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
	cout << "Magos:" << endl << endl;
	SetConsoleTextAttribute(consoleHandle, 7);

	cout << "\tVida entre 40 y 60" << endl;
	cout << "\tAtaque entre 10 y 20" << endl << endl;

	system("Pause"); 
	system("cls");

	cout << "Una vez asignados los paises, cada jugador debe seleccionar 50 unidades entre caballeros magos y arqueros." << endl;
	SetConsoleTextAttribute(consoleHandle, FSCTL_GET_INTEGRITY_INFORMATION);
	cout << "Es obligatorio tener unidades de los tres tipos.";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << endl << "Luego se forman diez tropas no mixtas utilizando todas las unidades seleccionadas." << endl << endl;
	cout << "Consideraciones para el armado de tropas :" << endl<<endl;
	cout << "\t-Los ";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE);
	cout << "caballeros "; 
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << "son mas fuertes que los arqueros." << endl;
	cout << "\t-Los ";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
	cout << "arqueros ";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << "son mas fuertes que los magos." << endl;
	cout << "\t-Los ";
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED);
	cout << "magos ";
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << "son mas fuertes que los caballeros." << endl << endl;
	cout << "[Cuando una clase fuerte ataca a una debil, el ataque aumenta en un 25 % . Al contrario, el ataque disminuye un 25 %]" << endl << endl;

	SetConsoleTextAttribute(consoleHandle, EVENT_SYSTEM_FOREGROUND);
	cout << "****Los arqueros pueden aleatoriamente atacar una segunda vez, con un 50 % de aumento de dano****" << endl;
	cout << "****Los caballeros poseen un contraataque del 25 % cada vez que se los ataca****" << endl;
	cout << "****Los magos atacan en zona, por lo que atacan a todas las unidades enemigas ubicadas en el pais****" << endl;
	SetConsoleTextAttribute(consoleHandle, 7);
	
	system("Pause");
	system("cls");

	cout << "Por Ultimo" << endl << endl;
	cout << "*Ataques:" << endl << endl;
	SetConsoleTextAttribute(consoleHandle, EVENT_SYSTEM_FOREGROUND);
	cout << "En cada turno, el jugador puede realizer hasta tres ataques." << endl;
	SetConsoleTextAttribute(consoleHandle, 7);
	cout << "Para atacar, debe seleccionar a partir de una lista que pais vecino enemigo atacar, y desde que pais propio(debe tener dos tropas o mas)." << endl << "Se ataca primero a las unidades mas debiles(menor HP), absorbiendo parte del dano y pasando el resto del dano a las unidades siguientes." << endl << endl;
	cout << "En pantalla se muestran cuantas unidades fueron eliminadas y si se elimino la ultima unidad de una tropa." << endl<<endl;
	cout << "Al terminar cada ataque, se reasignan los paises ganados si fuera necesario,";
	SetConsoleTextAttribute(consoleHandle, FSCTL_GET_INTEGRITY_INFORMATION);
	cout << " y es obligatorio pasarle alguna tropa." << endl;
	SetConsoleTextAttribute(consoleHandle, 7);
	system("Pause");
	system("cls");
	
		
}

void CrearContinenteConPaises()
{
	string NomPaises[16] = {"Argentina", "Chile", "Uruguay" , "Brasil", "Peru", "Colombia", "Mexico", "California", "Oregon" , "Alaska", "Yukon", "Canada", "Nueva York", "Terranova", "Labrador", "Groenlandia"};

	Continente->AgregarPaises(&NomPaises[0]);
}

void AsignarVecinos()
{
	string Vargentina[4] = { "Chile", "Uruguay", "Brasil", "Peru" };
	string Vchile[3] = { "Peru", "Argentina", "Groenlandia" };
	string Vuruguay[2] = { "Argentina", "Brasil" };
	string Vbrasil[4] = { "Argentina", "Uruguay", "Colombia", "Peru" };
	string Vperu[4] = { "Chile", "Argentina", "Brasil", "Colombia" };
	string Vcolombia[3] = { "Mexico", "Brasil", "Peru" };
	string Vmexico[2] = { "California", "Colombia" };
	string Vcalifornia[3] = { "Nueva York", "Oregon", "Mexico" };
	string Voregon[5] = { "Yukon", "Alaska", "Canada", "Nueva York", "California" };
	string Valaska[2] = { "Yukon", "Oregon" };
	string Vyukon[3] = { "Alaska", "Canada", "Oregon" };
	string Vcanada[4] = { "Terranova", "Nueva York", "Oregon", "Yukon" };
	string Vnuevayork[4] = { "Terranova", "Canada", "Oregon", "California" };
	string Vterranova[3] = { "Labrador", "Canada", "Nueva York" };
	string Vlabrador[2] = { "Groenlandia", "Terranova" };
	string Vgroenlandia[3] = { "Labrador", "Nueva York", "Chile" };

	Continente->AsignarVecinos("Argentina", &Vargentina[0], 4);
	Continente->AsignarVecinos("Chile", &Vchile[0], 3);
	Continente->AsignarVecinos("Uruguay", &Vuruguay[0], 2);
	Continente->AsignarVecinos("Brasil", &Vbrasil[0], 4);
	Continente->AsignarVecinos("Peru", &Vperu[0], 4);
	Continente->AsignarVecinos("Colombia", &Vcolombia[0], 3);
	Continente->AsignarVecinos("Mexico", &Vmexico[0], 2);
	Continente->AsignarVecinos("California", &Vcalifornia[0], 3);
	Continente->AsignarVecinos("Oregon", &Voregon[0], 5);
	Continente->AsignarVecinos("Alaska", &Valaska[0], 2);
	Continente->AsignarVecinos("Yukon", &Vyukon[0], 3);
	Continente->AsignarVecinos("Canada", &Vcanada[0], 4);
	Continente->AsignarVecinos("Nueva York", &Vnuevayork[0], 4);
	Continente->AsignarVecinos("Terranova", &Vterranova[0], 3);
	Continente->AsignarVecinos("Labrador", &Vlabrador[0], 2);
	Continente->AsignarVecinos("Groenlandia", &Vgroenlandia[0], 3);
	
}

void AsignarPaisesAJugadores()
{
	int num, check=0, paisesDeJugador1[8];

	for (int i = 0; i < 8; i++)
	{
		num = rand() % 16;

		check = Jugador1->AgregarPais(Continente->BuscarPais(num));

		if (check == 1)
		{
			i--;
		}
		else
		{
			paisesDeJugador1[i] = num;
		}

	}

	check = 0;
	
	for (int i = 0; i < Continente->getCaLista(); i++)
	{
		for (int k = 0; k < (Continente->getCaLista())/2 ; k++)
		{
			if (i == paisesDeJugador1[k])
			{
				check++;
			}
		}

		if (check == 0)
		{
			Jugador2->AgregarPais(Continente->BuscarPais(i));
		}
		else
		{
			check = 0;
		}
				
	}


}

void InicializacionDeVaribales()
{
	MaxUnidades = 0;
	caballeros = 0;
	magos = 0;
	arqueros = 0;
	opcion = 0;
	aux = 0;
	sobrecarga = 0;
	suma = 0;
	NrTropa = 0;
	
}

void AgregarTropasEnPais()
{
	Jugador1->setTropaEnPais();
	Jugador2->setTropaEnPais();
}

void Inicio(void)
{
	CrearContinenteConPaises(); //se le agregan los paises al continente
	AsignarVecinos();//se le agregan los vecinos a cada pais
	AsignarPaisesAJugadores(); // se le agregan los paises a cada jugador

	ReglasDelJuego();//se explican las reglas

	ModoDeJuego();//se elige jugar por rondas o hasta conquistar el continente
	
	EleccionDeUnidades(Jugador1); //el jugador 1 elige las unidades de caballeros, arqueros y magos
	AgruparUnidadesEnTropas(Jugador1,Tcaballeros1,Tarqueros1,Tmagos1); //el jugador 1 agrupa, a gusto, las unidades en 10 tropas
	GeneradorDeTropasParaJugador(Jugador1, Tcaballeros1, Tarqueros1, Tmagos1);//se arman las tropas en el jugador 1
			   
	EleccionDeUnidades(Jugador2); //el jugador 1 elige las unidades de caballeros, arqueros y magos
	AgruparUnidadesEnTropas(Jugador2, Tcaballeros2, Tarqueros2, Tmagos2); //el jugador 1 agrupa, a gusto, las unidades en 10 tropas
	GeneradorDeTropasParaJugador(Jugador2, Tcaballeros2, Tarqueros2, Tmagos2); //se arman las tropas en el jugador 1
		
	AgregarTropasEnPais(); //ubican las tropas donde quiere cada jugador

	
}

void ModoDeJuego(void)
{
	string opcion;
	int check = 0;

	do
	{
		system("cls");
		if (check == 0)
		{
			cout << "Si quiere jugar a cierto numero de rondas escriba RONDAS, de lo contrario, si quiere jugar hasta conquistar el continente escriba CONQUISTAR" << endl<< endl;
			cout << ": ";
			cin >> opcion;
		}
		else
		{
			cout << "Si quiere jugar a cierto numero de rondas escriba RONDAS, de lo contrario, si quiere jugar hasta conquistar el continente escriba CONQUISTAR" << endl<< endl;
			cout << ": " << opcion << endl;
		}


		if (opcion == "conquistar" || opcion == "CONQUISTAR")
		{
			IteradorDeRondas = 0;
			Rondas = 1;
		}
		else if (opcion == "rondas" || opcion == "RONDAS")
		{
			cout << "ingrese la cantidad de rondas: ";
			cin.clear();
			cin >> Rondas;
			if (Rondas == 0)
			{
				getchar();
				Rondas = 0;
				check = 1;
			}
			else if (Rondas != 0 && Rondas >0)
			{
				IteradorDeRondas = 1;
			}
		}

	} while (Rondas == 0);

	system("cls");
}

void inicioPrueba(void)
{
	
	ModoDeJuego();
	

	int Tropas[10];
	CrearContinenteConPaises(); //se le agregan los paises al continente
	AsignarVecinos();//se le agregan los vecinos a cada pais
	AsignarPaisesAJugadores(); // se le agregan los paises a cada jugador
	InicializacionDeVaribales();

	caballeros = 20;
	arqueros = 10;
	magos = 20;
	int Tcaballeros = 4;
	int Tarqueros = 3;
	int Tmagos = 3;

	Tcaballeros1 = Tcaballeros;
	Tarqueros1 = Tarqueros;
	Tmagos1 = Tmagos;


	for (int i = 0; i < Tcaballeros; i++)
	{
		TropasJugador1[i] = 5;
	}
	for (int i = Tcaballeros; i < Tcaballeros + arqueros; i++)
	{
		
			TropasJugador1[i] = 5;
		
		
	}
	for (int i = Tcaballeros + arqueros; i < Tcaballeros + Tmagos + Tarqueros; i++)
	{
	
		TropasJugador1[i] = 5;
		
	}
	
	GeneradorDeTropasParaJugador(Jugador1,Tcaballeros,Tarqueros,Tmagos);
	Jugador1->setTropasEnPaisesPrueba(Tcaballeros, Tarqueros, Tmagos);

	system("cls");

	caballeros = 10;
	arqueros = 20;
	magos = 20;
	Tcaballeros = 2;
	Tarqueros = 4;
	Tmagos = 4;

	Tcaballeros2 = Tcaballeros;
	Tarqueros2 = Tarqueros;
	Tmagos2 = Tmagos;

	for (int i = 0; i < Tcaballeros; i++)
	{
		TropasJugador2[i] = 10;
	}
	for (int i = Tcaballeros; i < Tcaballeros + Tarqueros; i++)
	{
		TropasJugador2[i] = 5;
	}
	for (int i = Tcaballeros + Tarqueros; i < Tcaballeros + Tarqueros + Tmagos; i++)
	{
		
		TropasJugador2[i] = 5;
		
	}

	GeneradorDeTropasParaJugador(Jugador2, Tcaballeros, Tarqueros, Tmagos);
	Jugador2->setTropasEnPaisesPrueba(Tcaballeros, Tarqueros, Tmagos);

	system("cls");




}

void ataque()
{

	string pais;

	
	for (int i = 0; i < 3; i++)
	{
		system("cls");
		//ImprimirMapa();
		pais = Jugador1->AtacarPais();
		if (pais == "atras")
		{
			i--;
		}
		else if (pais != "0")
		{
			Jugador1->AgregarPais(Jugador2->quitarPais(pais));
		}

	}

	pais = "0";

	for (int i = 0; i < 3; i++)
	{
		system("cls");
		//ImprimirMapa();
		pais = Jugador2->AtacarPais();
		if (pais == "atras")
		{
			i--;
		}
		else if (pais != "0")
		{
			Jugador2->AgregarPais(Jugador1->quitarPais(pais));
		}

	}

	

	

}

void cambio_de_ronda()
{

	int NPaises = 0, N=0, PaisesADar = 0;

	if (Turnos == 0)
	{

		NPaises = Jugador1->getNumeroDePaises();

		if (NPaises != 0)
		{

			if (NPaises != 16)
			{

				PaisesADar = NPaises / 2;

				if (PaisesADar == 0)
				{
					PaisesADar = 2;
				}
				else if (PaisesADar > 12)
				{
					PaisesADar = 6;
				}

				for (int i = 0; i < PaisesADar; i++)
				{
					N = rand() % 3;

					if (N == 0) //caballero
					{
						Jugador1->AgregarTropaCaballero(new cTropaCaballero, TropasJugador1[rand() % Tcaballeros1]);
					}
					else if (N == 1)//arquero
					{
						Jugador1->AgregarTropaArquero(new cTropaArquero, TropasJugador1[Tcaballeros1 + rand() % (Tarqueros1)]);
					}
					else if (N == 2)//mago
					{
						Jugador1->AgregarTropaMago(new cTropaMago, TropasJugador1[(Tcaballeros1 + Tarqueros1) + rand() % (Tmagos1)]);
					}

				}

				NPaises = Jugador2->getNumeroDePaises();

				PaisesADar = NPaises / 2;

				if (PaisesADar == 0)
				{
					PaisesADar = 2;
				}
				else if (PaisesADar > 12)
				{
					PaisesADar = 6;
				}


				for (int i = 0; i < PaisesADar; i++)
				{
					N = rand() % 3;

					if (N == 0) //caballero
					{
						Jugador2->AgregarTropaCaballero(new cTropaCaballero, TropasJugador2[rand() % Tcaballeros2 + 1]);
					}
					else if (N == 1)//arquero
					{
						Jugador2->AgregarTropaArquero(new cTropaArquero, TropasJugador2[Tcaballeros2 + rand() % (Tarqueros2 + 1)]);
					}
					else if (N == 2)//mago
					{
						Jugador2->AgregarTropaMago(new cTropaMago, TropasJugador2[(Tcaballeros2 + Tarqueros2) + rand() % (Tmagos2 + 1)]);
					}

				}

				AgregarTropasEnPais();
			}
			else
			{
				Turnos = 1;
			}

		}
		else
		{
			Turnos = 1;
		}


	}

	
}

void Resultados()
{
	system("cls");

	if (IteradorDeRondas == 1)
	{
		if (Jugador1->getNumeroDePaises() > Jugador2->getNumeroDePaises())
		{
			cout << "*********************************" << endl;
			cout << "El Jugador 1 gano, Felicitaciones" << endl;
			cout << "*********************************" << endl;
		}
		else if (Jugador1->getNumeroDePaises() > Jugador2->getNumeroDePaises())
		{
			cout << "*********************************" << endl;
			cout << "El Jugador 2 gano, Felicitaciones" << endl;
			cout << "**********************************" << endl;
		}
		else
		{
			cout << "***************************************************" << endl;
			cout << "Se determino que el jugador 1 y jugador 2 empataron" << endl;
			cout << "***************************************************" << endl;
		}

	}
	else
	{
		if (Jugador1->getNumeroDePaises() == 16)
		{
			cout << "**********************************************" << endl;
			cout << "El Jugador 1 conquisto America, Felicitaciones" << endl;
			cout << "**********************************************" << endl;
			
		}
		else
		{
			cout << "**********************************************" << endl;
			cout << "El Jugador 2 conquisto America, Felicitaciones" << endl;
			cout << "**********************************************" << endl;
		}

	}


	system("Pause");
}

void ocultarCursor()
{
	/*
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
	
	//CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	//GetConsoleScreenBufferInfo(consoleHandle, ConsoleInfo);
	//WORD OriginalColors = ConsoleInfo->wAttributes;
	//SetConsoleTextAttribute(consoleHandle, 5);
	*/
	//EVENT_SYSTEM_FOREGROUND -- celeste
	//FSCTL_GET_INTEGRITY_INFORMATION -- se usa para textos que requierean atencion
	//5 -- purpura
	//6 -- naranja 
	//4 -- rojo 
	//14 -- descolorado
}
