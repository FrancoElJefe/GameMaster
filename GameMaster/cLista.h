#pragma once
#define NMAX 100

#include <string>
#include <iostream>
using namespace std;

template<class tipodato>
class cLista
{

	tipodato **vector;
	unsigned int CA, TAM;
	void Redimensionalizar();

public:

	cLista(unsigned int TAM = NMAX);
	~cLista();

	bool AgregarItem(tipodato *item);

	//bool AgregarItemOrdenado(tipodato *item);

	tipodato* Quitar(string codigo);
	tipodato* Quitar(tipodato *item);
	tipodato* QuitarenPos(unsigned int pos);

	void Eliminar(string codigo);
	void Eliminar(tipodato *item);
	void Eliminar(unsigned int pos);


	void Listar();
	void ListarV();
	void ListarParaAtacar(string nombre);

	tipodato* AtacarVecino(string nombre, int N);

	tipodato* BuscarItem(string codigo);
	tipodato* getItem(unsigned int pos);

	unsigned int getItemPos(string codigo);

	void OrdenarPorHp();

	int getCA() { return CA; }

};

template<class tipodato>
void cLista<tipodato>::Redimensionalizar()
{
}


template<class tipodato>
cLista<tipodato>::cLista(unsigned int TAM)
{
	vector = new tipodato*[TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;


}
template<class tipodato>
cLista<tipodato>::~cLista()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}


}

template<class tipodato>
void cLista<tipodato>::Listar()
{

	for (unsigned int i = 0; i < CA; i++)
	{
		cout << i + 1;
		cout << ") "; //imprime la posicion

		vector[i]->PrintA();// imprimir
	}
}
template<class tipodato>
inline void cLista<tipodato>::ListarV()
{
	for (unsigned int i = 0; i < CA; i++)
	{
		cout << i+1 << ") ";

		vector[i]->PrintNombre();// imprimir
		vector[i]->PrintTropas();
	}
}
template<class tipodato>
inline void cLista<tipodato>::ListarParaAtacar(string nombre)
{
	int jugador = 0, contador = 0;

	if (nombre == "Jugador 1")
	{
		jugador = 1;
	}
	else
	{
		jugador = 2;
	}

	for (unsigned int i = 0; i < CA; i++)
	{
		if ( jugador != vector[i]->getNjugador())
		{
			cout << contador + 1 << ") ";
			vector[i]->PrintNombre();// imprimir
			contador++;
		}
		
	}


}
template<class tipodato>
inline tipodato * cLista<tipodato>::AtacarVecino(string nombre , int N)
{
	int jugador = 0, contador = 0;

	if (nombre == "Jugador 1")
	{
		jugador = 1;
	}
	else
	{
		jugador = 2;
	}

	for (unsigned int i = 0; i < CA; i++)
	{
		if (jugador != vector[i]->getNjugador())
		{
			if (contador == N - 1)
			{
				return vector[i];
			}
			contador++;
			
		}

	}

}
/**/
template<class tipodato>
bool cLista<tipodato>::AgregarItem(tipodato * item)
{

	//tipodato *i_f = BuscarItem(item->getCodigo());
	//if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM) {
		vector[CA++] = item;
	}
	else throw new exception("No hay tamaño suficiente para agregar el item");;
	return true;
}
/*
bool cLista::AgregarItemOrdenado(tipodato * item)
{
for (unsigned int i = 0; i < CA; i++)
{
if (vector[i]->getCodigo() == codigo)
return vector[i];
}

return NULL;
}
*/
template<class tipodato>
tipodato* cLista<tipodato>::Quitar(string codigo) {

	unsigned int pos = getItemPos(codigo);
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);

}
template<class tipodato>
tipodato* cLista<tipodato>::Quitar(tipodato *item) {
	unsigned int pos = getItemPos(item->getCodigo());
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);
}
template<class tipodato>
tipodato* cLista<tipodato>::QuitarenPos(unsigned int pos) {

	if (pos >= CA)throw new exception("Posicion invalida");

	tipodato *aux = vector[pos];

	for (unsigned int i = 0; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}

template<class tipodato>
void cLista<tipodato>::Eliminar(string codigo) {

	unsigned int pos = getItemPos(codigo);

	if (pos < CA)
		Eliminar(pos);
	//sino algo

}
template<class tipodato>
void cLista<tipodato>::Eliminar(tipodato *item) {

	Eliminar(item->getCodigo());
}
template<class tipodato>
void cLista<tipodato>::Eliminar(unsigned int pos) {
	if (pos >= CA)return;// o Throw no pude eliminar

	tipodato *dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
	else
	{
		throw new exception("no encontrado");
	}
}

template<class tipodato>

tipodato * cLista<tipodato>::BuscarItem(string codigo)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getCodigo() == codigo)
			return vector[i];
	}
	return NULL;
}

template<class tipodato>
tipodato * cLista<tipodato>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}

template<class tipodato>
unsigned int cLista<tipodato>::getItemPos(string codigo)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getCodigo() == codigo)
			return i;
	}

	return INT_MAX;
}
template<class tipodato>

inline void cLista<tipodato>::OrdenarPorHp() //ordena del menor a mayor
{
	for (int i = 0; i < CA; i++)
	{
		for (int k = 0; k < CA - 1; k++)
		{
			if (vector[k]->getHP() > vector[k+1]->getHP())
			{
				tipodato * aux;
				aux = vector[k];
				vector[k] = vector[k + 1];
				vector[k + 1] = aux;
			}
		}

	}
}
#pragma once
