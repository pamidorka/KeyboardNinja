#include<SFML/Graphics.hpp>

int main()
{
    sf::Window window;
    window.create(sf::VideoMode(1600, 1000), "Keyboard Ninja");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
