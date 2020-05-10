#include <iostream>
#include <fstream>
#include "List_.h"

using namespace std;

template<typename T>
List_<T>::List_()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List_<T>::~List_()
{
	clear();
}

template<typename T>
void List_<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List_<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List_<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List_<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List_<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List_<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List_<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

template<typename T>
void List_<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List_<T>::write()
{
	Node<T>* current = this->head;
	ofstream fout; string path = "list.txt";
	if (!this->GetSize()) {
		cout << "��������� ���" << endl;
		return;
	}
	int* arr = new int[this->GetSize()];
	for (int i = 0; i < this->GetSize(); i++)
	{
		arr[i] = current->data;
		current = current->pNext;
	}
	fout.open(path);
	for (int i = 0; i < this->GetSize(); i++)
	{
		fout << arr[i];
	}
	delete[] arr;
	fout.close();
	cout << "\n������ ������ �������!\n";
}

template<typename T>
void List_<T>::read() {
	ifstream fin; string path = "list.txt"; int element = 0; int counter = 0;
	if (this->GetSize())
	{
		cout << "������!" << endl;
		return;
	}
	fin.open(path);
	if (!fin.is_open()) {
		cout << "����� �� ����������!" << endl;
		return;
	}
	while (fin >> element)
	{
		counter++;
	}
	fin.close();
	fin.open(path);
	int* arr = new int[counter];
	for (int i = 0; i < counter; i++)
	{
		fin >> element;
		arr[i] = element;
		this->push_back(arr[i]);
	}
	delete[] arr;
	fin.close();
	cout << "\n������ ������ �������!\n";
}