#pragma once
#include <thread>
#include "primeNumberFunction.h"
#include "manager.h"

Manager::Manager(){
	all_numbers = new std::vector<unsigned int>();
}

Manager::~Manager(){
	if (all_numbers != nullptr){
		all_numbers->clear();
		delete all_numbers;
	}
}

unsigned int Manager::manage(unsigned int serial_number){
	unsigned int result;
	start = 1; //�������� � 1 (� ����� ����� �������� 2)
	all_done = false;

	//��������� � ����� 2 ������ �� ������ ������� �����, � ������ ������ ����� �������� �� 1 �����
	do{
		std::thread thr1(&PrimeNumberFinder::search_prime_number, PrimeNumberFinder(serial_number, start + 1, start + PERIOD), all_numbers, &all_done);
		start = start + PERIOD;
		std::thread thr2(&PrimeNumberFinder::search_prime_number, PrimeNumberFinder(serial_number, start + 1, start + PERIOD), all_numbers, &all_done);
		start = start + PERIOD;
		thr1.join();
		thr2.join();
	} while (!all_done);

	result = all_numbers->at(serial_number - 1);
	all_numbers->clear();
	PrimeNumberFinder::reset_count();
	return result;
}