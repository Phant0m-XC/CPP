/*Программа по многопоточному (2) поиску простых чисел по их порядковому номеру*/

#include <iostream>
#include <cstdlib>
#include <chrono>
#include "primeNumberFunction.h"
#include "manager.h"

int main() {
	Manager manager;
	u_int result, choice;
	do {
		std::cout << "Enter a number of prime number (or 0 for exit): ";
		std::cin >> choice;
		if (choice) {
			//auto begin = std::chrono::high_resolution_clock::now();
			result = manager.manage(choice);
			//auto end = std::chrono::high_resolution_clock::now();
			//std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
			std::cout << result << std::endl;
		}
	} while (choice);
	std::cout << "Exit" << std::endl;
	return EXIT_SUCCESS;
}