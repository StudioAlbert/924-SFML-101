#include <iostream>
#include <SFML/Graphics.hpp>

#include "hero.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::Clock clock;
    float dt = 0.016f;

    Hero Link;
    

    while (window.isOpen())
    {

        std::cout << "Delta Time (in sec) : " << dt << std::endl;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Link.MoveHero(sf::Vector2f(0, -1), dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Link.MoveHero(sf::Vector2f(0, 1), dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Link.MoveHero(sf::Vector2f(-1, 0), dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Link.MoveHero(sf::Vector2f(1, 0), dt);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            Link.Run(true);
            Link.EquipSword(false);
        }else
        {
            Link.Run(false);
        }

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    	{
            // -------------------------------------------------
            Link.EquipSword(true);
    	}else
    	{
            Link.EquipSword(false);
    	}

        


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed)
            {
	            if(event.key.code == sf::Keyboard::LControl || event.key.code == sf::Keyboard::RControl)
	            {
                    Link.SwitchSword();
	            }
            }

        }

        window.clear();
        window.draw(Link);
    	window.display();

        // At the end of the game loop
        dt = clock.restart().asSeconds();

    }

    return 0;
}
