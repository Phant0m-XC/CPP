#pragma once
#include <cmath>
#include "primeNumberFunction.h"

PrimeNumberFinder::PrimeNumberFinder(int serial_number, int start, int end) {
	this->serial_number = serial_number;
	this->start = start;
	this->end = end;
	my_prime_numbers = new std::vector<int>();
}

PrimeNumberFinder::PrimeNumberFinder(const PrimeNumberFinder &copy_object) {
	this->serial_number = copy_object.serial_number;
	this->start = copy_object.start;
	this->end = copy_object.end;
	this->is_current_number_prime = copy_object.is_current_number_prime;
	this->my_prime_numbers = new std::vector<int>();
	this->my_prime_numbers->insert(this->my_prime_numbers->end(), copy_object.my_prime_numbers->begin(),
		copy_object.my_prime_numbers->end());
}

PrimeNumberFinder::~PrimeNumberFinder() {
	my_prime_numbers->clear();
	if (my_prime_numbers != nullptr)
		delete my_prime_numbers;
}

void PrimeNumberFinder::search_prime_number(std::vector<int> *vect, bool *all_done) {
	//начинаем со start
	int number = start;
	while (number <= end) {
		is_current_number_prime = true;
		for (size_t devider = 2; devider < number; devider++) {
			//если число не 2 и делиться без остатка, то оно состовное
			if (number != 2 && number % devider == 0) {
				is_current_number_prime = false;
				break;
			}
		}
		//если простое - изменить счётчик, добавить в хранилище
		if (is_current_number_prime) {
			change_count();
			my_prime_numbers->push_back(number);
		}
		number++;
	}
	//если счётчик равен или превысил искомый порядковый номер
	//помечаем true дело сделано (для менеджера)
	my_lock->lock();
	if (count >= serial_number)
		*all_done = true;
	//переписываем найденные числа менеджеру
	vect->insert(vect->end(), my_prime_numbers->begin(), my_prime_numbers->end());
	my_lock->unlock();
}

//увеличение счётчика
void PrimeNumberFinder::change_count() {
	my_lock->lock();
	count++;
	my_lock->unlock();
}

int PrimeNumberFinder::count = 0;

std::mutex* PrimeNumberFinder::my_lock = new std::mutex();