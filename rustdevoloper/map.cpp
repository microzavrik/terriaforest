#include "map.hpp"

map::map(const std::string& map_data_file, const std::string& first_layer_data, 
	const std::string& second_layer_data, const std::string& colision_cfg)
{
	std::ifstream colision_cfg_file(colision_cfg);
	std::string ch;
	while (std::getline(colision_cfg_file, ch))
	{
		colision_char_list.push_back(ch[0]);
	}

	std::cout << "Colision list:" << std::endl;
	for (size_t i = 0; i < colision_char_list.size(); i++) {
		std::cout << colision_char_list[i] << std::endl;
	}
	std::cout << std::endl;

	std::ifstream data_file(map_data_file);
	std::string line;
	while (std::getline(data_file, line))
	{
		std::istringstream data_stream(line);
		std::string symbol, texture_path;
		while (data_stream >> symbol >> texture_path)
		{
			map_data_cells.push_back(cell(symbol[0], texture_path));
			std::cout << texture_path << std::endl;
			std::cout << "Add data for cells" << std::endl;
		}
	}
	data_file.close();

	std::ifstream first_layer_file(first_layer_data);
	line.clear();
	size_t row = 0;
	while (std::getline(first_layer_file, line))
	{
		first_layer.push_back({});
		for (size_t i = 0; i < line.size(); i++)
		{
			first_layer[row].push_back(line[i]);
		}
		row++;
	}

	std::ifstream second_layer_file(second_layer_data);
	line.clear();
	row = 0;
	while (std::getline(second_layer_file, line))
	{
		second_layer.push_back({});
		for (size_t i = 0; i < line.size(); i++)
		{
			second_layer[row].push_back(line[i]);
		}
		row++;
	}

	std::cout << "==========================================" << std::endl;

	std::cout << "First layer map: " << std::endl;

	for (size_t i = 0; i < first_layer.size(); i++)
	{
		for (size_t j = 0; j < first_layer[i].size(); j++)
		{
			std::cout << first_layer[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << "==========================================" << std::endl;

	std::cout << "Second layer map: " << std::endl;

	for (size_t i = 0; i < second_layer.size(); i++)
	{
		for (size_t j = 0; j < second_layer[i].size(); j++)
		{
			std::cout << second_layer[i][j];
		}
		std::cout << std::endl;
	}


	std::cout << "==========================================" << std::endl;

	second_layer_file.close();
}

std::pair<bool, size_t> map::contains_pointer(char pointer)
{
	for (size_t i = 0; i < map_data_cells.size(); i++)
	{
		if (map_data_cells[i].texture_pointer == pointer) {
			return std::make_pair(true, i);
		}
	}
	return std::make_pair(false, -1);
}