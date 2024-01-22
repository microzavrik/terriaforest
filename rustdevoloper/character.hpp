#pragma once

#define TEST

#include "include.hpp"
#include "animation_path.hpp"

enum class key_direction
{
	Up,
	Down,
	Right,
	Left
};

struct character_animation_station
{
	sf::Texture characterTexture;
	sf::Sprite characterSprite;

	std::int32_t frameWidth;
	std::int32_t frameHeight;
	std::int32_t frameCount;
	std::int32_t frameSpacing;

	sf::Clock clock;
	float frameDuration = 0.2f;
	std::int32_t currentFrame = 0;
};

enum class anim_station
{
	run,
	idle,
	attack
};

class character
{
public:
	character(const animation_path& packet, float speed);
	void render_animation();
	sf::Sprite& get_sprite();
	void animation_loader(character_animation_station& station, const std::string& path, const std::uint16_t frames);

	void update_animation_position(key_direction dx);
	void move(key_direction dx);
	anim_station a_station = anim_station::idle;
private:
	character_animation_station idle_station_back;
	character_animation_station run_station_back;
	
	character_animation_station idle_station_side_left;
	character_animation_station run_station_side_left;

	character_animation_station idle_station_side_right;
	character_animation_station run_station_slide_right;
	
	character_animation_station idle_station_top;
	character_animation_station run_station_top;

#ifndef TEST
	character_animation_station test_animation;
#endif

	key_direction current_direction = key_direction::Down;
	float movement_speed;

	float weapon_offset_x = 2.f;
	float weapon_offset_y = 1.0f;
};