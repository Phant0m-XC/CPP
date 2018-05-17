#ifndef RAEDER_H
#define READER_H

#include <string>

class Reader {
public:
	using ULL = unsigned long long;
private:
	ULL id;
	std::string first_name;
	std::string last_name;
public:
	Reader(ULL, std::string, std::string);
	Reader(Reader const &) = default;
	Reader(Reader &&) = default;
	~Reader() = default;
	bool operator<(Reader const &) const;
	bool operator==(Reader const &) const;
	ULL get_id() const;
	std::string get_first_name() const;
	void set_first_name(std::string);
	std::string get_last_name() const;
	void set_last_name(std::string);
};

#endif
