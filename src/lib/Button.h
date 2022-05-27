#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:

	struct Options {
		double x;
		double y;
	};

	int keycode_;
	char character_;
	sf::Color color_;
	sf::Color character_color_;
	Options size_;
	Options position_;

public:

	Button(const double _width = 60, const double _height = 60, const double _x = 0, const double _y = 0, const int _character = 0);
	void SetSize(const double _width, const double _height);
	void SetKeyCode(const int _character);
	void SetPosistion(const double _width, const double _height);
	void SetCharacter(const char _symbol);
	void SetColor(const sf::Color _color);
	void SetCharacterColor(const sf::Color _color);
	int GetKeyCode();
	char GetCharacter();
	Options GetSize();
	Options GetPosition();
	sf::Color GetColor();
	sf::Color GetCharacterColor();

};