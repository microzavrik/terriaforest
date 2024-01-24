#pragma once

#include "include.hpp"
#include "cell.hpp"
#include "colision_object.hpp"

class map
{
public:
	map(const std::string& map_data_file, const std::string& first_layer_data, const std::string& second_layer_data, 
		const std::string& colision_cfg);
	std::vector<cell> map_data_cells;
	std::vector<std::vector<char>> first_layer;
	std::vector<std::vector<char>> second_layer;
	std::pair<bool, size_t> contains_pointer(char pointer);
	std::vector<char> colision_char_list;

	std::vector<colision_object> colision_objects;

	char placeholder_empty_cells = '_';
};