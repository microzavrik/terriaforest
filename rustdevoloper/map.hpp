#pragma once

#include "include.hpp"
#include "cell.hpp"
#include "colision_object.hpp"

class map
{
public:
	map(const std::string& map_data_file, const std::string& first_layer_data);
	std::vector<cell> map_data_cells;
	std::vector<std::vector<char>> first_layer;
	std::pair<bool, size_t> contains_pointer(char pointer);

	std::vector<colision_object> colision_objects;
};