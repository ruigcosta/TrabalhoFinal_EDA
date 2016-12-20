#pragma once
#include <iostream>
#include <chrono>
#include "Lista.h"

using namespace std;

class ListaBinElem
{
	public:
		char letra;
		string binario;
		ListaBinElem *next;

		ListaBinElem()
		{ 
			letra = '\0';
			binario = "";
			next = NULL;
		}

		ListaBinElem (char parLetra, string parBinario )
		{
			this->letra = parLetra;
			this->binario = parBinario;
			this->next = NULL;
		}

		ListaBinElem( char parLetra, string parBinario, ListaBinElem* nextElem )
		{
			this->letra = parLetra;
			this->binario = parBinario;
			this->next = nextElem;
		}

		~ListaBinElem() {};

		void setNext( ListaBinElem* nextItem )
		{
			this->next = nextItem;
		}
		
		void print( )
		{
			cout << this->letra << ", " << this->binario;
		}

private:

};



class ListaBin
{
public:
	ListaBinElem *head;
	ListaBinElem *tail;

	ListaBin()
	{
		head = tail = NULL;
	};

	~ListaBin() {};

	void addElement( char parLetra, string parBinario )
	{
		ListaBinElem* novo = new ListaBinElem( parLetra, parBinario );
		novo->next = NULL; //Apenas por segurança, se a classe do elemeno for alterada
		if ( this->head == NULL )
		{
			this->head = this->tail = novo;
		}
		else
		{
			this->tail->next = novo;
			this->tail = novo;
		}
	}

	ListaBinElem* findElem( char parLetra )
	{
		ListaBinElem* actual = this->head;
		while ( actual != NULL )
		{
			if ( actual->letra == parLetra )
			{
				return actual;
			}
			else
			{
				actual = actual->next;
			}
		}
		return NULL;
	}

	ListaBinElem* findElem( string parBinario )
	{
		ListaBinElem* actual = this->head;
		while ( actual != NULL )
		{
			if ( actual->binario == parBinario )
			{
				return actual;
			}
			else
			{
				actual = actual->next;
			}
		}
		return NULL;
	}

	void printList()
	{
		ListaBinElem* elem = this->head;
		while ( elem != NULL )
		{
			elem->print();
			cout << endl;
		}
	}
	//Métodos necessários
		//Encontrar elemento
		//Adicionar elemento
		//Verificar se é necessário ordenar

	//ListaBinElem* addListaBinElem( char parLetra, string parBinario )
	//{
	//	ListaBinElem *novoItem = new ListaBinElem();
	//	novoItem->letra = parLetra;
	//	novoItem->binario = parBinario;

	//	return novoItem;
	//}


private:

};
