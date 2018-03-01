#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(const Matrix &copy)
{
	this->col = copy.col;
	this->row = copy.row;
	this->ind_row = 0;
	this->ind_col = 0;
	this->arr = new T*[this->row];
	for (int i = 0; i < this->row; i++)
		this->arr[i] = new T[this->col];
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			this->arr[i][j] = copy.arr[i][j];
}

template <typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < this->row; i++)
		delete[]this->arr[i];
	delete[]this->arr;
}

template <typename T>
void Matrix<T>::init(size_t row, size_t col) //инициализаи€ объекта
{
	for (int i = 0; i < this->row; i++)
		if (this->arr[i])
			delete[]this->arr[i];
	if (this->arr)
		delete[]this->arr;
	this->row = row;
	this->col = col;
	this->ind_row = 0;
	this->ind_col = 0;
	this->arr = new T*[this->row];
	for (int i = 0; i < this->row; i++)
		this->arr[i] = new T[this->col];
}

template <typename T>
void Matrix<T>::clear()
{
	if (this->arr)
	{
		for (int i = 0; i < this->row; i++)
		{
			if (this->arr[i])
				delete[]this->arr[i];
		}
		delete[]this->arr;
	}
	this->row = 0;
	this->col = 0;
	this->arr = nullptr;
}

template <typename T>
void Matrix<T>::fill_manual() //заполнение матрицы
{
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			std::cout << "¬ведите элемент [" << i << "][" << j << "] - ";
			std::cin >> this->arr[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::fill() //заполнение случайными числами
{
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			this->arr[i][j] = rand() % 11;
}

template <typename T>
void Matrix<T>::print() const //вывод всех элементов
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << std::setw(12) << this->arr[i][j] << " ";
		std::cout << std::endl;
	}
}

template <typename T>
const Matrix<T> Matrix<T>::operator=(const Matrix &matrix) //присваивание матриц
{
	for (int i = 0; i < this->row; i++)
		if (this->arr[i])
			delete[]this->arr[i];
	if (this->arr)
		delete[]this->arr;
	this->row = matrix.row;
	this->col = matrix.col;
	this->arr = new T*[this->row];
	for (int i = 0; i < this->row; i++)
		this->arr[i] = new T[this->col];
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			this->arr[i][j] = matrix.arr[i][j];
	return *this;
}

template <typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix &matrix) const //сложение матриц
{
	if (this->row == matrix.row && this->col == matrix.col)
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < this->col; j++)
				temp.arr[i][j] = this->arr[i][j] + temp.arr[i][j];
		return temp;
	}
	else
	{
		Matrix<T> temp;
		std::cout << "–азмеры матриц не равны\n";
		return temp;
	}
}

template <typename T>
const Matrix<T> Matrix<T>::operator-(const Matrix &matrix) const //вычитание матриц
{
	if (this->row == matrix.row && this->col == matrix.col)
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < this->col; j++)
				temp.arr[i][j] = this->arr[i][j] - matrix.arr[i][j];
		return temp;
	}
	else
	{
		Matrix<T> temp;
		std::cout << "–азмеры матриц не равны\n";
		return temp;
	}
}

template <typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix &matrix) const //умножение матриц
{
	if (this->col == matrix.row)
	{
		Matrix<T> temp(this->row, matrix.col);
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < matrix.col; j++)
			{
				temp.arr[i][j] = 0;
				for (int k = 0; k < this->col; k++)
					temp.arr[i][j] += this->arr[i][k] * matrix.arr[k][j];
			}
		}
		return temp;
	}
	else
	{
		Matrix<T> temp;
		std::cout << "ћатрицы не подлежат к умножению\n";
		return temp;
	}
}

template <typename T>
const Matrix<T> Matrix<T>::operator/(const Matrix &matrix) const //деление матриц
{
	if (this->row == this->col && matrix.row == matrix.col && this->col == matrix.row)
	{
		Matrix<T> temp;
		temp = matrix.inverse();
		if (!temp.row)
		{
			std::cout << "ћатрица выражденна€! ƒеление не возможно!\n";
			return temp;
		}
		else
		{
			Matrix<T> result;
			result = *this*temp;
			result.transpon();
			return result;
		}
	}
	else
	{
		Matrix<T> temp;
		std::cout << "ћатрицы не подлежат к делению\n";
		return temp;
	}
}

template <typename T>
const Matrix<T> Matrix<T>::inverse() const //метод поиска обратной матрицы (1-€ часть)
{
	Matrix<T> temp;
	T det = this->determinant(0);
	if (!det)
		return temp;
	temp = *this;
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			temp.arr[i][j] = temp.alg_dop(i, j) / det;
		}
	}
	return temp;
}

template <typename T>
const T Matrix<T>::determinant(size_t i) const //поиск детерминанты матрицы
{
	T sum = 0;
	for (size_t j = 0; j < this->col; j++)
		sum += this->arr[i][j] * this->alg_dop(i, j);
	return sum;
}

template <typename T>
const T Matrix<T>::alg_dop(const size_t i, const size_t j) const //поиск алгебраического дополнени€
{
	return pow(-1, i + j + 2)*this->minor(i, j);
}

template <typename T>
const T Matrix<T>::minor(const size_t i, const size_t j) const //поиск минора элеиента
{
	size_t x = 0;
	size_t y = 0;
	Matrix<T> temp(this->row - 1, this->col - 1);
	for (size_t m = 0; m < this->row; m++)
	{
		if (m == i)
			continue;
		for (size_t n = 0; n < this->col; n++)
		{
			if (n == j)
				continue;
			temp.arr[x][y] = this->arr[m][n];
			y++;
		}
		y = 0;
		x++;
	}
	T sum1 = 1;
	T sum2 = 1;
	for (size_t k = 0; k < temp.row; k++)
	{
		for (size_t l = 0; l < temp.col; l++)
		{
			if (k == l)
				sum1 *= temp.arr[k][l];
			if (l == temp.col - k - 1)
				sum2 *= temp.arr[k][l];
		}
	}
	return sum1 - sum2;
}

template <typename T>
void Matrix<T>::transpon() //транспонирование матрицы (2-€ часть поиска обратной матрицы)
{
	Matrix<T> temp;
	temp = *this;
	for (size_t i = 0; i < this->row; i++)
		if (this->arr[i])
			delete[]this->arr[i];
	delete[]this->arr;
	this->arr = new T*[this->col];
	for (size_t i = 0; i < this->col; i++)
		this->arr[i] = new T[this->row];
	size_t tmp;
	tmp = this->row;
	this->row = this->col;
	this->col = tmp;
	for (size_t i = 0; i < this->row; i++)
		for (size_t j = 0; j < this->col; j++)
			this->arr[i][j] = temp.arr[j][i];
}

template <typename T>
const T Matrix<T>::minimum() const
{
	T min = this->arr[0][0];
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			if (this->arr[i][j] < min)
				min = this->arr[i][j];
		}
	}
	return min;
}

template <typename T>
const T Matrix<T>::maximum() const
{
	T max = this->arr[0][0];
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			if (this->arr[i][j] > max)
				max = this->arr[i][j];
		}
	}
	return max;
}