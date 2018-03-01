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

	void init(size_t, size_t);							//������������ �������
	void clear();
	void fill_manual();									//���������� �������
	void fill();										//���������� ���������� �������
	void print() const;									//����� ���� ���������
	const Matrix operator=(const Matrix&);				//������������ ������
	const Matrix operator+(const Matrix&) const;		//�������� ������
	const Matrix operator-(const Matrix&) const;		//��������� ������
	const Matrix operator*(const Matrix&) const;		//��������� ������
	const Matrix operator/(const Matrix&) const;		//������� ������
	const Matrix inverse() const;						//����� ������ �������� ������� (1-� �����)
	const T determinant(size_t) const;					//����� ������������ �������
	const T alg_dop(const size_t, const size_t) const;	//����� ��������������� ����������
	const T minor(const size_t, const size_t) const;	//����� ������ ��������
	void transpon();									//���������������� ������� (2-� ����� ������ �������� �������)
	const T minimum() const;
	const T maximum() const;
};

#endif