#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "base.h"

GAI::GAI()
{
	root = nullptr;
}

GAI::~GAI()
{
	del(root);
	root = nullptr;
}

void GAI::add_infraction()
{
	if (!root)
	{
		Base *new_element = new Base;
		char key[128];
		std::cout << "Введите номер автомобиля - ";
		std::cin >> new_element->number;
		std::cout << "Введите нарушение - ";
		std::cin >> key;
		new_element->infraction = new char*[++new_element->n];
		new_element->infraction[new_element->n - 1] = new char[strlen(key) + 1];
		strcpy(new_element->infraction[new_element->n - 1], key);
		new_element->left = new_element->right = new_element->parient = nullptr;
		root = new_element;
	}
	else
	{
		Base *new_element;
		size_t num;
		char key[128];
		std::cout << "Введите номер автомобиля - ";
		std::cin >> num;
		if (new_element = search_number(num))
		{
			std::cout << "Введите нарушение - ";
			std::cin >> key;
			char **temp;
			temp = new char*[++new_element->n];
			for (size_t i = 0; i < new_element->n - 1; i++)
			{
				temp[i] = new char[strlen(new_element->infraction[i]) + 1];
				strcpy(temp[i], new_element->infraction[i]);
				delete new_element->infraction[i];
			}
			temp[new_element->n - 1] = new char[strlen(key) + 1];
			strcpy(temp[new_element->n - 1], key);
			delete[]new_element->infraction;
			new_element->infraction = temp;
		}
		else
		{
			insert_number(num);
		}
	}
}

Base* GAI::search_number(const size_t num) const
{
	Base *temp = root;
	while (temp && (num != temp->number))
	{
		if (num < temp->number)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

void GAI::insert_number(const size_t num)
{
	Base *up_point = nullptr, *temp = root, *new_element = new Base;
	new_element->parient = new_element->left = new_element->right = nullptr;
	while (temp)
	{
		up_point = temp;
		if (num < temp->number)
			temp = temp->left;
		else
			temp = temp->right;
	}
	new_element->parient = up_point;
	if (!up_point)
		root = new_element;
	else
		if (num < up_point->number)
			up_point->left = new_element;
		else
			up_point->right = new_element;
	new_element->number = num;
	char key[128];
	std::cout << "Введите нарушение - ";
	std::cin >> key;
	new_element->infraction = new char*[++new_element->n];
	new_element->infraction[new_element->n - 1] = new char[strlen(key) + 1];
	strcpy(new_element->infraction[new_element->n - 1], key);
}

void GAI::insert_node(Base &element)
{
	Base *up_point = root, *temp = root, *add = new Base;
	add->number = element.number;
	add->n = element.n;
	add->infraction = new char*[add->n];
	for (size_t i = 0; i < add->n; i++)
	{
		add->infraction[i] = new char[strlen(element.infraction[i]) + 1];
		strcpy(add->infraction[i], element.infraction[i]);
	}
	add->parient = add->left = add->right = nullptr;
	while (temp)
	{
		up_point = temp;
		if (add->number < temp->number)
			temp = temp->left;
		else
			temp = temp->right;
	}
	add->parient = up_point;
	if (!up_point)
		root = add;
	else
		if (add->number < up_point->number)
			up_point->left = add;
		else
			up_point->right = add;
}

void GAI::print_all(Base *temp) const
{
	if (temp)
	{
		print_all(temp->left);
		std::cout << "Номер машины - " << temp->number << ":\n";
		for (size_t i = 0; i < temp->n; i++)
			std::cout << i + 1 << ". " << temp->infraction[i] << std::endl;
		std::cout << std::endl;
		print_all(temp->right);
	}
}

void GAI::print_one() const
{
	Base *temp;
	size_t key;
	std::cout << "Введите номер для поиска - ";
	std::cin >> key;
	if (temp = search_number(key))
	{
		std::cout << "Номер машины - " << temp->number << ":\n";
		for (size_t i = 0; i < temp->n; i++)
			std::cout << i + 1 << ". " << temp->infraction[i] << std::endl;
	}
	else
	{
		std::cout << "Искомого номера в базе не найдено!\n";
	}
}

void GAI::print_diapazon() const
{
	size_t low, hi;
	Base* temp = nullptr;
	std::cout << "Введите границы поиска номеров:\nНижняя - ";
	std::cin >> low;
	std::cout << "Верхняя - ";
	std::cin >> hi;
	for (; low <= hi; low++)
	{
		temp = search_number(low);
		if (temp)
		{
			std::cout << "Номер машины - " << temp->number << ":\nНарушения:\n";
			for (size_t i = 0; i < temp->n; i++)
				std::cout << i + 1 << ". " << temp->infraction[i] << std::endl;
		}
		temp = nullptr;
	}
}

Base* GAI::get_root() const
{
	return root;
}

void GAI::del(Base *temp)
{
	if (temp)
	{
		del(temp->left);
		for (size_t i = 0; i < temp->n; i++)
			delete temp->infraction[i];
		delete temp->infraction;
		del(temp->right);
		delete temp;
	}
}

void GAI::read_from_file(FILE *file)
{
	int size, *ptr_size;
	ptr_size = &size;
	char *str;
	Base *temp;
	while (!feof(file))
	{
		temp = new Base;
		fread(temp, sizeof(Base), 1, file);
		if (feof(file))
		{
			delete temp;
			break;
		}
		temp->infraction = new char*[temp->n];
		for (size_t i = 0; i < temp->n; i++)
		{
			fread(ptr_size, sizeof(int), 1, file);
			str = new char[size];
			fread(str, size, 1, file);
			temp->infraction[i] = new char[size];
			strcpy(temp->infraction[i], str);
			delete str;
		}
		insert_node(*temp);
		for (size_t i = 0; i < temp->n; i++)
		{
			delete temp->infraction[i];
		}
		delete temp->infraction;
		delete temp;
	}
}

void GAI::save_to_file(FILE *file, Base *temp)
{
	int size, *ptr_size;
	ptr_size = &size;
	if (temp)
	{
		save_to_file(file, temp->left);
		fwrite(temp, sizeof(Base), 1, file);
		for (size_t i = 0; i < temp->n; i++)
		{
			size = strlen(temp->infraction[i]) + 1;
			fwrite(ptr_size, sizeof(int), 1, file);
			fwrite(temp->infraction[i], size, 1, file);
		}
		save_to_file(file, temp->right);
	}
}