#pragma once

#define PERIOD 100 //периодичность для искателей

class Manager{
	u_int start;
	bool all_done;
	std::vector<u_int> *all_numbers;
public:
	Manager();
	~Manager();
	u_int manage(u_int);
};