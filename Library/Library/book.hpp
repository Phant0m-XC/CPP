#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
	using UINT = unsigned int;
	using ULL = unsigned long long;
private:
	ULL id;
	std::string title;
	std::string author;
	UINT pages;
public:
	Book(ULL, std::string, std::string, UINT);
	Book(Book const &) = default;
	Book(Book &&) = default;
	~Book() = default;
	bool operator<(Book const &) const;
	bool operator==(Book const &) const;
	ULL get_id() const;
	void set_id(ULL);
	std::string get_title() const;
	void set_title(std::string);
	std::string get_author() const;
	void set_author(std::string);
	UINT get_pages() const;
	void set_pages(UINT);
};

#endif
