#include "cContinente.h"



cContinente::cContinente() : CantPaises(16), nombre("America")
{
	listaPaises = new cLista<cPais>(16);
}

cContinente::cContinente(int N, string nomb) : CantPaises(N), nombre(nomb)
{
	listaPaises = new cLista<cPais>(N);
}

void cContinente::AgregarPaises(string * ptr)
{
	for (int i = 0; i < CantPaises; i++)
	{
		listaPaises->AgregarItem(new cPais(ptr[i]));
	}
}

void cContinente::AsignarVecinos(string nomb,  string * ptr, int CV)
{
	cPais * pais = NULL;
	
	pais = listaPaises->BuscarItem(nomb);
	for (int i = 0; i <CV ; i++)
	{
		pais->AgregarVecinos(listaPaises->BuscarItem(ptr[i]));
	}
	
}

cPais * cContinente::BuscarPais(int n)
{
	return listaPaises->getItem(n);
}

void cContinente::ListarPaises()
{
	listaPaises->Listar();
}


cContinente::~cContinente()
{
	delete listaPaises;
}
