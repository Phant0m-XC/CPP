#pragma once
struct Base
{
	size_t number;
	char **infraction;
	size_t n = 0;
	Base *left, *right, *parient;
};

class GAI
{
	Base *root;
public:
	GAI();
	~GAI();
	void add_infraction();
	Base* search_number(const size_t) const;
	void insert_number(const size_t);
	void insert_node(Base&);
	void print_all(Base*) const;
	void print_one() const;
	void print_diapazon() const;
	Base* get_root() const;
	void del(Base*);
	void read_from_file(FILE*);
	void save_to_file(FILE*, Base*);
};