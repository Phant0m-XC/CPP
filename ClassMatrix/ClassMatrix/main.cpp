//матрицы
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
	std::cout << "Введите размерность 1-ой матрицы:\nКоличество строк - ";
	std::cin >> x;
	std::cout << "Количество столбцов - ";
	std::cin >> y;
	a.init(x, y);
	std::cout << "Введите размерность 2-ой матрицы:\nКоличество строк - ";
	std::cin >> x;
	std::cout << "Количество столбцов - ";
	std::cin >> y;
	b.init(x, y);
	std::cout << "1-ая матрица:\n";
	a.fill();
	a.print();
	std::cout << "\n2-ая матрица:\n";
	b.fill();
	b.print();
	std::cout << "\nМинимум 2-ой матрицы - " << b.minimum();
	std::cout << "\nМаксимум 2-ой матрицы - " << b.maximum();
	std::cout << "\nСложение матриц:\n\n";
	c = a + b;
	c.print();
	std::cout << "\nВычитание матриц:\n";
	c = a - b;
	c.print();
	std::cout << "\nПроизведение матриц:\n\n";
	c = a * b;
	c.print();
	std::cout << "\nДеление матриц:\n\n";
	c = a / b;
	c.print();

	return EXIT_SUCCESS;
}