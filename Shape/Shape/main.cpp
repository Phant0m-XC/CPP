//������
#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

#include "Figures.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Shape **obj1 = nullptr, **obj2 = nullptr;
	int num, choise;
	cout << "������� ���������� ����� - ";
	cin >> num;
	obj1 = new Shape*[num];
	for (size_t i = 0; i < num; i++)
	{
		cout << "����� ���� ������ (1 - �������, 2 - �������������, 3 - ����������, 4 - ������): ";
		cin >> choise;
		switch (choise)
		{
		case SQUARE:
			obj1[i] = new Square;
			obj1[i]->Set();
			break;
		case RECTANGLE:
			obj1[i] = new Rectangle;
			obj1[i]->Set();
			break;
		case CIRCLE:
			obj1[i] = new Circle;
			obj1[i]->Set();
			break;
		case ELLIPSE:
			obj1[i] = new Ellipse;
			obj1[i]->Set();
			break;
		default:
			cout << "�������� �����!";
			break;
		}
		system("cls");
	}
	for (size_t i = 0; i < num; i++)
	{
		obj1[i]->Show();
	}
	fstream file("base.bin", ios::out | ios::binary | ios::trunc);
	file.write((char*)&num, sizeof(int));
	file.close();
	for (size_t i = 0; i < num; i++)
	{
		obj1[i]->Save();
	}
	cout << "\n\n������ �� �����:\n";
	file.open("base.bin", ios::in | ios::binary);
	file.read((char*)&num, sizeof(int));
	obj2 = new Shape*[num];
	for (size_t i = 0; i < num; i++)
	{
		file.read((char*)&choise, sizeof(int));
		switch (choise)
		{
		case SQUARE:
			obj2[i] = new Square;
			obj2[i]->Load(file);
			break;
		case RECTANGLE:
			obj2[i] = new Rectangle;
			obj2[i]->Load(file);
			break;
		case CIRCLE:
			obj2[i] = new Circle;
			obj2[i]->Load(file);
			break;
		case ELLIPSE:
			obj2[i] = new Ellipse;
			obj2[i]->Load(file);
			break;
		}
	}
	for (size_t i = 0; i < num; i++)
	{
		obj2[i]->Show();
	}
	for (size_t i = 0; i < num; i++)
	{
		delete obj1[i];
		delete obj2[i];
	}
	delete obj1;
	delete obj2;
	return 0;
}