#include "ToggleButton.h"

ToggleButton::ToggleButton(float _x, float _y, float _width, float _height, const Font* _font, const string &_text_enabled, const string &_text_disabled, unsigned int _text_size, const ButtonColorSet& _color_enabled, const ButtonColorSet& _color_disabled, bool _is_enabled)
	: Button(_x, _y, _width, _height, _font, _text_disabled, _text_size, _color_disabled), is_enabled_(_is_enabled), text_enabled_(_text_enabled), text_disabled_(_text_disabled), color_enabled_(_color_enabled), color_disabled_(_color_disabled) {

	UpdateTextAndColors();
}

ToggleButton::~ToggleButton() {

}

void ToggleButton::UpdateTextAndColors() {
	SetText(is_enabled_ ? text_enabled_ : text_disabled_);
	SetColorSet(is_enabled_ ? color_enabled_ : color_disabled_);
	RefreshButtonColor();
}

void ToggleButton::Toggle(bool _is_enabled) {
	is_enabled_ = _is_enabled;
	UpdateTextAndColors();
}

bool ToggleButton::IsEnabled() {
	return is_enabled_;
}

bool ToggleButton::Update(const Vector2f _mouse_pos) {
	if (Button::Update(_mouse_pos)) {
		Toggle(!is_enabled_);
		return true;
	}
	else return false;
}