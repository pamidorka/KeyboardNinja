#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Settings.h"
#include <iostream>
#include <exception>
#include <string>

class VirtualKeyboard {
private:

	struct Position {
		double x;
		double y;
	};

	Button* buttons_;
	Settings* settings_;
	Position position_;
	const int kNumberOfButtons_ = 27;
	const size_t kSizeOfCharacter_ = 30;
	const size_t kSizeOfOutline_ = 1;

public:

	VirtualKeyboard(Settings* _settings);
	void SetPosition(const double _x, const double _y);
	void ChangePressedKey(const int _key);
	void ChangeReleasedKey(const int _key);
	Button* GetButtons();
	Position GetPosition();
	void Draw(sf::RenderWindow* _window);

};