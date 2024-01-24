#pragma once

#include "include.hpp"

class colision_object
{
public:
	colision_object(const std::string& ind, const std::string texture_path, std::int32_t x, std::int32_t y);
	void setup_collision();
	void delete_colision();

	std::int32_t get_x() { return m_xcoord; }
	std::int32_t get_y() { return m_ycoord; }
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::string m_indificator;
	bool m_colision_on;

	std::int32_t m_xcoord;
	std::int32_t m_ycoord;
};