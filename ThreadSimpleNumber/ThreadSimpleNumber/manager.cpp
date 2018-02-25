#pragma once
#include <thread>
#include <algorithm>
#include "primeNumberFunction.h"
#include "manager.h"

Manager::Manager(){
	all_numbers = new std::vector<u_int>();
}

Manager::~Manager(){
	if (all_numbers != nullptr){
		all_numbers->clear();
		delete all_numbers;
	}
}

u_int Manager::manage(u_int serial_number) {
	u_int result;
	start = 1; //start with 1 (in method will be transmitted 2)
	all_done = false;

	//start 2 threads in loop; each thread searches for one hundred
	do {
		std::thread thr1(&PrimeNumberFinder::search_prime_number, PrimeNumberFinder(serial_number, start + 1, start + PERIOD), all_numbers, &all_done);
		start = start + PERIOD;
		std::thread thr2(&PrimeNumberFinder::search_prime_number, PrimeNumberFinder(serial_number, start + 1, start + PERIOD), all_numbers, &all_done);
		start = start + PERIOD;
		thr1.join();
		thr2.join();
	} while (!all_done);
	std::sort(all_numbers->begin(), all_numbers->end());
	result = all_numbers->at(serial_number - 1);
	all_numbers->clear();
	PrimeNumberFinder::reset_count();
	return result;
}