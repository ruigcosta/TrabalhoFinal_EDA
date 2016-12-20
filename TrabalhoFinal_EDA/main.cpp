#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lista.h"
#include "Tree.h"
#include "ListaBin.h"

using namespace std;

int main() {

	string textoTeste = "";
	textoTeste += "Este ser� o texto de testes enquanto n�o colocamos as leituras de ficheiros a funcionar.";
	//Terminado este teste, vamos inserir as mudan�as de linha

	DoubleLinkedList lista;
	
	//Constru��o da Lista Ordenada e da �rvore de Huffman
	lista.addOrdered('o',5);
	lista.addOrdered(' ', 6);
	lista.addOrdered('p', 4);
	lista.addOrdered('d', 1);
	lista.addOrdered('a', 3);
	lista.addOrdered('l', 1);
	lista.addOrdered('e', 3);
	lista.addOrdered('v', 1);
	lista.addOrdered('b', 2);


	lista.mostraLista();
	
	while (lista.head != lista.tail) {
		Tree *left = lista.RemoveFirst();
		Tree *rigth = lista.RemoveFirst();

		DLListItem * novo = lista.addOrdered('\0', left->root->ocorrencia + rigth->root->ocorrencia);
		novo->data->root->left = left->root;
		novo->data->root->rigth = rigth->root;
	}

	lista.mostraLista();
	
	system("pause");

	//for ( int contChar = 0; contChar < textoTeste.length(); contChar++ )
	//{
	//	char caracter = textoTeste[contChar];
	//}
	ListaBinElem* xpto = new ListaBinElem( 'a', "1011001" );
	xpto->print();
	cout << endl;
	system( "pause" );


	return 0;
}