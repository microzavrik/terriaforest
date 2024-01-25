#include "character.hpp"

#define TEST

character::character(const animation_path& packet, float speed, map& map_object) : movement_speed(speed), m_map(map_object)
{

	animation_loader(idle_station_top, packet.top_idle.first, packet.top_idle.second);
	animation_loader(run_station_top, packet.top_move.first, packet.top_move.second);

	animation_loader(idle_station_side_left, packet.slide_idle_left.first, packet.slide_idle_left.second);
	animation_loader(run_station_side_left, packet.slide_move_left.first, packet.slide_move_left.second);

	animation_loader(idle_station_side_right, packet.slide_idle_right.first, packet.slide_idle_right.second);
	animation_loader(run_station_slide_right, packet.slide_move_right.first, packet.slide_move_right.second);

	animation_loader(idle_station_back, packet.back_idle.first, packet.back_idle.second);
	animation_loader(run_station_back, packet.back_move.first, packet.back_move.second);

	animation_loader(weapon_equip_slide_anim, packet.weapon_equip_slide.first, packet.weapon_equip_slide.second);

#ifndef TEST
	animation_loader(test_animation, packet.test_sprite.first, packet.test_sprite.second);
#endif
}

void character::attack()
{
	switch (current_direction)
	{
	case key_direction::Right:
		animation_attack_running = true;
		att_type = attack_type::weapon_equip_slide;
		break;
	case key_direction::Left:
		std::cout << "Not realization animated" << std::endl;
		break;
	case key_direction::Up:
		std::cout << "Not realization animated" << std::endl;
		break;
	case key_direction::Down:
		std::cout << "Not realization animated" << std::endl;
		break;
	}
}

void character::render_animation()
{
#ifndef TEST
	if (test_animation.clock.getElapsedTime().asSeconds() > test_animation.frameDuration)
	{
		test_animation.currentFrame = (test_animation.currentFrame + 1) % test_animation.frameCount;

		test_animation.characterSprite.setTextureRect(sf::IntRect(test_animation.currentFrame * test_animation.frameWidth, 0,
			test_animation.frameWidth, test_animation.frameHeight));

		std::cout << "Frame: " << test_animation.currentFrame << std::endl;

		test_animation.clock.restart();
	}
	return;
#endif

	if (current_direction == key_direction::Right && animation_attack_running && att_type == attack_type::weapon_equip_slide)
	{
		if (weapon_equip_slide_anim.clock.getElapsedTime().asSeconds() > weapon_equip_slide_anim.frameDuration)
		{
			weapon_equip_slide_anim.currentFrame = (weapon_equip_slide_anim.currentFrame + 1) % weapon_equip_slide_anim.frameCount;

			weapon_equip_slide_anim.characterSprite.setTextureRect(sf::IntRect(weapon_equip_slide_anim.currentFrame * weapon_equip_slide_anim.frameWidth, 0,
				weapon_equip_slide_anim.frameWidth, weapon_equip_slide_anim.frameHeight));

			std::cout << weapon_equip_slide_anim.currentFrame << "/" << weapon_equip_slide_anim.frameCount << std::endl;

			if (weapon_equip_slide_anim.currentFrame == weapon_equip_slide_anim.frameCount - 1) {
				std::cout << "Attack animation ended" << std::endl;
				animation_attack_running = false;
				return;
			}

			weapon_equip_slide_anim.clock.restart();
		}

		return;
	}


	if (a_station == anim_station::idle && current_direction == key_direction::Up)
	{
		if (idle_station_back.clock.getElapsedTime().asSeconds() > idle_station_top.frameDuration)
		{
			idle_station_back.currentFrame = (idle_station_back.currentFrame + 1) % idle_station_back.frameCount;

			idle_station_back.characterSprite.setTextureRect(sf::IntRect(idle_station_back.currentFrame * idle_station_back.frameWidth, 0,
				idle_station_back.frameWidth, idle_station_back.frameHeight));

			idle_station_back.clock.restart();
		}
	}


	if (a_station == anim_station::run && current_direction == key_direction::Up)
	{
		if (run_station_back.clock.getElapsedTime().asSeconds() > run_station_back.frameDuration)
		{
			run_station_back.currentFrame = (run_station_back.currentFrame + 1) % run_station_back.frameCount;

			run_station_back.characterSprite.setTextureRect(sf::IntRect(run_station_back.currentFrame * run_station_back.frameWidth, 0,
				run_station_back.frameWidth, run_station_back.frameHeight));

			run_station_back.clock.restart();
		}
	}


	/////////////////////////////////


	if (a_station == anim_station::idle && current_direction == key_direction::Down)
	{
		if (idle_station_top.clock.getElapsedTime().asSeconds() > idle_station_top.frameDuration)
		{
			idle_station_top.currentFrame = (idle_station_top.currentFrame + 1) % idle_station_top.frameCount;

			idle_station_top.characterSprite.setTextureRect(sf::IntRect(idle_station_top.currentFrame * idle_station_top.frameWidth, 0,
				idle_station_top.frameWidth, idle_station_top.frameHeight));

			idle_station_top.clock.restart();
		}
	}


	if (a_station == anim_station::run && current_direction == key_direction::Down)
	{
		if (run_station_top.clock.getElapsedTime().asSeconds() > run_station_top.frameDuration)
		{
			run_station_top.currentFrame = (run_station_top.currentFrame + 1) % run_station_top.frameCount;

			run_station_top.characterSprite.setTextureRect(sf::IntRect(run_station_top.currentFrame * run_station_top.frameWidth, 0,
				run_station_top.frameWidth, run_station_top.frameHeight));

			run_station_top.clock.restart();
		}
	}



	///////////////////////////////////////////


	if (a_station == anim_station::idle && current_direction == key_direction::Left)
	{
		if (idle_station_side_left.clock.getElapsedTime().asSeconds() > idle_station_side_left.frameDuration)
		{
			idle_station_side_left.currentFrame = (idle_station_side_left.currentFrame + 1) % idle_station_side_left.frameCount;

			idle_station_side_left.characterSprite.setTextureRect(sf::IntRect(idle_station_side_left.currentFrame * idle_station_side_left.frameWidth, 0,
				idle_station_side_left.frameWidth, idle_station_side_left.frameHeight));

			idle_station_side_left.clock.restart();
		}
	}


	if (a_station == anim_station::run && current_direction == key_direction::Left)
	{
		if (run_station_side_left.clock.getElapsedTime().asSeconds() > run_station_side_left.frameDuration)
		{
			run_station_side_left.currentFrame = (run_station_side_left.currentFrame + 1) % run_station_side_left.frameCount;

			run_station_side_left.characterSprite.setTextureRect(sf::IntRect(run_station_side_left.currentFrame * run_station_side_left.frameWidth, 0,
				run_station_side_left.frameWidth, run_station_side_left.frameHeight));

			run_station_side_left.clock.restart();
		}
	}

	//////////////////////////////////////////////

	if (a_station == anim_station::idle && current_direction == key_direction::Right)
	{
		if (idle_station_side_right.clock.getElapsedTime().asSeconds() > idle_station_side_right.frameDuration)
		{
			idle_station_side_right.currentFrame = (idle_station_side_right.currentFrame + 1) % idle_station_side_right.frameCount;

			idle_station_side_right.characterSprite.setTextureRect(sf::IntRect(idle_station_side_right.currentFrame * idle_station_side_right.frameWidth, 0,
				idle_station_side_right.frameWidth, idle_station_side_right.frameHeight));

			idle_station_side_right.clock.restart();
	}
	}


	if (a_station == anim_station::run && current_direction == key_direction::Right)
	{
		if (run_station_slide_right.clock.getElapsedTime().asSeconds() > run_station_slide_right.frameDuration)
		{
			run_station_slide_right.currentFrame = (run_station_slide_right.currentFrame + 1) % run_station_slide_right.frameCount;

			run_station_slide_right.characterSprite.setTextureRect(sf::IntRect(run_station_slide_right.currentFrame * run_station_slide_right.frameWidth, 0,
				run_station_slide_right.frameWidth, run_station_slide_right.frameHeight));

			run_station_slide_right.clock.restart();

			// std::cout << "Run Move | Change animation" << std::endl;
		}
	}
}

sf::Sprite& character::get_sprite()
{
#ifndef TEST
	return test_animation.characterSprite;
#endif

	// attack

	
	if ( current_direction == key_direction::Right && att_type == attack_type::weapon_equip_slide && animation_attack_running) {
		return weapon_equip_slide_anim.characterSprite;
	}

	/// move 

	if (a_station == anim_station::idle && current_direction == key_direction::Up) {
		return idle_station_back.characterSprite;
	}
	if (a_station == anim_station::run && current_direction == key_direction::Up) {
		return run_station_back.characterSprite;
	}

	///////////////////

	if (a_station == anim_station::idle && current_direction == key_direction::Right) {
		return idle_station_side_right.characterSprite;
	}
	if (a_station == anim_station::run && current_direction == key_direction::Right) {
		// std::cout << "Return Run Right animation" << std::endl;
		return run_station_slide_right.characterSprite;
	}

	///////////////////


	if (a_station == anim_station::idle && current_direction == key_direction::Left) {
		return idle_station_side_left.characterSprite;
	}
	if (a_station == anim_station::run && current_direction == key_direction::Left) {
		return run_station_side_left.characterSprite;
	}


	//////////////////////

	if (a_station == anim_station::idle && current_direction == key_direction::Down) {
		return idle_station_top.characterSprite;
	}
	if (a_station == anim_station::run && current_direction == key_direction::Down) {
		return run_station_top.characterSprite;
	}

	return idle_station_top.characterSprite;
}

void character::move(key_direction dx)
{
	if (animation_attack_running) {
		return;
	}

	switch (dx)
	{
	case key_direction::Up:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		current_direction = key_direction::Up;
		update_animation_position(key_direction::Up);
		break;
	case key_direction::Down:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}

		current_direction = key_direction::Down;
		update_animation_position(key_direction::Down);
		break;
	case key_direction::Right:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		current_direction = key_direction::Right;
		update_animation_position(key_direction::Right);
		break;
	case key_direction::Left:
		if (a_station != anim_station::run)
		{
			a_station = anim_station::run;
		}
		current_direction = key_direction::Left;
		update_animation_position(key_direction::Left);
		break;
	}
}

void character::animation_loader(character_animation_station& station, const std::string& path, const std::uint16_t frames)
{
	station.characterTexture.loadFromFile(path);

	station.frameWidth = station.characterTexture.getSize().x / frames;
	station.frameHeight = station.characterTexture.getSize().y;
	station.frameCount = frames;
	station.frameSpacing = 20;

	station.characterSprite = sf::Sprite(station.characterTexture);
	station.characterSprite.setTextureRect(sf::IntRect(0, 0, station.frameWidth,
		station.frameHeight));
	station.characterSprite.setScale(3.0f, 3.0f);
	station.characterSprite.setPosition(0, 0);

	if (path == "sprite.png") {
		station.characterSprite.setPosition(30, 30);
	}

	std::cout << "Load sprite: " << path << " | [SIZE: " << station.frameHeight << "x" << station.frameWidth << "]"
		<< std::endl;
}

void character::update_animation_position(key_direction dx)
{
	switch (dx)
	{
	case key_direction::Up:
		idle_station_side_left.characterSprite.move(0, -movement_speed);
		run_station_side_left.characterSprite.move(0, -movement_speed);

		idle_station_side_right.characterSprite.move(0, -movement_speed);
		run_station_slide_right.characterSprite.move(0, -movement_speed);

		idle_station_back.characterSprite.move(0, -movement_speed);
		run_station_back.characterSprite.move(0, -movement_speed);

		idle_station_top.characterSprite.move(0, -movement_speed);
		run_station_top.characterSprite.move(0, -movement_speed);

		weapon_equip_slide_anim.characterSprite.move(0, -movement_speed);
		break;
	case key_direction::Down:
		idle_station_side_left.characterSprite.move(0, movement_speed);
		run_station_side_left.characterSprite.move(0, movement_speed);

		idle_station_side_right.characterSprite.move(0, movement_speed);
		run_station_slide_right.characterSprite.move(0, movement_speed);

		idle_station_back.characterSprite.move(0, movement_speed);
		run_station_back.characterSprite.move(0, movement_speed);

		idle_station_top.characterSprite.move(0, movement_speed);
		run_station_top.characterSprite.move(0, movement_speed);

		weapon_equip_slide_anim.characterSprite.move(0, movement_speed);
		break;
	case key_direction::Right:
		idle_station_side_left.characterSprite.move(movement_speed, 0);
		run_station_side_left.characterSprite.move(movement_speed, 0);

		idle_station_side_right.characterSprite.move(movement_speed, 0);
		run_station_slide_right.characterSprite.move(movement_speed, 0);

		idle_station_back.characterSprite.move(movement_speed, 0);
		run_station_back.characterSprite.move(movement_speed, 0);

		idle_station_top.characterSprite.move(movement_speed, 0);
		run_station_top.characterSprite.move(movement_speed, 0);

		weapon_equip_slide_anim.characterSprite.move(movement_speed, 0);
		break;
	case key_direction::Left:
		idle_station_side_left.characterSprite.move(-movement_speed, 0);
		run_station_side_left.characterSprite.move(-movement_speed, 0);

		idle_station_side_right.characterSprite.move(-movement_speed, 0);
		run_station_slide_right.characterSprite.move(-movement_speed, 0);

		idle_station_back.characterSprite.move(-movement_speed, 0);
		run_station_back.characterSprite.move(-movement_speed, 0);

		idle_station_top.characterSprite.move(-movement_speed, 0);
		run_station_top.characterSprite.move(-movement_speed, 0);

		weapon_equip_slide_anim.characterSprite.move(-movement_speed, 0);
		break;
	}

	std::cout << "Temp pos character: X - " << run_station_top.characterSprite.getPosition().x 
		<< "| Y - " <<
		run_station_top.characterSprite.getPosition().y << std::endl;
}