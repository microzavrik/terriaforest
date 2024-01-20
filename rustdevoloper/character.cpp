#include "character.hpp"

character::character(const std::string& path_to_texture,
	const std::string& path_to_run_texture,
	float speed, 
	std::uint16_t frame_count,
	std::uint32_t frame_spacing)
	: movement_speed(speed)
{

	idle_station.characterTexture.loadFromFile(path_to_texture);

	std::cout << path_to_texture << std::endl;
	idle_station.frameWidth = idle_station.characterTexture.getSize().x / 6;
	std::cout << idle_station.frameWidth << std::endl;
	idle_station.frameHeight = idle_station.characterTexture.getSize().y;
	std::cout << idle_station.frameHeight << std::endl;
	idle_station.frameCount = frame_count;
	idle_station.frameSpacing = 0;

	idle_station.characterSprite = sf::Sprite(idle_station.characterTexture);
	idle_station.characterSprite.setTextureRect(sf::IntRect(0, 0, idle_station.frameWidth,
		idle_station.frameHeight));
	idle_station.characterSprite.setScale(3.0f, 3.0f);
	idle_station.characterSprite.setPosition(0, 0);

	/// 

	run_station.characterTexture.loadFromFile(path_to_run_texture);

	run_station.frameWidth = run_station.characterTexture.getSize().x / 6;
	run_station.frameHeight = run_station.characterTexture.getSize().y;
	run_station.frameCount = 6;
	run_station.frameSpacing = 20;

	run_station.characterSprite = sf::Sprite(run_station.characterTexture);
	run_station.characterSprite.setTextureRect(sf::IntRect(0, 0, run_station.frameWidth,
		run_station.frameHeight));
	run_station.characterSprite.setScale(5.0f, 5.0f);
	run_station.characterSprite.setPosition(0, 0);
}

void character::render_animation()
{
	if (a_station == anim_station::idle)
	{
		if (idle_station.clock.getElapsedTime().asSeconds() > idle_station.frameDuration)
		{
			idle_station.currentFrame = (idle_station.currentFrame + 1) % idle_station.frameCount;
			std::cout << idle_station.currentFrame << std::endl;
			idle_station.characterSprite.setTextureRect
			(sf::IntRect(idle_station.currentFrame * idle_station.frameWidth, 0, idle_station.frameWidth,
				idle_station.frameHeight));
			idle_station.clock.restart();
		}
	}
	if (a_station == anim_station::run)
	{
		if (run_station.clock.getElapsedTime().asSeconds() > run_station.frameDuration)
		{
			run_station.currentFrame = (run_station.currentFrame + 1) % run_station.frameCount;
			run_station.characterSprite.setTextureRect
			(sf::IntRect(run_station.currentFrame * run_station.frameWidth, 0, run_station.frameWidth,
				run_station.frameHeight));
			run_station.clock.restart();
		}
	}
}

sf::Sprite& character::get_sprite()
{
	switch (a_station)
	{
	case anim_station::idle:
		return idle_station.characterSprite;
	case anim_station::run:
		return run_station.characterSprite;
	}

	return idle_station.characterSprite;
}

void character::move(key_direction dx)
{
	switch (dx)
	{
	case key_direction::Up:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		idle_station.characterSprite.move(0, -movement_speed);
		run_station.characterSprite.move(0, -movement_speed);
		break;
	case key_direction::Down:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		idle_station.characterSprite.move(0, movement_speed);
		run_station.characterSprite.move(0, movement_speed);
		break;
	case key_direction::Right:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		if (current_direction != key_direction::Right)
		{
			current_direction = key_direction::Right;
			idle_station.characterSprite.setScale(5.0f, 5.0f);
			idle_station.characterSprite.setOrigin(idle_station.characterSprite.getLocalBounds().width / 2, idle_station.characterSprite.getLocalBounds().height / 2);
			run_station.characterSprite.setScale(5.0f, 5.0f);
			run_station.characterSprite.setOrigin(run_station.characterSprite.getLocalBounds().width / 2, run_station.characterSprite.getLocalBounds().height / 2);
		}
		idle_station.characterSprite.move(movement_speed, 0);
		run_station.characterSprite.move(movement_speed, 0);
		break;
	case key_direction::Left:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		if (current_direction != key_direction::Left)
		{
			current_direction = key_direction::Left;
			idle_station.characterSprite.setScale(-5.0f, 5.0f);
			idle_station.characterSprite.setOrigin(idle_station.characterSprite.getLocalBounds().width / 2, idle_station.characterSprite.getLocalBounds().height / 2);
			run_station.characterSprite.setScale(-5.0f, 5.0f);
			run_station.characterSprite.setOrigin(run_station.characterSprite.getLocalBounds().width / 2, run_station.characterSprite.getLocalBounds().height / 2);
		}
		idle_station.characterSprite.move(-movement_speed, 0);
		run_station.characterSprite.move(-movement_speed, 0);
		break;
	}
}