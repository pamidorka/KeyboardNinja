#include "VirtualButton.h"

VirtualButton::VirtualButton(double _width, double _height, double _x, double _y) {
	SetSize(_width, _height);
	SetPosition(_x, _y);
}

void VirtualButton::SetSize(double _width, double _height) {
	this->size_.x = _width;
	this->size_.y = _height;
}

void VirtualButton::SetPosition(double _width, double _height) {
	this->position_.x = _width;
	this->position_.y = _height;
}

void VirtualButton::SetCharacter(std::string _symbol) {
	this->character_ = _symbol;
}

void VirtualButton::SetColor(sf::Color _color) {
	this->color_ = _color;
}

void VirtualButton::SetCharacterColor(sf::Color _color) {
	this->character_color_ = _color;
}

std::string VirtualButton::GetCharacter() {
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