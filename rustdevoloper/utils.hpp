#pragma once

#include <iostream>
#include <iterator>
#include <vector>

void print_2d_container(std::vector<std::vector<char>>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j];
		}
		std::cout << std::endl;
	}
}