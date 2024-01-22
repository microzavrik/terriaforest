#pragma once

#include "include.hpp"

class window
{
public:
	window(std::uint32_t width, std::uint32_t height, const std::string& title) : m_window(sf::VideoMode(width, height), title) { }
	void draw_texture(const sf::Texture& texture);
	void draw_sprite(const sf::Sprite& sprite);
	void set_icon(const std::string& path, std::int16_t width, std::int16_t height);
	void set_title(const std::string& path);
	void window_clear(sf::Color);
	void set_frame_limit(float limit);
	void process_events();
	void display()  { m_window.display(); }
	bool is_open()  { return m_window.isOpen(); }
	void close()    { m_window.close(); }
private:
	sf::RenderWindow m_window;
	sf::Image icon;
};