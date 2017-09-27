/*��������� �� �������������� (2) ������ ������� ����� �� �� ����������� ������*/

#include <iostream>
#include "primeNumberFunction.h"
#include "manager.h"

int main() {
	Manager manager;
	unsigned int result, choice;
	do {
		std::cout << "Enter a number of prime number (or 0 for exit): ";
		std::cin >> choice;
		if (choice) {
			result = manager.manage(choice);
			std::cout << result << std::endl;
		}
	} while (choice);
	std::cout << "Exit" << std::endl;
	return 0;
}