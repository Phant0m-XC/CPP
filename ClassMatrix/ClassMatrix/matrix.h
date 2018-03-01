#ifndef _MATRIX
#define _MATRIX

template <typename T>
class Matrix
{
private:
	size_t row;
	size_t col;
	size_t ind_row;
	size_t ind_col;
	T **arr;
public:
	Matrix(size_t row = 0, size_t col = 0)
	{
		this->row = row;
		this->col = col;
		this->ind_row = 0;
		this->ind_col = 0;
		this->arr = new T*[this->row];
		for (int i = 0; i < this->row; i++)
			this->arr[i] = new T[this->col];
	}

	Matrix(const Matrix&);
	~Matrix();

	void init(size_t, size_t);							//инициализаия объекта
	void clear();
	void fill_manual();									//заполнение матрицы
	void fill();										//заполнение случайными числами
	void print() const;									//вывод всех элементов
	const Matrix operator=(const Matrix&);				//присваивание матриц
	const Matrix operator+(const Matrix&) const;		//сложение матриц
	const Matrix operator-(const Matrix&) const;		//вычитание матриц
	const Matrix operator*(const Matrix&) const;		//умножение матриц
	const Matrix operator/(const Matrix&) const;		//деление матриц
	const Matrix inverse() const;						//метод поиска обратной матрицы (1-я часть)
	const T determinant(size_t) const;					//поиск детерминанты матрицы
	const T alg_dop(const size_t, const size_t) const;	//поиск алгебраического дополнения
	const T minor(const size_t, const size_t) const;	//поиск минора элеиента
	void transpon();									//транспонирование матрицы (2-я часть поиска обратной матрицы)
	const T minimum() const;
	const T maximum() const;
};

#endif