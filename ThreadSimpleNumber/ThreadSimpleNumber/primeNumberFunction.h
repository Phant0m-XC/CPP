#pragma once
#include <vector>
#include <mutex>

typedef unsigned int u_int;

class PrimeNumberFinder {
	u_int serial_number;							//���������� ����� �������� �����
	u_int start;									//������
	u_int end;										//�����
	bool is_current_number_prime;					//true - ������� �����
	std::vector<u_int> *my_prime_numbers;			//��������� ��������� ����� (���������)
	static u_int count;								//������� ������� �����
	static std::mutex *my_lock;						//�����
public:
	PrimeNumberFinder(u_int, u_int, u_int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<u_int>*, bool*);		//���������� �����
	static void change_count();									//��������� ��������
	static void reset_count();
};