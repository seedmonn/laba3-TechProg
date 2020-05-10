#pragma once
#include "List_.h"
#include <iostream>

using namespace std;

template<typename T> class queue_ : public List_ <T> {
public:
	queue_();

	~queue_() override;

	void pop_front() override;

	void push_back(T data) override;

	void clear() override;

	int GetSize() { return Size; }

	T& operator[](const int index) override;

	void push_front(T data) override;

	void removeAt(int index) override;

	void pop_back() override;

	void write();

	void read();

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