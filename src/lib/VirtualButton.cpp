#include "VirtualButton.h"

VirtualButton::VirtualButton(
        double _width, double _height, double _x, double _y)
{
    SetSize(_width, _height);
    SetPosition(_x, _y);
}

void VirtualButton::SetSize(double _width, double _height)
{
    size_.x = _width;
    size_.y = _height;
}

void VirtualButton::SetPosition(double _width, double _height)
{
    position_.x = _width;
    position_.y = _height;
}

void VirtualButton::SetCharacter(std::string _symbol)
{
    character_ = _symbol;
}

void VirtualButton::SetColor(sf::Color _color)
{
    color_ = _color;
}

void VirtualButton::SetCharacterColor(sf::Color _color)
{
    character_color_ = _color;
}

std::string VirtualButton::GetCharacter()
{
    return character_;
}

VirtualButton::Options VirtualButton::GetSize()
{
    return size_;
}

VirtualButton::Options VirtualButton::GetPosition()
{
    return position_;
}

sf::Color VirtualButton::GetColor()
{
    return color_;
}

sf::Color VirtualButton::GetCharacterColor()
{
    return character_color_;
}