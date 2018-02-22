#include <iostream>
#include <time.h>

int main()
{
	int dice_comp1, dice_comp2, dice_user1, dice_user2, sum_comp = 0, sum_user = 0, points_comp = 0, points_user = 0, sum;
	std::cout << "Please, enter final game points - ";
	std::cin >> sum;
	std::cout << std::endl;
	getchar();
	do
	{
		srand((unsigned)time(NULL));
		dice_comp1 = rand() % 6 + 1;
		dice_comp2 = rand() % 6 + 1;
		sum_comp = sum_comp + dice_comp1 + dice_comp2;
		std::cout << "Computer " << dice_comp1 << "\t" << dice_comp2 << "\t" << "Sum - " << sum_comp << std::endl << std::endl;
		if (dice_comp1 == dice_comp2)
			points_comp += 2;
		std::cout << "User's turn (press \"Enter\" for play)\n";
		getchar();
		dice_user1 = rand() % 6 + 1;
		dice_user2 = rand() % 6 + 1;
		sum_user = sum_user + dice_user1 + dice_user2;
		std::cout << "User " << dice_user1 << "\t" << dice_user2 << "\t" << "Sum - " << sum_user << std::endl << std::endl;
		if (dice_user1 == dice_user2)
			points_user += 2;
		if ((dice_comp1 + dice_comp2) > (dice_user1 + dice_user2))
			points_comp++;
		if ((dice_comp1 + dice_comp2) < (dice_user1 + dice_user2))
			points_user++;
		std::cout << "Computer's points - " << points_comp << " User's points - " << points_user << std::endl << std::endl;
	} while ((sum_comp < sum) && (sum_user < sum));
	if (points_comp > points_user)
		std::cout << "Computer win!\n";
	if (points_comp < points_user)
		std::cout << "User win\n";
	if (points_comp == points_user)
		std::cout << "Draw\n";
	system("pause");
	return EXIT_SUCCESS;
}