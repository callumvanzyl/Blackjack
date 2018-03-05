#include <fstream>
#include <iostream>
#include <windows.h>

#include "utilities.h"

bool is_valid_path(std::string path)
{
	std::fstream checker(path);
	bool t = checker.is_open();
	checker.close();
	return t;
}

float normalise(int n, int i_min, int i_max, int o_min, int o_max)
{
	return (((n - i_min) / (i_max - i_min)) * (o_max - o_min) + o_min);
}

void print_colored_text(std::string text, TEXT_COLORS color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void print_error(std::string text) // Prints bright red text to the CLI
{
	print_colored_text(text, TEXT_COLORS::BAD);
}

void print_warning(std::string text) // Prints yellow text to the CLI
{
	print_colored_text(text, TEXT_COLORS::OKAY);
}

void print_success(std::string text) // Prints bright green text to the CLI
{
	print_colored_text(text, TEXT_COLORS::GOOD);
}