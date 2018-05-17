#include <iostream>
#include <exception>
#include <cstdlib>
#include "menu.hpp"

int main() {
	try {
		Menu menu;
		while (menu.start());
	}
	catch (std::exception const &ex) {
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << "Something wrong!" << std::endl;
		return EXIT_FAILURE;
	}
	system("pause");
	return EXIT_SUCCESS;
}