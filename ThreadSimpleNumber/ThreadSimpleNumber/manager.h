#pragma once
#include <iostream>
#include <vector>

#define PERIOD 100 //периодичность для искателей

class Manager{
	unsigned int start;
	bool all_done;
	std::vector<unsigned int> *all_numbers;
public:
	Manager();
	~Manager();
	unsigned int manage(unsigned int);
};