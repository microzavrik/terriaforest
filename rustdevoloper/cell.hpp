#pragma once

#include "include.hpp"

struct cell
{
	cell(char point, const std::string& texture_path);
	char texture_pointer;
	sf::Texture texture;
};