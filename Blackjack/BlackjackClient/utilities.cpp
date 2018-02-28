#include <iostream>
#include <windows.h>

#include "utilities.h"

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