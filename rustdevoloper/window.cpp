#include "window.hpp"

void window::draw_texture(const sf::Texture& texture)
{
	sf::Sprite sprite(texture);
	m_window.draw(sprite);
}

void window::draw_sprite(const sf::Sprite& sprite)
{
	m_window.draw(sprite);
}

void window::set_icon(const std::string& path, std::int16_t width, std::int16_t height)
{
	if (!icon.loadFromFile(path)) {
		throw std::runtime_error("error path");
	}
	m_window.setIcon(width, height, icon.getPixelsPtr());
}

process_return_type window::process_events()
{
	sf::Event event;
	while (m_window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "Attack pressed" << std::endl;
				return process_return_type::pressed_right_mouse_button;
			}
		}
	}

	return process_return_type::none;
}

void window::window_clear(sf::Color color)
{
	m_window.clear(color);
}

void window::set_frame_limit(float limit)
{
	m_window.setFramerateLimit(limit);
}

void window::set_title(const std::string& path)
{
	m_window.setTitle(path);
}