/*Программа по многопоточному (2) поиску простых чисел по их порядковому номеру*/

#include <iostream>
#include <cstdlib>
#include "primeNumberFunction.h"
#include "manager.h"

int main() {
	Manager manager;
	u_int result, choice;
	do {
		std::cout << "Enter a number of prime number (or 0 for exit): ";
		std::cin >> choice;
		if (choice) {
			result = manager.manage(choice);
			std::cout << result << std::endl;
		}
	} while (choice);
	std::cout << "Exit" << std::endl;
	return EXIT_SUCCESS;
}