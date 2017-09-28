#pragma once
#include <vector>
#include <mutex>

class PrimeNumberFinder {
	unsigned int serial_number;						//Порядковый номер искомого числа
	unsigned int start;								//Начало
	unsigned int end;								//Конец
	bool is_current_number_prime;					//true - простое число
	std::vector<unsigned int> *my_prime_numbers;	//хранилище найденных чисел (временное)
	static unsigned int count;						//счётчик простых чисел
	static std::mutex *my_lock;						//локер
public:
	PrimeNumberFinder(unsigned int, unsigned int, unsigned int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<unsigned int>*, bool*); //собственно поиск
	static void change_count();									//изменение счётчика
	static void reset_count();
};