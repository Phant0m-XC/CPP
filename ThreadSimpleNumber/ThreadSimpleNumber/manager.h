#pragma once
#include <iostream>
#include <vector>

#define PERIOD 100 //������������� ��� ���������

class Manager{
	int start;
	bool all_done;
	std::vector<int> *all_numbers;
public:
	Manager();
	~Manager();
	int manage(int);
};