// 924-SFML-101.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	sf::CircleShape circle(25);
	circle.setPosition(0, 0);
	circle.setFillColor(sf::Color::Red);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::Texture texture;
	//texture.loadFromFile("D:\\5_Repos\\C++\\924-SFML-101\\924-SFML-101\\assets\\sprites\\tile_0000.png");
	texture.loadFromFile("assets\\sprites\\tile_0000.png");

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y);

	while(window.isOpen())
	{
		//std::cout << "I'm game looping !!!!!!!!!!!!!!!" << '\n';

		// A : Redundant with B
		circle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		}

		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}

			// B: Redundant with A
			if(event.type == sf::Event::MouseMoved)
			{
				circle.setPosition(event.mouseMove.x, event.mouseMove.y);
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					//sprite.setPosition(event.mouseButton.x, event.mouseButton.y);
					// if je suis dans la case
				}
			}

		}

		window.clear();

		//window.draw(circle);
		for(int x = 0; x <= 5; x ++)
		{
			window.draw(sprite);
		}

		window.display();

	}

	std::cout << "I'm not game looping any more !!!!!!!!!!!!!!!" << '\n';

}


