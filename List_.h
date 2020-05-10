#pragma once
#include <iostream>
using namespace std;

template<typename T>
class List_
{
public:
	List_();
	virtual ~List_();

	//удаление первого элемента в списке
	virtual void pop_front();

	//добавление элемента в конец списка
	virtual void push_back(T data);

	// очистить список
	virtual void clear();

	// получить количество елементов в списке
	virtual int GetSize() { return Size; }

	// перегруженный оператор []
	virtual T& operator[](const int index);

	//добавление элемента в начало списка
	virtual void push_front(T data);

	//добавление элемента в список по указанному индексу
	virtual void insert(T data, int index);

	//удаление элемента в списке по указанному индексу
	virtual void removeAt(int index);

	//удаление последнего элемента в списке
	virtual void pop_back();

	//запись в файл
	virtual void write();

	//чтение из файла
	virtual void read();

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};
