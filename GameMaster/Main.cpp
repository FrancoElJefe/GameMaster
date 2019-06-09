#include <stdio.h>
#include "stdlib.h"
#include <ostream>
#include "cLista.h"
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

void EleccionDeUnidades(void);
void AgruparUnidadesEnTropas(void);
void GeneradorDeTropasParaJugador(void);
void CrearContinenteConPaises();
void AsignarVecinos(); // esta funcion asigna los vecinos a los distintos paises

cContinente * Continente = new cContinente(16, "America");

int MaxUnidades = 0, caballeros = 0, magos = 0, arqueros = 0, opcion = 0, aux = 0, sobrecarga = 0, suma = 0; // variables de EleccionDeUnidades 

int Tropas[10], NrTropa=0, Tcaballeros=0, Tmagos=0, Tarqueros=0; // variables de AgruparUnidadesEnTropas , reutilizo el aux, opcion y MaxUnidades

int main(void) {
		

	CrearContinenteConPaises();
	AsignarVecinos();

	Continente->ListarPaises();

	system("Pause");
	//EleccionDeUnidades();

	//system("cls");

	//caballeros = 12;
	//arqueros = 18;
	//magos = 20;

	//AgruparUnidadesEnTropas();

	//GeneradorDeTropasParaJugador();

	delete Continente;

	return 0;
}



void EleccionDeUnidades(void)
{
	do
	{
		cout << "Eleccion de Unidades: (MaxUnidades 50) // Unidades ACTUALES: " << MaxUnidades << endl << endl;
		cout << "1) 10-20 unidades si son caballeros" << endl << "2) 15 - 30 si son arqueros" << endl << "3) 20 - 40 si son magos" << endl << endl;
		cout << "Caballeros : " << caballeros << endl;
		cout << "Arqueros : " << arqueros << endl;
		cout << "Magos : " << magos << endl << endl;
		
		cout << "Opcion: ";

		cin >> opcion;
		if (opcion == 1)
		{
			if (caballeros != 20)
			{
				aux = caballeros;

				do
				{
					suma = 0;
					cout << "Cantidad de Caballeros: ";
					cin >> suma;
					suma = suma + aux;
					sobrecarga = MaxUnidades + suma - aux;
					if (sobrecarga > 50)suma = 30;
				} while (suma > 20 );
				MaxUnidades = MaxUnidades + suma - aux;
				caballeros = caballeros + suma - aux;
			}
			else
			{
				cout << "Maxima unidades de Caballeros" << endl;
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
					cin >> suma;
					suma = suma + aux;
					sobrecarga = MaxUnidades + suma - aux;
					if (sobrecarga > 50)suma = 40;
				} while (suma > 30);

				MaxUnidades = MaxUnidades + suma - aux;
				arqueros = arqueros + suma - aux;
			}
			else
			{
				cout << "Maxima unidades de Arqueros" << endl;
			}

		}
		else if (opcion == 3 && magos != 40)
		{
			aux = magos;
			do
			{
				suma = 0;
				cout << "Cantidad de Magos: ";
				cin >> suma;
				suma = suma + aux;
				sobrecarga = MaxUnidades + suma - aux;
				if (sobrecarga > 50)suma = 70;
								
			} while (suma > 40);
			MaxUnidades = MaxUnidades + suma - aux;
			magos = magos + suma - aux;
		}

		system("cls");

		if (magos != 0 || arqueros != 0 || caballeros != 0)
		{
			system("cls");
			cout << "Se debe tener 10 tropas, reingrese" << endl << endl;
			NrTropa = 0;
			system("pause");
			system("cls");
		}

	} while (NrTropa <= 9);

}

void AgruparUnidadesEnTropas(void)
{
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

			cout << "Caballeros : " << caballeros << endl;
			cout << "Arqueros : " << arqueros << endl;
			cout << "Magos : " << magos << endl << endl;

			if (caballeros != 0)
			{
				do
				{
					cout << "Caballeros: " << endl;
					cout << "Tropa Nr " << i + 1 << ":";
					cin >> Tropas[i];
	
					if (caballeros - Tropas[i] < 0)Tropas[i] = -1;
					
				} while (Tropas[i] <= 0);
				NrTropa++;
				caballeros = caballeros - Tropas[i];
				Tcaballeros++;
			}
			else if (arqueros != 0)
			{
				do
				{
					cout << "Arqueros: " << endl;
					cout << "Tropa Nr " << i + 1 << ":";
					cin >> Tropas[NrTropa];

					if (arqueros - Tropas[i] < 0)Tropas[i] = -1;

				} while (Tropas[i] <= 0);
				NrTropa++;
				Tarqueros++;
				arqueros = arqueros - Tropas[i];
			}
			else if (magos != 0)
			{
				do
				{
					cout << "Magos: " << endl;
					cout << "Tropa Nr " << i + 1 << ":";
					cin >> Tropas[i];

					if (magos - Tropas[i] < 0) {
						Tropas[i] = -1;
					}

				} while (Tropas[i] <= 0);
				NrTropa++;
				Tmagos++;
				magos = magos - Tropas[i];
			}

			system("cls");

		}//FOR

		if (NrTropa < 9)
		{
			system("cls");
			cout << "Se debe tener 10 tropas, reingrese estas "<< NrTropa << endl << endl;
			system("pause");
			system("cls");
		}

	} while (NrTropa < 9);

	system("cls");

	

	
}

void GeneradorDeTropasParaJugador(void)
{
	cout << endl;

	cout << "Caballeros: " << endl;
	for (int i = 0; i < Tcaballeros; i++)
	{   
		//cTropaCaballero * tropa = new cTropaCaballero;
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;

		for (int k = 0; k < Tropas[k]; k++)
		{
			//tropa->AgregarUnidades(new cUnidadCaballero);

		}
		//listaTropaCaballero->AgregarItem(tropa);
	}
	cout << endl;
	cout << "Arqueros: " << endl;
	for (int i = Tcaballeros; i < Tarqueros + Tcaballeros; i++)
	{
		cTropaArquero * tropa = new cTropaArquero;
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;

		for (int k = 0; k < Tropas[k]; k++)
		{
			//tropa->AgregarUnidades(new cUnidadArquero);

		}
		//listaTropaArquero->AgregarItem(tropa);
	}
	cout << endl;
	cout << "Magos: " << endl;
	for (int i = Tarqueros + Tcaballeros; i < Tmagos + Tcaballeros + Tarqueros; i++)
	{
		//cTropaMago * tropa = new cTropaMago;
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;

		for (int k = 0; k < Tropas[k]; k++)
		{
			//tropa->AgregarUnidades(new cUnidadMago);

		}
		//listaTropaMago->AgregarItem(tropa);
	}

	system("pause");
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
