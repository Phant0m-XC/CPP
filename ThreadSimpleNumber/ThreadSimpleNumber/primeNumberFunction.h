#pragma once
#include <vector>
#include <mutex>

class PrimeNumberFinder {
	int serial_number;						//Порядковый номер искомого числа
	int start;								//Начало
	int end;								//Конец
	bool is_current_number_prime;			//true - простое число
	std::vector<int> *my_prime_numbers;		//хранилище найденных чисел (временное)
	static int count;						//счётчик простых чисел
	static std::mutex *my_lock;				//локер
public:
	PrimeNumberFinder(int, int, int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<int>*, bool*); //собственно поиск
	static void change_count();							//изменение счётчика
};