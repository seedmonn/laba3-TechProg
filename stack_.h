#pragma once
#include "List_.h"
#include <iostream>

using namespace std;

template<typename T> class stack_ : public List_ <T> {
public:
	stack_();
	~stack_() override;

	//удаление первого элемента в списке
	void pop_front() override;

	//добавление элемента в конец списка
	void push_back(T data) override;

	// очистить список
	void clear() override;

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор []
	T& operator[](const int index) override;

	//удаление элемента в списке по указанному индексу
	void removeAt(int index) override;

	//удаление последнего элемента в списке
	void pop_back() override;

	void write() override;

	void read() override;

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