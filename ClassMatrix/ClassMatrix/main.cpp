//�������
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "matrix.h"

int main()
{
	size_t x, y;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	Matrix<double> a, b, c;
	std::cout << "������� ����������� 1-�� �������:\n���������� ����� - ";
	std::cin >> x;
	std::cout << "���������� �������� - ";
	std::cin >> y;
	a.init(x, y);
	std::cout << "������� ����������� 2-�� �������:\n���������� ����� - ";
	std::cin >> x;
	std::cout << "���������� �������� - ";
	std::cin >> y;
	b.init(x, y);
	std::cout << "1-�� �������:\n";
	a.fill();
	a.print();
	std::cout << "\n2-�� �������:\n";
	b.fill();
	b.print();
	std::cout << "\n������� 2-�� ������� - " << b.minimum();
	std::cout << "\n�������� 2-�� ������� - " << b.maximum();
	std::cout << "\n�������� ������:\n\n";
	c = a + b;
	c.print();
	std::cout << "\n��������� ������:\n";
	c = a - b;
	c.print();
	std::cout << "\n������������ ������:\n\n";
	c = a * b;
	c.print();
	std::cout << "\n������� ������:\n\n";
	c = a / b;
	c.print();

	return EXIT_SUCCESS;
}