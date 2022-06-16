#include "Button.h"

void Button::RefreshButtonColor() {
	switch (button_state_) {
	case ButtonStates::ButtonIdle:
	case ButtonStates::ButtonUnhoverActive:
		shape_.setFillColor(colors_.idle_color_);
		break;
	case ButtonStates::ButtonHover:
	case ButtonStates::ButtonHoverInactive:
		shape_.setFillColor(colors_.hover_color_);
		break;
	case ButtonStates::ButtonHoverActive:
		shape_.setFillColor(colors_.active_color_);
		break;
	}
}

void Button::RefreshTextLocation() {
	text_.setPosition(
		shape_.getPosition().x + (shape_.getSize().x / 2.f) - (text_.getGlobalBounds().width / 2.f),
		shape_.getPosition().y + (shape_.getSize().y / 2.f) - (text_.getGlobalBounds().height / 1.4f)
	);
}

Button::Button(float _x, float _y, float _width, float _height, const sf::Font* _font, const std::string &_text, unsigned int _text_size, const ButtonColorSet& _colors)
	: colors_(_colors) {
	button_state_ = ButtonStates::ButtonIdle;

	shape_.setPosition(sf::Vector2f(_x, _y));
	shape_.setSize(sf::Vector2f(_width, _height));

	font_ = _font;
	text_.setFont(*font_);
	text_.setFillColor(sf::Color::White);
	text_.setCharacterSize(_text_size);
	SetText(_text);

	shape_.setFillColor(colors_.idle_color_);
}

Button::~Button() {

}

bool Button::IsMouseHover(sf::Vector2f _mouse_pos) const {
	return shape_.getGlobalBounds().contains(_mouse_pos);
}

void Button::SetColorSet(const ButtonColorSet& _color_set) {
	colors_ = ButtonColorSet(_color_set);
}

void Button::SetText(const std::string& _s) {
	text_.setString(_s);
}

ButtonStates Button::GetButtonState() const {
	return button_state_;
}

const sf::String& Button::GetTextString() const {
	return text_.getString();
}

const sf::Font& Button::GetTextFont() const {
	return *font_;
}

const sf::RectangleShape& Button::GetBounds() const {
	return shape_;
}

const ButtonColorSet& Button::GetButtonColorSet() const {
	return colors_;
}

bool Button::Update(sf::Vector2f _mouse_pos, bool _mouse_pressed) {
	bool result = false;

	switch (button_state_) {
	case ButtonStates::ButtonIdle:
		if (IsMouseHover(_mouse_pos)) {
			button_state_ = _mouse_pressed ? ButtonStates::ButtonHoverInactive : ButtonStates::ButtonHover;
		}
		break;
	case ButtonStates::ButtonHover:
		if (IsMouseHover(_mouse_pos)) {
			button_state_ = _mouse_pressed ? ButtonStates::ButtonHoverActive : ButtonStates::ButtonHover;
		}
		else {
			button_state_ = ButtonStates::ButtonIdle;
		}
		break;
	case ButtonStates::ButtonHoverInactive:
		if (IsMouseHover(_mouse_pos)) {
			button_state_ = _mouse_pressed ? ButtonStates::ButtonHoverInactive : ButtonStates::ButtonHover;
		}
		else {
			button_state_ = ButtonStates::ButtonIdle;
		}
		break;
	case ButtonStates::ButtonHoverActive:
	case ButtonStates::ButtonUnhoverActive:
		if (IsMouseHover(_mouse_pos)) {
			if (_mouse_pressed) {
				button_state_ = ButtonStates::ButtonHoverActive;
			}
			else {
				button_state_ = ButtonStates::ButtonHover;
				result = true;
			}
		}
		else {
			button_state_ = _mouse_pressed ? ButtonStates::ButtonUnhoverActive : ButtonStates::ButtonIdle;
		}
		break;
	}

	RefreshButtonColor();
	return result;
}

void Button::Render(sf::RenderTarget* _target) {
	_target->draw(shape_);

	RefreshTextLocation();
	_target->draw(text_);
}