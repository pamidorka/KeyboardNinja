#include <SFML/Graphics.hpp>
#include <lib/Keyboard.h>

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1200, 600), "Keyboard Ninja", Style::Close);
    VirtualKeyboard* keyboard = new VirtualKeyboard("Roboto-Regular.ttf");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
			if (event.type == sf::Event::KeyPressed) {
				keyboard->ChangePressedKey(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased) {
				keyboard->ChangeReleasedKey(event.key.code);
			}
		}
		window->clear(sf::Color::White);
		board->Draw(window);
		window->display();
    }

    return 0;
}