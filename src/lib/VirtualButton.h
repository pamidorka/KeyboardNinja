#pragma once
#include <SFML/Graphics.hpp>

class VirtualButton {
private:
    struct Options {
        double x;
        double y;
    };

    std::string character_;
    sf::Color color_;
    sf::Color character_color_;
    Options size_;
    Options position_;

public:
    VirtualButton(
            double _width = 60,
            double _height = 60,
            double _x = 0,
            double _y = 0);

    void SetSize(double _width, double _height);
    void SetPosition(double _width, double _height);
    void SetCharacter(std::string _symbol);
    void SetColor(sf::Color _color);
    void SetCharacterColor(sf::Color _color);

    std::string GetCharacter();
    Options GetSize();
    Options GetPosition();
    sf::Color GetColor();
    sf::Color GetCharacterColor();
};
