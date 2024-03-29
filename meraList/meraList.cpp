﻿#include "stdafx.h"
#include <iostream> 

using namespace std;

//typedef int int;
struct node
{
	int data; //  данные 
	node* next; // указатель на следующий
	node* pred; // указатель на предыдущий
};

class SimpleList // класс связный список
{
private:
	node* first; // указатель на начало
public:
	SimpleList() { first = NULL; } // в конструкторе инициализируем его, он указывает в 
	// в место где нет полезной информации

	void push(int d, int pos); // метод добавления элемента
	int pop(int pos);  // метод удаления элемента	
	void clean(); // удаление всех элементов
	void view(); // вывод на экран
};

void SimpleList::push(int d, int pos) // метод добавления элемента
{



	node* newnode = new node; // создаём новый элемент
	newnode->data = d; // вводим в него данные
	if (first == NULL)   // если это первый элемент в списке                                   
	{
		newnode->next = newnode;
		newnode->pred = newnode;
		first = newnode; // first  указывает на него
	}
	else
	{
		node* temp = first; // создаём времменный указатель
		for (int i = pos; i > 1; i--, temp = temp->next); // цикл
		temp->pred->next = newnode;
		newnode->pred = temp->pred;
		newnode->next = temp; // добавляем перед времменным
		temp->pred = newnode;
	}
}

int SimpleList::pop(int pos) // удаляем элемент из списка по индексу
{
	if (first == NULL)  return 0; // если список пуст
	int val;
	if (first == first->next) // если это последний элемент в списке
	{
		val = first->data;
		delete first;
		first = NULL;
	}
	else
	{
		node* temp = first;
		for (int i = pos; i > 1; i--, temp = temp->next);
		if (temp == first) first = temp->next;
		temp->pred->next = temp->next; // удаляем temp элемент
		temp->next->pred = temp->pred;
		val = temp->data;
		delete temp;
	}
	return val;
}

void SimpleList::clean() // удалить все элементы из списка
{
	if (first == NULL) return;
	for (node* newnode = first->next; newnode != first; newnode = newnode->next) delete newnode;
	delete first;
	first = NULL;
}

void SimpleList::view() // просмотр элементов в списке
{
	if (first == NULL) return;
	node* newnode = first;
	do
	{
		cout << newnode->data << endl;
		newnode = newnode->next;
	} while (newnode != first);
}
