#include "VirtualButton.h"

Button::Button(const double _width, const double _height, const double _x, const double _y, const int _character) {
	SetSize(_width, _height);
	SetKeyCode(_character);
	SetPosistion(_x, _y);
}

void Button::SetSize(const double _width, const double _height) {
	this->size_.x = _width;
	this->size_.y = _height;
}

void Button::SetKeyCode(const int _character) {
	this->keycode_ = _character;
}

void Button::SetPosistion(const double _width, const double _height) {
	this->position_.x = _width;
	this->position_.y = _height;
}

void Button::SetCharacter(const char _symbol) {
	this->character_ = _symbol;
}

void Button::SetColor(const sf::Color _color) {
	this->color_ = _color;
}

void Button::SetCharacterColor(const sf::Color _color) {
	this->character_color_ = _color;
}

int Button::GetKeyCode() {
	return this->keycode_;
}

char Button::GetCharacter() {
	return this->character_;
}

Button::Options Button::GetSize() {
	return this->size_;
}

Button::Options Button::GetPosition() {
	return this->position_;
}

sf::Color Button::GetColor() {
	return this->color_;
}

sf::Color Button::GetCharacterColor() {
	return this->character_color_;
}