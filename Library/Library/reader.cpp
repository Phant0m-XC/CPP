#include "reader.hpp"

Reader::Reader(ULL id, std::string first_name, std::string last_name) : id(id), first_name(first_name), last_name(last_name) {}

bool Reader::operator<(Reader const &reader) const {
	return this->id < reader.id;
}

bool Reader::operator==(Reader const &reader) const {
	return this->id == reader.id;
}

Reader::ULL Reader::get_id() const {
	return id;
}

std::string Reader::get_first_name() const {
	return first_name;
}

void Reader::set_first_name(std::string first_name) {
	this->first_name = first_name;
}

std::string Reader::get_last_name() const {
	return last_name;
}

void Reader::set_last_name(std::string last_name) {
	this->last_name = last_name;
}
