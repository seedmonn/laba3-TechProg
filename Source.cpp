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
		cout << "����: ";
		for (int i = 0; i < stck.GetSize(); i++)
		{
			cout << "["; cout << stck[i] << "] ";
		}
		cout << "\n�������: ";
		for (int i = 0; i < que.GetSize(); i++)
		{
			cout << "["; cout << que[i] << "] ";
		}
		cout << "\n�������� ��������" << endl;
		cout << "[1] �������� ������� � ����" << endl;
		cout << "[2] ������� ������� �� �����" << endl;
		cout << "[3] �������� ������� � �������" << endl;
		cout << "[4] ������� ������� �� �������" << endl;
		cout << "[5] ������ ����� � ����" << endl;
		cout << "[6] ������ ����� �� �����" << endl;
		cout << "[7] ������ ������� � ����" << endl;
		cout << "[8] ������ ������� �� �����" << endl;
		cout << "[9] �����" << endl;
		cout << "=> "; cin >> menu_value;
		switch (menu_value) {
		case '1':
			system("cls");
			for (int i = 0; i < stck.GetSize(); i++)
			{
				cout << "["; cout << stck[i] << "] ";
			}
			cout << "\n������� ������� ��� ����������: ";
			cin >> int_menu_value;
			stck.push_back(int_menu_value);
			cout << "�����!\n";
			system("PAUSE");
			break;
		case '2':
			system("cls");
			if (!stck.GetSize())
			{
				cout << "���� ����!\n";
				system("PAUSE");
				break;
			}
			for (int i = 0; i < stck.GetSize(); i++)
			{
				cout << "["; cout << stck[i] << "] ";
			}
			stck.pop_back();
			cout << "\n�����!\n������� ����: ";
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
			cout << "������� ������� ��� ����������: ";
			cin >> int_menu_value;
			que.push_back(int_menu_value);
			cout << "�����!\n";
			system("PAUSE");
			break;
		case '4':
			system("cls");
			if (!que.GetSize())
			{
				cout << "������� �����!\n";
				system("PAUSE");
				break;
			}
			for (int i = 0; i < que.GetSize(); i++)
			{
				cout << "["; cout << que[i] << "] ";
			}
			que.pop_front();
			cout << "\n�����!\n������� �������: ";
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