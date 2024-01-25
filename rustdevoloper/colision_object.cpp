#include "colision_object.hpp"

colision_object::colision_object(const std::string& ind, std::int32_t x, std::int32_t y)
{
	m_indificator = ind;

	m_xcoord = x;
	m_ycoord = y;
}

void colision_object::setup_collision()
{
	m_colision_on = true;
}

void colision_object::delete_colision()
{
	m_colision_on = false;
}