#pragma once
#include <SFML/Graphics.hpp>
#include "lib/Keyboard.h"
#include "lib/Textbox.h"
#include "lib/Windows/SettingsWindow.h"
#include "lib/Statistic.h"

class MainWindow {
private:

	enum TestState {
		WAITING,
		TESTING,
		RESULT
	};

	sf::RenderWindow* window_;
	Settings* settings_;
	VirtualKeyboard* keyboard_;
	TextboxView* textbox_;
	Button* settings_btn_;
	Statistic* statistic_;

	TestState state_;
	Vector2f mouse_pos_;

	static const ButtonColorSet kColorsSettingsBtn;

	void Render();
	void RenderResult();
	void Reset();

public:

	MainWindow();
	~MainWindow();

	void Show();
};