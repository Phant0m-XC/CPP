#pragma once
#include "primeNumberFunction.h"

PrimeNumberFinder::PrimeNumberFinder(u_int serial_number, u_int start, u_int end) {
	this->serial_number = serial_number;
	this->start = start;
	this->end = end;
	my_prime_numbers = new std::vector<u_int>();
}

PrimeNumberFinder::PrimeNumberFinder(const PrimeNumberFinder &copy_object) {
	this->serial_number = copy_object.serial_number;
	this->start = copy_object.start;
	this->end = copy_object.end;
	this->is_current_number_prime = copy_object.is_current_number_prime;
	this->my_prime_numbers = new std::vector<u_int>();
	this->my_prime_numbers->insert(this->my_prime_numbers->end(), copy_object.my_prime_numbers->begin(),
		copy_object.my_prime_numbers->end());
}

PrimeNumberFinder::~PrimeNumberFinder() {
	if (my_prime_numbers != nullptr) {
		my_prime_numbers->clear();
		delete my_prime_numbers;
	}
}

void PrimeNumberFinder::search_prime_number(std::vector<u_int> *vect, bool *all_done) {
	//to start with "start"
	u_int number = start;
	while (number <= end) {
		is_current_number_prime = true;
		for (u_int devider = 2; devider < number; devider++) {
			//if number is not 2 and devided, that it is composite number
			if (number != 2 && number % devider == 0) {
				is_current_number_prime = false;
				break;
			}
		}
		//if prime - change count, add to vector
		if (is_current_number_prime) {
			change_count();
			my_prime_numbers->push_back(number);
		}
		number++;
	}
	//if count equals or exceeded wanted serial number
	//check true - all done (for manager)
	my_lock->lock();
	if (count >= serial_number)
		*all_done = true;
	//copy all finded numbers to manager
	vect->insert(vect->end(), my_prime_numbers->begin(), my_prime_numbers->end());
	my_lock->unlock();
}

//increase count
void PrimeNumberFinder::change_count() {
	my_lock->lock();
	count++;
	my_lock->unlock();
}

void PrimeNumberFinder::reset_count() {
	count = 0;
}

u_int PrimeNumberFinder::count = 0;

std::mutex* PrimeNumberFinder::my_lock = new std::mutex();