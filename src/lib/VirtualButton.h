#pragma once
#include <SFML/Graphics.hpp>

class VirtualButton {
private:

	struct Options {
		double x;
		double y;
	};

	int keycode_;
	std::string character_;
	sf::Color color_;
	sf::Color character_color_;
	Options size_;
	Options position_;

public:

	VirtualButton(const double _width = 60, const double _height = 60, const double _x = 0, const double _y = 0, const int _character = 0);
	void SetSize(const double _width, const double _height);
	void SetKeyCode(const int _character);
	void SetPosition(const double _width, const double _height);
	void SetCharacter(std::string _symbol);
	void SetColor(const sf::Color _color);
	void SetCharacterColor(const sf::Color _color);
	int GetKeyCode();
	std::string GetCharacter();
	Options GetSize();
	Options GetPosition();
	sf::Color GetColor();
	sf::Color GetCharacterColor();

};
