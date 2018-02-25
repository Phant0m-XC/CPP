#pragma once
#include <vector>
#include <mutex>

typedef unsigned int u_int;

class PrimeNumberFinder {
	u_int serial_number;							//serial number
	u_int start;									//begin
	u_int end;										//end
	bool is_current_number_prime;					//true - prime number
	std::vector<u_int> *my_prime_numbers;			//container of prime numbers (temporary)
	static u_int count;								//count of prime numbers
	static std::mutex *my_lock;						//locker
public:
	PrimeNumberFinder(u_int, u_int, u_int);
	PrimeNumberFinder(const PrimeNumberFinder&);
	~PrimeNumberFinder();
	void search_prime_number(std::vector<u_int>*, bool*);		//search method
	static void change_count();									//change count
	static void reset_count();
};