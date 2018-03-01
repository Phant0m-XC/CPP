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
	std::cout << "Введиет данные " << i << " студента:\nФИО студента - ";
	std::cin.getline((*stud)->fio, 50);
	std::cout << "Группу студента - ";
	std::cin >> (*stud)->group;
	std::cout << "Номер зачётки - ";
	std::cin >> (*stud)->number;
	std::cout << "Введиет оценки студента:\n";
	for (int j = 0; j < 4; j++)
		std::cin >> (*stud)->marks[j];
	std::cin.get();
}

void print(student **stud, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "ФИО - " << ((*stud) + i)->fio << "Номер группы - " << ((*stud) + i)->group << "\nНомер зачётки - " << ((*stud) + i)->number << "\nОценки: ";
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
				std::cout << "ФИО - " << ((*stud) + j)->fio << " Номер группы - " << ((*stud) + j)->group << "\nНомер зачётки - " << ((*stud) + j)->number << "\nОценки: ";
				for (int k = 0; k < 4; k++)
					std::cout << ((*stud) + j)->marks[k] << " ";
				std::cout << std::endl;
			}
}

void findGroup(student **stud, int n)
{
	int key;
	std::cout << "Введите номер группы - ";
	std::cin >> key;
	for (int i = 0; i < n; i++)
		if (key == ((*stud) + i)->group)
			std::cout << "ФИО - " << ((*stud) + i)->fio << std::endl;
}

void averageMarks(student **stud, int n)
{
	int sum; double midl;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		std::cout << "ФИО - " << ((*stud) + i)->fio << " Средняя оценка - ";
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
			std::cout << "ФИО - " << ((*stud) + i)->fio << "\nНомер группы - " << ((*stud) + i)->group << "\nНомер зачётки - " << ((*stud) + i)->number;
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
			std::cout << "ФИО - " << ((*stud) + i)->fio << "\nНомер группы - " << ((*stud) + i)->group << "\nНомер зачётки - " << ((*stud) + i)->number;
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
		std::cout << "Выберите действие:\n1 - Вывести список студентов\n2 - Вывести отсортированный список студентов\n3 - Вывести список студентов определённой группы\n";
		std::cout << "4 - Вывести средний бал успеваемости студентов\n5 - Вывести список отличников\n6 - Вывести список \"неуспевающих студентов\"\nСделайте выбор - ";
		std::cin >> z;
		if (z >= 1 || z <= 6)
			break;
	}
	return menu[z - 1];
}