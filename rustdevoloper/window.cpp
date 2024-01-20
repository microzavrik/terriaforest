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

void window::process_events()
{
	sf::Event event;
	while (m_window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
	}
}

void window::window_clear(sf::Color color)
{
	m_window.clear(color);
}