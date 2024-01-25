#pragma once

#include "include.hpp"

class colision_object
{
public:
	colision_object(const std::string& ind, std::int32_t x, std::int32_t y);
	void setup_collision();
	void delete_colision();

	std::string get_ind() { return m_indificator; }
	std::int32_t get_x() { return m_xcoord; }
	std::int32_t get_y() { return m_ycoord; }
	bool get_status() { return m_colision_on; }
private:
	std::string m_indificator;
	bool m_colision_on;

	std::int32_t m_xcoord;
	std::int32_t m_ycoord;
};