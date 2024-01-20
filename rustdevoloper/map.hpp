#pragma once

#include "include.hpp"
#include "cell.hpp"

class map
{
public:
	map(const std::string& map_data_file, const std::string& first_layer_data);
	std::vector<cell> map_data_cells;
	std::array<std::array<char, 12>, 12> first_layer;
	std::pair<bool, size_t> contains_pointer(char pointer);
};