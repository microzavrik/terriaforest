#include "cell.hpp"

cell::cell(char point, const std::string& texture_path)
{
	texture_pointer = point;
	texture.loadFromFile(texture_path);
}