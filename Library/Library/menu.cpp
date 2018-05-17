#include <iostream>
#include <string>
#include "menu.hpp"

Menu::Menu() : choice(0) {}

bool Menu::start() {
	system("cls");
	std::cout << "1 - Load data base" << std::endl;
	std::cout << "2 - Save data base" << std::endl;
	std::cout << "3 - Print all book" << std::endl;
	std::cout << "4 - Print all reader" << std::endl;
	std::cout << "5 - Add book" << std::endl;
	std::cout << "6 - Remove book" << std::endl;
	std::cout << "7 - Add reader" << std::endl;
	std::cout << "8 - Remove reader" << std::endl;
	std::cout << "9 - Add book to the reader" << std::endl;
	std::cout << "10 - Delete book from the reader" << std::endl;
	std::cout << "11 - Print books of reader" << std::endl;
	std::cout << "0 - Exit" << std::endl;
	std::cout << "Enter your select: ";
	choice = check_enter();
	switch (choice) {
	case 1:
		manager.load_book_base();
		manager.load_reader_base();
		break;
	case 2:
		manager.save_book_base();
		manager.save_reader_base();
		break;
	case 3:
		system("cls");
		manager.print_all_books();
		system("pause");
		break;
	case 4:
		system("cls");
		manager.print_all_readers();
		system("pause");
		break;
	case 5: {
		Book::ULL id = manager.give_next_id(Manager::TypeId::Book);
		std::string title, author;
		Book::UINT pages;
		std::cout << "Enter title of book: ";
		std::cin >> title;
		std::cout << "Enter author of book: ";
		std::cin >> author;
		std::cout << "Enter book's page count: ";
		pages = check_enter();
		Book book(id, title, author, pages);
		manager.add_book(book);
	}
			break;
	case 6: {
		Book::ULL id;
		std::cout << "Enter id of delete book: ";
		id = check_enter();
		Book book(id, "", "", 0);
		manager.delete_book(book);
	}
			break;
	case 7: {
		Reader::ULL id = manager.give_next_id(Manager::TypeId::Reader);
		std::string first_name, last_name;
		std::cout << "Enter reader's first name: ";
		std::cin >> first_name;
		std::cout << "Enter reader's last name: ";
		std::cin >> last_name;
		Reader reader(id, first_name, last_name);
		manager.add_reader(reader);
	}
			break;
	case 8: {
		Reader::ULL id;
		std::cout << "Enter id of delete reader: ";
		id = check_enter();
		Reader reader(id, "", "");
		manager.delete_reader(reader);
	}
			break;
	case 9: {
		Reader::ULL reader_id;
		Book::ULL book_id;
		std::cout << "Enter id of reader: ";
		reader_id = check_enter();
		std::cout << "Enter id of book: ";
		book_id = check_enter();
		manager.add_book_to_reader(reader_id, book_id);
	}
			break;
	case 10: {
		Reader::ULL reader_id;
		Book::ULL book_id;
		std::cout << "Enter id of reader: ";
		reader_id = check_enter();
		std::cout << "Enter id of book: ";
		book_id = check_enter();
		manager.delete_book_from_reader(reader_id, book_id);
	}
			 break;
	case 11: {
		system("cls");
		Reader::ULL id;
		std::cout << "Enter id of reader: ";
		id = check_enter();
		manager.print_books_of_reader(id);
		system("pause");
	}
			 break;
	case 0:
		return false;
	default:
		std::cout << "Wrong select! Try again!" << std::endl;
		break;
	}
	return true;
}

unsigned int Menu::check_enter() {
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	unsigned int enter = 0;
	do {
		if (std::cin >> enter)
			break;
		else {
			std::cin.clear();
			std::cin.get();
			std::cout << "Try again!" << std::endl;
			system("pause");
			std::cout << "Enter your select: ";
		}
	} while (true);
	return enter;
}