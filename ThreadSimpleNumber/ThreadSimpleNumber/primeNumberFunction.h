#pragma once
#include <vector>
#include <mutex>

class PrimeNumberFinder {
	int serial_number;						//���������� ����� �������� �����
	int start;								//������
	int end;								//�����
	bool is_current_number_prime;			//true - ������� �����
	std::vector<int> *my_prime_numbers;		//��������� ��������� ����� (���������)
	static int count;						//������� ������� �����
	static std::mutex *my_lock;				//�����
public:
	PrimeNumberFinder(int, int, int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<int>*, bool*); //���������� �����
	static void change_count();							//��������� ��������
};