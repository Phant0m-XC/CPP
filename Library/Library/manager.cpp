#include <iostream>
#include <iomanip>
#include <cstring>
#include <exception>
#include <algorithm>
#include "manager.hpp"

Manager::Manager() {
	book_file_db.open("book_db.dat", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
	if (!book_file_db.is_open())
		throw std::exception("Book_db file open failed!");
	else
		load_book_base();
	reader_file_db.open("reader_db.dat", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
	if (!reader_file_db.is_open())
		throw std::exception("Reader_db file open failed!");
	else
		load_reader_base();
}

Manager::~Manager() {
	if (book_file_db.is_open())
		book_file_db.close();
	if (reader_file_db.is_open())
		reader_file_db.close();
}

void Manager::load_book_base() {
	if (book_file_db.is_open()) {
		book_file_db.clear();
		book_file_db.seekg(0, std::ios::beg);
		Book::ULL id;
		unsigned int size_title = 0;
		unsigned int size_author = 0;
		char *title = nullptr;
		char *author = nullptr;
		Book::UINT pages;
		while (true) {
			book_file_db.read(reinterpret_cast<char *>(&id), sizeof(Book::ULL));
			book_file_db.read(reinterpret_cast<char *>(&size_title), sizeof(size_title));
			title = new char[size_title + 1];
			book_file_db.read(title, size_title);
			title[size_title] = '\0';
			book_file_db.read(reinterpret_cast<char *>(&size_author), sizeof(size_author));
			author = new char[size_author + 1];
			book_file_db.read(author, size_author);
			author[size_author] = '\0';
			book_file_db.read(reinterpret_cast<char *>(&pages), sizeof(Book::UINT));
			if (book_file_db.eof()) {
				if (title)
					delete title;
				if (author)
					delete author;
				break;
			}
			Book book(id, title, author, pages);
			if (title) {
				delete title;
				title = nullptr;
			}
			if (author) {
				delete author;
				author = nullptr;
			}
			add_book(book);
		}
	}
	else
		throw std::exception("File book_db is failed! Function load_book_base()");
	return;
}

void Manager::save_book_base() {
	if (book_file_db.is_open()) {
		book_file_db.clear();
		book_file_db.seekp(0, std::ios::beg);
		for (auto el : book_db) {
			Book::ULL id = el.first.get_id();
			unsigned int size_title = el.first.get_title().size();
			unsigned int size_author = el.first.get_author().size();
			Book::UINT pages = el.first.get_pages();
			book_file_db.write(reinterpret_cast<char const *>(&id), sizeof(Book::ULL));
			book_file_db.write(reinterpret_cast<char const *>(&size_title), sizeof(size_title));
			book_file_db.write(el.first.get_title().c_str(), size_title);
			book_file_db.write(reinterpret_cast<char const *>(&size_author), sizeof(size_author));
			book_file_db.write(el.first.get_author().c_str(), size_author);
			book_file_db.write(reinterpret_cast<char const *>(&pages), sizeof(Book::UINT));
			book_file_db.flush();
		}
	}
	else
		throw std::exception("File book_db is failed! Function save_book_base()");
	return;
}

void Manager::load_reader_base() {
	if (reader_file_db.is_open()) {
		reader_file_db.clear();
		reader_file_db.seekg(0, std::ios::beg);
		Reader::ULL reader_id;
		Book::ULL book_id;
		unsigned int size_first_name = 0;
		unsigned int size_last_name = 0;
		char *first_name = nullptr;
		char *last_name = nullptr;
		unsigned int count = 0;
		while (true) {
			reader_file_db.read(reinterpret_cast<char *>(&reader_id), sizeof(Reader::ULL));
			reader_file_db.read(reinterpret_cast<char *>(&size_first_name), sizeof(size_first_name));
			first_name = new char[size_first_name + 1];
			reader_file_db.read(first_name, size_first_name);
			first_name[size_first_name] = '\0';
			reader_file_db.read(reinterpret_cast<char *>(&size_last_name), sizeof(size_last_name));
			last_name = new char[size_last_name + 1];
			reader_file_db.read(last_name, size_last_name);
			last_name[size_last_name] = '\0';
			reader_file_db.read(reinterpret_cast<char *>(&count), sizeof(count));
			if (reader_file_db.eof()) {
				if (first_name)
					delete first_name;
				if (last_name)
					delete last_name;
				break;
			}
			Reader reader(reader_id, first_name, last_name);
			if (first_name) {
				delete first_name;
				first_name = nullptr;
			}
			if (last_name) {
				delete last_name;
				last_name = nullptr;
			}
			add_reader(reader);
			for (size_t i = 0; i < count; ++i) {
				reader_file_db.read(reinterpret_cast<char *>(&book_id), sizeof(book_id));
				add_book_to_reader(reader_id, book_id);
			}
		}
	}
	else
		throw std::exception("File reader_db is failed! Function load_reader_base()");
	return;
}

void Manager::save_reader_base() {
	if (reader_file_db.is_open()) {
		reader_file_db.clear();
		reader_file_db.seekp(0, std::ios::beg);
		for (auto el : reader_db) {
			Reader::ULL id = el.first.get_id();
			unsigned int size_first_name = el.first.get_first_name().size();
			unsigned int size_last_name = el.first.get_last_name().size();
			unsigned int count = el.second.size();
			reader_file_db.write(reinterpret_cast<char const *>(&id), sizeof(Reader::ULL));
			reader_file_db.write(reinterpret_cast<char const *>(&size_first_name), sizeof(size_first_name));
			reader_file_db.write(el.first.get_first_name().c_str(), size_first_name);
			reader_file_db.write(reinterpret_cast<char const *>(&size_last_name), sizeof(size_last_name));
			reader_file_db.write(el.first.get_last_name().c_str(), size_last_name);
			reader_file_db.write(reinterpret_cast<char const *>(&count), sizeof(count));
			for (auto id : el.second)
				reader_file_db.write(reinterpret_cast<char const *>(&id), sizeof(Book::ULL));
			reader_file_db.flush();
		}
	}
	else
		throw std::exception("File reader_db is failed! Function save_reader_base()");
	return;
}

void Manager::print_all_books() const {
	std::cout << std::setw(HEAD_WIDTH) << "Id:" << std::setw(HEAD_WIDTH) << "Title:" << std::setw(HEAD_WIDTH) << "Author:" << std::setw(HEAD_WIDTH) <<
		"Pages:" << std::setw(HEAD_WIDTH) << "Count:" << std::endl;
	for (auto el : book_db)
		std::cout << std::setw(ROW_WIDTH) << el.first.get_id() << " |" << std::setw(ROW_WIDTH) << el.first.get_title() << " |" << std::setw(ROW_WIDTH) <<
		el.first.get_author() << " |" << std::setw(ROW_WIDTH) << el.first.get_pages() << " |" << std::setw(ROW_WIDTH) << el.second << std::endl;
	return;
}

void Manager::print_all_readers() const {
	std::cout << std::setw(HEAD_WIDTH) << "Id:" << std::setw(HEAD_WIDTH) << "First name:" << std::setw(HEAD_WIDTH) << "Last name:" << std::endl;
	for (auto el : reader_db)
		std::cout << std::setw(ROW_WIDTH) << el.first.get_id() << " |" << std::setw(ROW_WIDTH) << el.first.get_first_name() << " |" << std::setw(ROW_WIDTH) <<
		el.first.get_last_name() << " |" << std::endl;
	return;
}

void Manager::add_book(Book &book) {
	if (book_db.find(book) == book_db.cend())
		book_db[std::move(book)] = 1;
	else
		++book_db[book];
	return;
}

void Manager::delete_book(Book &book) {
	auto found_book = book_db.find(book);
	if (found_book != book_db.cend())
		book_db.erase(found_book);
	return;
}

void Manager::add_reader(Reader &reader) {
	if (reader_db.find(reader) == reader_db.cend())
		reader_db[std::move(reader)];
	return;
}

void Manager::delete_reader(Reader &reader) {
	auto found_reader = reader_db.find(reader);
	if (found_reader != reader_db.cend())
		reader_db.erase(found_reader);
	return;
}

void Manager::add_book_to_reader(Reader::ULL reader_id, Book::ULL book_id) {
	Reader reader(reader_id, "", "");
	auto found_reader = reader_db.find(reader);
	if (found_reader == reader_db.cend()) {
		std::cout << "Reader not found!" << std::endl;
		return;
	}
	Book book(book_id, "", "", 0);
	auto found_book = book_db.find(book);
	if (found_book == book_db.cend()) {
		std::cout << "Book not found!" << std::endl;
		return;
	}
	auto found = std::find((*found_reader).second.cbegin(), (*found_reader).second.cend(), book_id);
	if (found != (*found_reader).second.cend()) {
		std::cout << "Reader already has the book!" << std::endl;
		return;
	}
	if ((*found_book).second) {
		(*found_reader).second.push_back(book_id);
		(*found_book).second--; //уменьшаем количество книг в библиотеке
	}
	else
		std::cout << "Book is absent";
	return;
}

void Manager::delete_book_from_reader(Reader::ULL reader_id, Book::ULL book_id) {
	Reader reader(reader_id, "", "");
	auto found_reader = reader_db.find(reader);
	if (found_reader == reader_db.cend()) {
		std::cout << "Reader not found!" << std::endl;
		return;
	}
	Book book(book_id, "", "", 0);
	auto found_book = book_db.find(book);
	if (found_book == book_db.cend()) {
		std::cout << "Book not found!" << std::endl;
		return;
	}
	auto found = std::find((*found_reader).second.cbegin(), (*found_reader).second.cend(), book_id);
	if (found == (*found_reader).second.cend()) {
		std::cout << "Reader has not the book!" << std::endl;
		return;
	}
	(*found_reader).second.erase(found);
	(*found_book).second++; //увеличиваем количество книг в библиотеке
	return;
}

void Manager::print_books_of_reader(Reader::ULL id) {
	Reader reader(id, "", "");
	auto found_reader = reader_db.find(reader);
	if (found_reader == reader_db.cend()) {
		std::cout << "Reader not found!" << std::endl;
		return;
	}
	if (!(*found_reader).second.empty()) {
		std::cout << std::setw(HEAD_WIDTH) << "Id:" << std::setw(HEAD_WIDTH) << "Title:" << std::setw(HEAD_WIDTH) << "Author:" << std::setw(HEAD_WIDTH) <<
			"Pages" << std::endl;
		for (auto book_id : (*found_reader).second) {
			Book temp_book(book_id, "", "", 0);
			auto book = book_db.find(temp_book);
			if (book != book_db.cend())
				std::cout << std::setw(ROW_WIDTH) << book->first.get_id() << " |" << std::setw(ROW_WIDTH) << book->first.get_title() << " |" << std::setw(ROW_WIDTH) <<
				book->first.get_author() << " |" << std::setw(ROW_WIDTH) << book->first.get_pages() << " |" << std::endl;
		}
	}
	return;
}

unsigned long long Manager::give_next_id(TypeId type_id) const {
	unsigned long long id = 0;
	switch (type_id) {
	case TypeId::Book: {
		auto book_const_riter = book_db.crbegin();
		if (book_const_riter != book_db.crend())
			id = (*book_const_riter).first.get_id();
		return ++id;
	}
	case TypeId::Reader: {
		auto reader_const_riter = reader_db.crbegin();
		if (reader_const_riter != reader_db.crend())
			id = (*reader_const_riter).first.get_id();
		return ++id;
	}
	}
}