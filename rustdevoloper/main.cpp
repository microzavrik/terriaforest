#include "character.hpp"
#include "window.hpp"
#include "map.hpp"

void main()
{
	window main_window(800, 600, "bebra");
	main_window.set_icon("666.png", 32, 32);
	map world("config.txt", "first_layer.txt");

	for (size_t i = 0; i < world.map_data_cells.size(); i++)
	{
		std::cout << world.map_data_cells[i].texture_pointer << std::endl;
	}

	std::cout << world.map_data_cells.size() << std::endl;
	std::cout << world.first_layer.size() << std::endl;


	character hero("./Assets/Characters/RedCharacter/FrontIdle.png", "./Assets/Characters/RedCharacter/FrontMovement.png",
		5.0f, 6, 54);

	while (main_window.is_open())
	{
		main_window.process_events();
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
	}
}