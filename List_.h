#pragma once
#include <iostream>
using namespace std;

template<typename T>
class List_
{
public:
	List_();
	virtual ~List_();

	//�������� ������� �������� � ������
	virtual void pop_front();

	//���������� �������� � ����� ������
	virtual void push_back(T data);

	// �������� ������
	virtual void clear();

	// �������� ���������� ��������� � ������
	virtual int GetSize() { return Size; }

	// ������������� �������� []
	virtual T& operator[](const int index);

	//���������� �������� � ������ ������
	virtual void push_front(T data);

	//���������� �������� � ������ �� ���������� �������
	virtual void insert(T data, int index);

	//�������� �������� � ������ �� ���������� �������
	virtual void removeAt(int index);

	//�������� ���������� �������� � ������
	virtual void pop_back();

	//������ � ����
	virtual void write();

	//������ �� �����
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
