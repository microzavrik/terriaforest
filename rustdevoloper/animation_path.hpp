#pragma once

#include <string>
#include <utility>

struct animation_path
{
	std::pair<std::string, std::uint16_t> top_idle;
	std::pair<std::string, std::uint16_t> top_move;
	std::pair<std::string, std::uint16_t> back_idle;
	std::pair<std::string, std::uint16_t> back_move;
	std::pair<std::string, std::uint16_t> slide_idle_left;
	std::pair<std::string, std::uint16_t> slide_move_left;
	std::pair<std::string, std::uint16_t> slide_idle_right;
	std::pair<std::string, std::uint16_t> slide_move_right;
#ifndef TEST
	std::pair<std::string, std::uint16_t> test_sprite;
#endif
};