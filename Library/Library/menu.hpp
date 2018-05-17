#ifndef MENU_H
#define MENU_H

#include "manager.hpp"

class Menu {
	Manager manager;
	unsigned int choice;
	unsigned int check_enter();
public:
	Menu();
	bool start();
};

#endif
