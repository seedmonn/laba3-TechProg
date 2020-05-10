#include "_queue.h"
#include <iostream>
using namespace std;

template<typename T>
queue_<T>::queue_()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
queue_<T>::~queue_()
{
	clear();
}

template<typename T>
void queue_<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void queue_<T>::push_back(T data)
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
void queue_<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& queue_<T>::operator[](const int index)
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
void queue_<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void queue_<T>::removeAt(int index)
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
void queue_<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void queue_<T>::write()
{
	Node<T>* current = this->head;
	ofstream fout; string path = "queue.txt";
	if (!this->GetSize()) {
		cout << "Элементов нет" << endl;
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
		fout << arr[i] << " ";
	}
	delete[] arr;
	fout.close();
	cout << "\nЗапись прошла успешно!\n";
}

template<typename T>
void queue_<T>::read()
{
	ifstream fin; string path = "queue.txt"; int element = 0; int counter = 0;
	if (this->GetSize())
	{
		cout << "Уже имеются элементы очереди! Освободите текущую очередь, чтобы считать из файла." << endl;
		return;
	}
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Файла не существует!" << endl;
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
	cout << "\nЧтение прошло успешно!\n";
}