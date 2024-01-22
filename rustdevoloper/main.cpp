#include "character.hpp"
#include "window.hpp"
#include "map.hpp"

#define DEFAULT_ANIMATION_FRAMES 6
#define DELTA_TIME = 1.0f / 60.0f;

void main()
{
	window main_window(800, 600, "Terria Forest");
	main_window.set_icon("666.png", 32, 32);
	map world("config.txt", "first_layer.txt");

	for (size_t i = 0; i < world.map_data_cells.size(); i++)
	{
		std::cout << world.map_data_cells[i].texture_pointer << std::endl;
	}

	std::cout << world.map_data_cells.size() << std::endl;
	std::cout << world.first_layer.size() << std::endl;

	animation_path path;
	path.top_idle = std::make_pair("./Assets/Characters/RedCharacter/FrontIdle.png", DEFAULT_ANIMATION_FRAMES);
	path.top_move = std::make_pair("./Assets/Characters/RedCharacter/FrontMovement.png", DEFAULT_ANIMATION_FRAMES);

	path.slide_idle_right = std::make_pair("./Assets/Characters/RedCharacter/SlideIdleRight.png", DEFAULT_ANIMATION_FRAMES);
	path.slide_move_right = std::make_pair("./Assets/Characters/RedCharacter/SlideMovementRight.png", DEFAULT_ANIMATION_FRAMES);

	path.slide_idle_left = std::make_pair("./Assets/Characters/RedCharacter/SlideIdleLeft.png", DEFAULT_ANIMATION_FRAMES);
	path.slide_move_left = std::make_pair("./Assets/Characters/RedCharacter/SlideMovementLeft.png", DEFAULT_ANIMATION_FRAMES);

	path.back_idle = std::make_pair("./Assets/Characters/RedCharacter/BackIdle.png", DEFAULT_ANIMATION_FRAMES);
	path.back_move = std::make_pair("./Assets/Characters/RedCharacter/BackMovement.png", DEFAULT_ANIMATION_FRAMES);

#ifndef TEST

	int n;
	
	std::cout << "> ";
	std::cin >> n;

	path.test_sprite = std::make_pair("sprite.png", n);
#endif

	character hero(path, 4.0f);

	sf::Clock clock;
	float want_fps = 50;

	while (main_window.is_open())
	{

		main_window.process_events();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			hero.move(key_direction::Left);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			hero.move(key_direction::Right);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			hero.move(key_direction::Up);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			hero.move(key_direction::Down);
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			hero.a_station = anim_station::idle;
		}

		hero.render_animation();
		main_window.window_clear(sf::Color::Black);

		for (size_t i = 0; i < world.first_layer.size(); i++)
		{
			for (size_t j = 0; j < world.first_layer[i].size(); j++)
			{
				auto[result, index] = world.contains_pointer(world.first_layer[i][j]);

				if (result)
				{
					main_window.draw_texture(world.map_data_cells[index].texture);
				}
			}
		}

		main_window.draw_sprite(hero.get_sprite());

		main_window.display();

		float current_fps = 1.0f / clock.getElapsedTime().asSeconds();
		main_window.set_title("Terria Forest | Current FPS: " + std::to_string(static_cast<int>(current_fps)));

		sf::Int32 frame_duration = clock.getElapsedTime().asMilliseconds();
		sf::Int32 time_to_sleep = int(1000.f / want_fps) - frame_duration;
		if (time_to_sleep > 0) {
			sf::sleep(sf::milliseconds(time_to_sleep));
		}
		clock.restart();
	}
}