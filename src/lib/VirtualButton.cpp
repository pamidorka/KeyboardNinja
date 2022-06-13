#include "VirtualButton.h"

VirtualButton::VirtualButton(const double _width, const double _height, const double _x, const double _y, const int _character) {
	SetSize(_width, _height);
	SetKeyCode(_character);
	SetPosition(_x, _y);
}

void VirtualButton::SetSize(const double _width, const double _height) {
	this->size_.x = _width;
	this->size_.y = _height;
}

void VirtualButton::SetKeyCode(const int _character) {
	this->keycode_ = _character;
}

void VirtualButton::SetPosition(const double _width, const double _height) {
	this->position_.x = _width;
	this->position_.y = _height;
}

void VirtualButton::SetCharacter(const char _symbol) {
	this->character_ = _symbol;
}

void VirtualButton::SetColor(const sf::Color _color) {
	this->color_ = _color;
}

void VirtualButton::SetCharacterColor(const sf::Color _color) {
	this->character_color_ = _color;
}

int VirtualButton::GetKeyCode() {
	return this->keycode_;
}

char VirtualButton::GetCharacter() {
	return this->character_;
}

VirtualButton::Options VirtualButton::GetSize() {
	return this->size_;
}

VirtualButton::Options VirtualButton::GetPosition() {
	return this->position_;
}

sf::Color VirtualButton::GetColor() {
	return this->color_;
}

sf::Color VirtualButton::GetCharacterColor() {
	return this->character_color_;
}