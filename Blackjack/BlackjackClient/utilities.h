#pragma once

#include <string>

const enum TEXT_COLORS { BAD = 12, OKAY = 14, GOOD = 10 };

void print_error(std::string text);
void print_warning(std::string text);
void print_success(std::string text);