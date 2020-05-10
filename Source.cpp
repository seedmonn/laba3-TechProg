#include <iostream>
#include <fstream>
#include "_queue.h"
#include "stack_.h"
#include "List_.h"
#include "_queue.cpp"
#include "stack_.cpp"
#include "List_.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	stack_<int> stck;
	queue_<int> que;

	char menu_value; int int_menu_value;
	do
	{
		system("cls");
		cout << "Стек: ";
		for (int i = 0; i < stck.GetSize(); i++)
		{
			cout << "["; cout << stck[i] << "] ";
		}
		cout << "\nОчередь: ";
		for (int i = 0; i < que.GetSize(); i++)
		{
			cout << "["; cout << que[i] << "] ";
		}
		cout << "\nВыберите действие" << endl;
		cout << "[1] Добавить элемент в стек" << endl;
		cout << "[2] Удалить элемент из стека" << endl;
		cout << "[3] Добавить элемент в очередь" << endl;
		cout << "[4] Удалить элемент из очереди" << endl;
		cout << "[5] Запись стека в файл" << endl;
		cout << "[6] Чтение стека из файла" << endl;
		cout << "[7] Запись очереди в файл" << endl;
		cout << "[8] Чтение очереди из файла" << endl;
		cout << "[9] Выйти" << endl;
		cout << "=> "; cin >> menu_value;
		switch (menu_value) {
		case '1':
			system("cls");
			for (int i = 0; i < stck.GetSize(); i++)
			{
				cout << "["; cout << stck[i] << "] ";
			}
			cout << "\nВведите элемент для добавления: ";
			cin >> int_menu_value;
			stck.push_back(int_menu_value);
			cout << "Успех!\n";
			system("PAUSE");
			break;
		case '2':
			system("cls");
			if (!stck.GetSize())
			{
				cout << "Стек пуст!\n";
				system("PAUSE");
				break;
			}
			for (int i = 0; i < stck.GetSize(); i++)
			{
				cout << "["; cout << stck[i] << "] ";
			}
			stck.pop_back();
			cout << "\nУспех!\nТекущий стек: ";
			for (int i = 0; i < stck.GetSize(); i++)
			{
				cout << "["; cout << stck[i] << "] ";
			}
			cout << endl;
			system("PAUSE");
			break;
		case '3':
			system("cls");
			for (int i = 0; i < que.GetSize(); i++)
			{
				cout << "["; cout << que[i] << "] ";
			}
			cout << "Введите элемент для добавления: ";
			cin >> int_menu_value;
			que.push_back(int_menu_value);
			cout << "Успех!\n";
			system("PAUSE");
			break;
		case '4':
			system("cls");
			if (!que.GetSize())
			{
				cout << "Очередь пуста!\n";
				system("PAUSE");
				break;
			}
			for (int i = 0; i < que.GetSize(); i++)
			{
				cout << "["; cout << que[i] << "] ";
			}
			que.pop_front();
			cout << "\nУспех!\nТекущая очередь: ";
			for (int i = 0; i < que.GetSize(); i++)
			{
				cout << "["; cout << que[i] << "] ";
			}
			cout << endl;
			system("PAUSE");
			break;
		case '5':
			stck.write();
			system("PAUSE");
			break;
		case '6':
			stck.read();
			system("PAUSE");
			break;
		case '7':
			que.write();
			system("PAUSE");
			break;
		case '8':
			que.read();
			system("PAUSE");
			break;
		}
	} while (menu_value != '9');
}