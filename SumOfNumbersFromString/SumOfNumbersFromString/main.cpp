/*
Программа для поиска суммы чётных и нечётных чисел
представленных в произвольной строке символов
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

int main()
{
	std::string str;
	int sum_even = 0, sum_odd = 0;
	int temp = 0;
	std::cout << "Enter string: ";
	std::getline(std::cin, str);
	for (int i = 0; i < str.length(); ++i) {
		if (std::isdigit(str.at(i))) {
			temp *= 10;
			temp += str.at(i) - '0';
		}
		else {
			if (!(temp % 2))
				sum_even += temp;
			else
				sum_odd += temp;
			temp = 0;
		}
	}
	//на случай, если последний символ - цифра
	if (temp)
		if (!(temp % 2))
			sum_even += temp;
		else
			sum_odd += temp;
	std::cout << "Sum of EVEN numbers: " << sum_even << std::endl;
	std::cout << "Sum of ODD numbers: " << sum_odd << std::endl;
	std::getchar();
	return EXIT_SUCCESS;
}