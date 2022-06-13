#pragma once
#include <SFML/Graphics.hpp>
#include "lib/Keyboard.h"
#include "lib/Textbox.h"
#include "lib/Windows/SettingsWindow.h"

class MainWindow {
private:

	sf::RenderWindow* window_;
	Settings* settings_;
	VirtualKeyboard* keyboard_;
	TextboxView* textbox_;
	Button* settings_btn_;

	Vector2f mouse_pos_;

	static const ButtonColorSet kColorsSettingsBtn;

	void Render();

public:

	MainWindow();
	~MainWindow();

	void Show();
};