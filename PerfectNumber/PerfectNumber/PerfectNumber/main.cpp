#include <iostream>
#include <cstdlib>

using ULL = unsigned long long;

bool perfect_number(ULL);

int main() {

	for (ULL i = 0; i <= ULONG_MAX; ++i)
		if(perfect_number(i)) std::cout << i << ' ';
		
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

bool perfect_number(ULL num) {
	ULL sum = 0;
	for (ULL del = 1; del < num; ++del)
		if (!(num % del))
			sum += del;
	return sum == num;
}