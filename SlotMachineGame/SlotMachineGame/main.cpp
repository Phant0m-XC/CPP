#include <iostream>
#include <time.h>

int main()
{
	const int SIZE = 10;
	int cylinder[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num1, num2, num3, variant;
	double bet, money, prize;
	std::cout << "Please, enter the amount of money you have: ";
	std::cin >> money;
	getchar();
	do
	{
		std::cout << "Make your bet: ";
		std::cin >> bet;
		getchar();
		if (bet <= money)
		{
			money -= bet;
			std::cout << "Press <Enter> to play.\n";
			getchar();
			srand((unsigned)time(NULL));
			num1 = rand() % 10;
			num2 = rand() % 10;
			num3 = rand() % 10;
			std::cout << "CYLINDER: |" << cylinder[num1] << "| |" << cylinder[num2] << "| |" << cylinder[num3] << "|" << std::endl;
			variant = 0;
			if (cylinder[num1] == (cylinder[num2] - 1) && cylinder[num1] == (cylinder[num3] - 2) && cylinder[num2] == (cylinder[num3] - 1))
				variant = 1;
			if (cylinder[num1] == cylinder[num2] && cylinder[num1] == cylinder[num3])
				variant = 2;
			switch (variant)
			{
			case 1:
				prize = bet * 0.3;
				break;
			case 2:
				prize = bet * 0.5;
				break;
			default:
				prize = 0;
				break;
			}
			if (prize > 0)
			{
				std::cout << "You win! Your prize is: " << prize << std::endl;
				bet += prize;
			}
			else
			{
				std::cout << "You lose!\n";
				bet = 0;
			}
			money += bet;
			std::cout << "You have money " << money << ".\n";
		}
		else
			std::cout << "You don't have money for this bet. Make another bet!\n";
	} while (money > 0);
	std::cout << "Sorry, you don't have money!\nGame over!\n";
	system("pause");
	return EXIT_SUCCESS;
}