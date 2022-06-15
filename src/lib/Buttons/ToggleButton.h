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
	ToggleButton(float _x, float _y, float _width, float _height, const Font* _font, const string& _text_enabled, const string& _text_disabled, unsigned int _text_size, const ButtonColorSet& _color_enabled, const ButtonColorSet& _color_disabled, bool _is_enabled = false);
	~ToggleButton();

	void Toggle(bool _is_enabled);

	bool IsEnabled() const;
	const string& GetTextEnabledString() const;
	const string& GetTextDisabledString() const;
	const ButtonColorSet& GetButtonColorEnabledSet() const;
	const ButtonColorSet& GetButtonColorDisabledSet() const;

	bool Update(const Vector2f _mouse_pos, bool _mouse_pressed);
};