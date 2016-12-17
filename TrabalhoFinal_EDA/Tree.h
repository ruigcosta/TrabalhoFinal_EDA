#pragma once
#include <iostream>
#include <string>


using namespace std;

class EmptyTreeException : public exception {
public:
	EmptyTreeException() :exception() {
	}
};


 class Nodo {
public:
	char ch;
	int ocorrencia;
		// T data;
	Nodo *left;
	Nodo *rigth;
};

class Tree {
public:
	Nodo *root;
	Tree() {
		root = NULL;
	}
	~Tree() {
		_Tree(root);
		root = NULL;
	}
	bool isEmpty() {
		return root == NULL;
	}
	void add(char ch ,int ocorrencia) {
		Nodo * novo = new Nodo();
		novo->ch = ch;
		novo->ocorrencia = ocorrencia;
		novo->left = NULL;
		novo->rigth = NULL;
		root = novo;
	}
	
	
	void mostrarArvore() {
		mostrarArvore(root, 0, 0);
	}

	//void mostrarBinario( char caracter )
	//{
	//	Nodo * actual =
	//}


private:
	void _Tree(Nodo *actual) {
		if (actual != NULL) {
			_Tree(actual->left);
			_Tree(actual->rigth);
			delete actual;
		}
	}

	
	void mostrarArvore(Nodo *actual, int nivel, int aux) {
		if (actual != NULL) {
			mostrarArvore(actual->rigth, nivel + 1, 1);
			for (int i = 0; i < nivel; i++)
				cout << "  ";
			if (aux > 0) cout << "/";
			if (aux < 0) cout << "\\";
			cout << actual->ch << ":" << actual->ocorrencia << endl;
			mostrarArvore(actual->left, nivel + 1, -1);
		}
	}

	//string 
	//string charBinary = "";
};


