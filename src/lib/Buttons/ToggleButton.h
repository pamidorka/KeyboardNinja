#pragma once
#include "Button.h"

class ToggleButton : public Button {
private:
	bool is_enabled_;
	string text_enabled_;
	string text_disabled_;
	ButtonColorSet color_enabled_;
	ButtonColorSet color_disabled_;

	void UpdateTextAndColors();

public:
	ToggleButton(float _x, float _y, float _width, float _height, const Font* _font, string _text_enabled, string _text_disabled, unsigned int _text_size, const ButtonColorSet& _color_enabled, const ButtonColorSet& _color_disabled, bool _is_enabled = false);
	~ToggleButton();

	void Toggle(bool _is_enabled);
	bool IsEnabled();

	bool Update(const Vector2f _mouse_pos);
};