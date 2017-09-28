#pragma once
#include <vector>
#include <mutex>

class PrimeNumberFinder {
	unsigned int serial_number;						//���������� ����� �������� �����
	unsigned int start;								//������
	unsigned int end;								//�����
	bool is_current_number_prime;					//true - ������� �����
	std::vector<unsigned int> *my_prime_numbers;	//��������� ��������� ����� (���������)
	static unsigned int count;						//������� ������� �����
	static std::mutex *my_lock;						//�����
public:
	PrimeNumberFinder(unsigned int, unsigned int, unsigned int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<unsigned int>*, bool*); //���������� �����
	static void change_count();									//��������� ��������
	static void reset_count();
};