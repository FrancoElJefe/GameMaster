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

void EleccionDeUnidades(void);
void AgruparUnidadesEnTropas(void);
void GeneradorDeTropasParaJugador(void);


//para probar la lista de tropas
cLista<cTropaCaballero> * listaTropaCaballero = new cLista<cTropaCaballero>;
cLista<cTropaArquero> * listaTropaArquero = new cLista<cTropaArquero>;
cLista<cTropaMago> * listaTropaMago = new cLista<cTropaMago>;

int MaxUnidades = 0, caballeros = 0, magos = 0, arqueros = 0, opcion = 0, aux = 0, sobrecarga = 0, suma = 0; // variables de EleccionDeUnidades 

int Tropas[10], NrTropa=0, Tcaballeros=0, Tmagos=0, Tarqueros=0; // variables de AgruparUnidadesEnTropas , reutilizo el aux, opcion y MaxUnidades

int main(void) {
		

	//EleccionDeUnidades();

	//system("cls");

	caballeros = 12;
	arqueros = 18;
	magos = 20;

	AgruparUnidadesEnTropas();

	GeneradorDeTropasParaJugador();


		
	delete listaTropaArquero;
	delete listaTropaCaballero;
	delete listaTropaMago;

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
		cTropaCaballero * tropa = new cTropaCaballero;
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;

		for (int k = 0; k < Tropas[k]; k++)
		{
			tropa->AgregarUnidades(new cUnidadCaballero);

		}
		listaTropaCaballero->AgregarItem(tropa);
	}
	cout << endl;
	cout << "Arqueros: " << endl;
	for (int i = Tcaballeros; i < Tarqueros + Tcaballeros; i++)
	{
		cTropaArquero * tropa = new cTropaArquero;
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;

		for (int k = 0; k < Tropas[k]; k++)
		{
			tropa->AgregarUnidades(new cUnidadArquero);

		}
		listaTropaArquero->AgregarItem(tropa);
	}
	cout << endl;
	cout << "Magos: " << endl;
	for (int i = Tarqueros + Tcaballeros; i < Tmagos + Tcaballeros + Tarqueros; i++)
	{
		cTropaMago * tropa = new cTropaMago;
		cout << "Tropa Nr " << i + 1 << ": " << Tropas[i] << " Unidades" << endl;

		for (int k = 0; k < Tropas[k]; k++)
		{
			tropa->AgregarUnidades(new cUnidadMago);

		}
		listaTropaMago->AgregarItem(tropa);
	}

	system("pause");
}
