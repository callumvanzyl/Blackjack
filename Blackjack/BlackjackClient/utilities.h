#pragma once

#include <string>

namespace utilities
{
	const enum TEXT_COLORS { BAD = 12, OKAY = 14, GOOD = 10 };

	bool is_valid_path(std::string path);
	void print_error(std::string text);
	void print_warning(std::string text);
	void print_success(std::string text);
}