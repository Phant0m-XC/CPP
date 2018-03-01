//база ГАИ
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <locale.h>
#include <Windows.h>
#include "base.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	bool go_on1 = true, go_on2 = true;
	FILE* file = nullptr;
	file = fopen("base.dat", "rb+");
	if (!file)
	{
		while (go_on1)
		{
			system("cls");
			std::cout << "Создать новый файл базы данных? (Y - Да, N - Нет): ";
			switch (_getch())
			{
			case 'Y':
			case 'y':
				file = fopen("base.dat", "wb+");
				go_on1 = false;
				break;
			case 'N':
			case 'n':
				std::cout << "\nФайл базы данных не найден!\nПрограмма завершена!\n";
				go_on1 = go_on2 = false;
				break;
			default:
				std::cout << "Неверный выбор!\n";
				Sleep(500);
				break;
			}
		}
	}
	GAI A;
	while (go_on2)
	{
		system("cls");
		std::cout << "---=== Меню программы База ГАИ===---\n";
		std::cout << "1 - Загрузить данные из файла\n";
		std::cout << "2 - Внести данные о правонарушении\n";
		std::cout << "3 - Вывести на экран всю базу данных\n";
		std::cout << "4 - Найти номер автомобиля в базе данных\n";
		std::cout << "5 - Найти диапазон номеров автомобилей в базе данных\n";
		std::cout << "0 - Сохранить файл базы данных и выйти из программы\n";
		std::cout << "------========================------\n";
		switch (_getch())
		{
		case '1':
			fseek(file, 0, SEEK_SET);
			A.read_from_file(file);
			std::cout << "База данных успешно загружена!";
			Sleep(500);
			break;
		case '2':
			system("cls");
			A.add_infraction();
			std::cout << "Данные внесены!";
			Sleep(500);
			break;
		case '3':
			system("cls");
			A.print_all(A.get_root());
			_getch();
			break;
		case '4':
			system("cls");
			A.print_one();
			_getch();
			break;
		case '5':
			system("cls");
			A.print_diapazon();
			_getch();
			break;
		case '0':
			go_on2 = false;
			fseek(file, 0, SEEK_SET);
			A.save_to_file(file, A.get_root());
			if (fclose(file) == EOF)
				std::cout << "Ошибка закрытия файла! Программа завершена!\n";
			else
				std::cout << "Файл успешно сохранён. Программа завершена.\n";
			break;
		default:
			std::cout << "Неверный выбор!";
			Sleep(500);
			break;
		}
	}
	return 0;
}