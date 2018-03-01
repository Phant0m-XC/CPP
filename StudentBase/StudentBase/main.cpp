#include <iostream>
#include "student.h"
#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	student *stud = nullptr;
	void(*menu[6])(student**, int) = { print, sort, findGroup, averageMarks, bestMarks, worstMarks };
	std::cout << "Введите количество студентов - ";
	std::cin >> n;
	std::cin.get();
	getMemory(&stud, n);
	for (int i = 0; i < n; i++)
		read(&stud + i, i + 1);
	result(&stud, n, getFunction(menu));
	freeMemory(&stud);
	return EXIT_SUCCESS;
}