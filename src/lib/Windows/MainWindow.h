#pragma once
#include <SFML/Graphics.hpp>
#include "lib/Keyboard.h"
#include "lib/Textbox.h"
#include "lib/Windows/SettingsWindow.h"
#include "lib/Statistic.h"


class MainWindow {
private:

	sf::RenderWindow* window_;
	Settings* settings_;
	VirtualKeyboard* keyboard_;
	TextboxView* textbox_;
	Button* settings_btn_;
	Statistic* statistic_;

	bool test_ongoing_ = true;
	Vector2f mouse_pos_;

	static const ButtonColorSet kColorsSettingsBtn;

	void Render();
	void Reset();

public:

	MainWindow();
	~MainWindow();

	void Show();
};