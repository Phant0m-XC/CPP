#include <iostream>
#include "functions.h"

void getMemory(student **stud, int n)
{
	*stud = new student[n];
}

void freeMemory(student **stud)
{
	delete[] *stud;
}

void read(student **stud, int i)
{
	std::cout << "������� ������ " << i << " ��������:\n��� �������� - ";
	std::cin.getline((*stud)->fio, 50);
	std::cout << "������ �������� - ";
	std::cin >> (*stud)->group;
	std::cout << "����� ������� - ";
	std::cin >> (*stud)->number;
	std::cout << "������� ������ ��������:\n";
	for (int j = 0; j < 4; j++)
		std::cin >> (*stud)->marks[j];
	std::cin.get();
}

void print(student **stud, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "��� - " << ((*stud) + i)->fio << "����� ������ - " << ((*stud) + i)->group << "\n����� ������� - " << ((*stud) + i)->number << "\n������: ";
		for (int j = 0; j < 4; j++)
			std::cout << ((*stud) + i)->marks[j] << " ";
		std::cout << std::endl;
	}
}

void sort(student **stud, int n)
{
	char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", c;
	for (int i = 0; letter[i] != '\0'; i++)
		for (int j = 0; j < n; j++)
			if (letter[i] == ((*stud) + j)->fio[0])
			{
				std::cout << "��� - " << ((*stud) + j)->fio << " ����� ������ - " << ((*stud) + j)->group << "\n����� ������� - " << ((*stud) + j)->number << "\n������: ";
				for (int k = 0; k < 4; k++)
					std::cout << ((*stud) + j)->marks[k] << " ";
				std::cout << std::endl;
			}
}

void findGroup(student **stud, int n)
{
	int key;
	std::cout << "������� ����� ������ - ";
	std::cin >> key;
	for (int i = 0; i < n; i++)
		if (key == ((*stud) + i)->group)
			std::cout << "��� - " << ((*stud) + i)->fio << std::endl;
}

void averageMarks(student **stud, int n)
{
	int sum; double midl;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		std::cout << "��� - " << ((*stud) + i)->fio << " ������� ������ - ";
		for (int j = 0; j < 4; j++)
			sum += ((*stud) + i)->marks[j];
		midl = (double)sum / 4;
		std::cout << midl << std::endl;
	}
}

void bestMarks(student **stud, int n)
{
	int sum; double best;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++)
			sum += ((*stud) + i)->marks[j];
		if (best = (double)sum / 4 == 5)
			std::cout << "��� - " << ((*stud) + i)->fio << "\n����� ������ - " << ((*stud) + i)->group << "\n����� ������� - " << ((*stud) + i)->number;
		std::cout << std::endl;
	}
}

void worstMarks(student **stud, int n)
{
	int sum; double best;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++)
			sum += ((*stud) + i)->marks[j];
		if (best = (double)sum / 4 < 3)
			std::cout << "��� - " << ((*stud) + i)->fio << "\n����� ������ - " << ((*stud) + i)->group << "\n����� ������� - " << ((*stud) + i)->number;
		std::cout << std::endl;
	}
}

void result(student **stud, int n, void(*ptralg)(student **, int))
{
	(*ptralg)(stud, n);
}

void(*getFunction(void(*menu[])(student **, int)))(student **, int)
{
	int z;
	while (1)
	{
		std::cout << "�������� ��������:\n1 - ������� ������ ���������\n2 - ������� ��������������� ������ ���������\n3 - ������� ������ ��������� ����������� ������\n";
		std::cout << "4 - ������� ������� ��� ������������ ���������\n5 - ������� ������ ����������\n6 - ������� ������ \"������������ ���������\"\n�������� ����� - ";
		std::cin >> z;
		if (z >= 1 || z <= 6)
			break;
	}
	return menu[z - 1];
}