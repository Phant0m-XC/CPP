#pragma once
#include <vector>
#include <mutex>

typedef unsigned int u_int;

class PrimeNumberFinder {
	u_int serial_number;							//Порядковый номер искомого числа
	u_int start;									//Начало
	u_int end;										//Конец
	bool is_current_number_prime;					//true - простое число
	std::vector<u_int> *my_prime_numbers;			//хранилище найденных чисел (временное)
	static u_int count;								//счётчик простых чисел
	static std::mutex *my_lock;						//локер
public:
	PrimeNumberFinder(u_int, u_int, u_int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<u_int>*, bool*);		//собственно поиск
	static void change_count();									//изменение счётчика
	static void reset_count();
};