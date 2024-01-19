#pragma once

#include "include.hpp"

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
	float frameDuration = 0.1f;
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
	character(const std::string& path_to_texture, const std::string& path_to_run_texture, float speed);
	void render_animation();
	sf::Sprite& get_sprite();

	void move(key_direction dx);
	anim_station a_station;
private:
	character_animation_station idle_station;
	character_animation_station run_station;
	key_direction current_direction;
	float movement_speed;

	float weapon_offset_x = 2.f;
	float weapon_offset_y = 1.0f;
};