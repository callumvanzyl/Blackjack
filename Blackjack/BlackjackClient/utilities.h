#pragma once

#include <string>

const enum TEXT_COLORS { BAD = 12, OKAY = 14, GOOD = 10 };

bool is_valid_path(std::string path);
float normalise(int n, int i_min, int i_max, int o_min, int o_max);
void print_error(std::string text);
void print_warning(std::string text);
void print_success(std::string text);