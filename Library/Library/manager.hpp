#ifndef MANAGER_H
#define MANAGER_H

#define HEAD_WIDTH 14
#define ROW_WIDTH 12

#include <list>
#include <map>
#include <fstream>
#include "book.hpp"
#include "reader.hpp"

class Manager {
	std::fstream book_file_db;
	std::fstream reader_file_db;
	std::map<Book, int> book_db;
	std::map<Reader, std::list<Book::ULL> > reader_db;
public:
	enum class TypeId { Book, Reader };
	Manager();
	Manager(Manager const &) = delete;
	Manager(Manager&&) = delete;
	~Manager();
	Manager operator=(Manager const &) = delete;
	Manager operator=(Manager&&) = delete;
	void load_book_base();
	void save_book_base();
	void load_reader_base();
	void save_reader_base();
	void print_all_books() const;
	void print_all_readers() const;
	void add_book(Book &);
	void delete_book(Book &);
	void add_reader(Reader &);
	void delete_reader(Reader &);
	void add_book_to_reader(Reader::ULL, Book::ULL);
	void delete_book_from_reader(Reader::ULL, Book::ULL);
	void print_books_of_reader(Reader::ULL);
	unsigned long long give_next_id(TypeId) const;
};

#endif
