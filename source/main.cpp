#include <iostream>
#include <SFML/Graphics.hpp>

#include "core/resource_manager.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode(800, 600), "My window" };
    
    GameAi::Core::ResourceManager manager{ };
    sf::Texture tex = manager.GetTextureByName("sfml");
    sf::Sprite sprite{ tex };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Cyan);

        window.draw(sprite);

        window.display();
    }

    return 0;
}
