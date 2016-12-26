#pragma once
#include <iostream>
#include <chrono>
#include "Tree.h"

using namespace std;

class EmptyListException : public exception {
public:
	EmptyListException() :exception() {
	}
};


class DLListItem {
public:
	Tree *data;
	DLListItem *next;
	DLListItem *previous;
};


class DoubleLinkedList {
public:
	DLListItem *head;
	DLListItem *tail;
	DoubleLinkedList() {
		head = NULL;
		tail = NULL;
	}
	~DoubleLinkedList() {
		DLListItem *aux = head;
		while (aux != NULL) {
			head = head->next;
			delete aux->data;
			delete aux;
			aux = head;
		}
		tail = NULL;
	};
	bool isEmpty() {
		return head == NULL || tail == NULL;
	}
	
	DLListItem* addOrdered(char ch,int ocorrencia) {
		DLListItem *novo = new DLListItem();
		novo->data = new Tree();
		novo->data->add(ch, ocorrencia);
		novo->next = NULL;
		novo->previous = NULL;
		if (head == NULL) {
			head = novo;
			tail = novo;
		}
		else {
			if (ocorrencia < head->data->root->ocorrencia || (ocorrencia == head->data->root->ocorrencia && ch < head->data->root->ch)) {
				head->previous = novo;
				novo->next = head;
				head = novo;
			}	
			else if (ocorrencia > tail->data->root->ocorrencia || (ocorrencia == tail->data->root->ocorrencia && ch > tail->data->root->ch)) {
				novo->previous = tail;
				tail->next = novo;
				tail = novo;
			}	
			else {
				DLListItem*aux = head;
				while (aux->data->root->ocorrencia < ocorrencia ||
					(aux->data->root->ocorrencia==ocorrencia &&aux->data->root->ch< ch))
					aux = aux->next;
				novo->next = aux;
				novo->previous = aux->previous;
				aux->previous->next = novo;
				aux->previous = novo;
			}
				
		}
		return novo;
	}

	Tree* RemoveFirst() {
		if (head == NULL)
			return NULL;
		else if (head == tail) {
			Tree *aux = head->data;
			delete head;
			head = tail = NULL;
			return aux;
		}
		else {
			Tree *aux = head->data;
			head = head->next;
			delete head->previous;
			head->previous = NULL;
			return aux;
		}
			
	}

	void mostraLista() {
		DLListItem *aux=head;
		while (aux!=NULL)
		{
			aux->data->mostrarArvore();
			aux = aux->next;
		}
		cout << endl;
	}
};

