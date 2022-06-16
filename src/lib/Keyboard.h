#pragma once
#include <SFML/Graphics.hpp>
#include "VirtualButton.h"
#include "Settings.h"
#include <iostream>

class VirtualKeyboard {
private:

	struct Position {
		double x;
		double y;
	};

	int button_size_ = 60;
	VirtualButton* buttons_;
	Settings* settings_;
	Position position_;
	const int kNumberOfButtons_ = 28;
	const size_t kSizeOfCharacter_ = 30;
	const size_t kSizeOfOutline_ = 1;

public:

	VirtualKeyboard(Settings* _settings);
	~VirtualKeyboard();

	void SetPosition(double _x, double _y);
	void SetButtonSize(int _size);
	void ChangePressedKey(int _key);
	void ChangeReleasedKey(int _key);
	void Reset();
	Position GetPosition();
	void Draw(sf::RenderWindow* _window);

	VirtualButton* GetButtons();

};