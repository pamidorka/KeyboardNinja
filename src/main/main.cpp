#include <SFML/Graphics.hpp>
#include <lib/Keyboard.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "SFML works!");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);

        window.display();
    }

    return 0;
}