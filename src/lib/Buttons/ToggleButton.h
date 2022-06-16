#pragma once
#include "Button.h"

class ToggleButton : public Button {
private:
	bool is_enabled_;
	std::string text_enabled_;
	std::string text_disabled_;
	ButtonColorSet color_enabled_;
	ButtonColorSet color_disabled_;

	void UpdateTextAndColors();
public:
	ToggleButton(float _x, float _y, float _width, float _height, const sf::Font* _font, const std::string& _text_enabled, const std::string& _text_disabled, unsigned int _text_size, const ButtonColorSet& _color_enabled, const ButtonColorSet& _color_disabled, bool _is_enabled = false);
	~ToggleButton();

	void Toggle(bool _is_enabled);

	bool IsEnabled() const;
	const std::string& GetTextEnabledString() const;
	const std::string& GetTextDisabledString() const;
	const ButtonColorSet& GetButtonColorEnabledSet() const;
	const ButtonColorSet& GetButtonColorDisabledSet() const;

	bool Update(const sf::Vector2f _mouse_pos, bool _mouse_pressed);
};