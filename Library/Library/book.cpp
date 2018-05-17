#include "book.hpp"

Book::Book(ULL id, std::string title, std::string author, UINT pages) : id(id), title(title), author(author), pages(pages) {}

bool Book::operator<(Book const &book) const {
	return this->id < book.id;
}

bool Book::operator==(Book const &book) const {
	return this->id == book.id;
}

Book::ULL Book::get_id() const {
	return id;
}

void Book::set_id(ULL id) {
	this->id = id;
}

std::string Book::get_title() const {
	return title;
}

void Book::set_title(std::string title) {
	this->title = title;
}

std::string Book::get_author() const {
	return author;
}

void Book::set_author(std::string author) {
	this->author = author;
}

Book::UINT Book::get_pages() const {
	return pages;
}

void Book::set_pages(UINT pages) {
	this->pages = pages;
}
