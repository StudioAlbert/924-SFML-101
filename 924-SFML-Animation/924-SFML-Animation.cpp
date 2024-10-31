// 924-SFML-Animation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::Texture texture_robot_full;
	texture_robot_full.loadFromFile("assets\\character_robot_sheetHD.png");

	//"attackKick" x = "192" y = "512" width = "192" height = "256" / >
	//<SubTexture name="rope" x="1536" y="768" width="192" height="256"/>


	sf::Sprite sprite_full;
	sprite_full.setTexture(texture_robot_full);
	sprite_full.setTextureRect(sf::IntRect(1536, 768, 192, 256));

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Animation exercice");


	// Animation from loading textures
	std::array<sf::Texture, 15> animation;
	animation[0].loadFromFile("assets\\flatboy\\png\\Walk (1).png");
	animation[1].loadFromFile("assets\\flatboy\\png\\Walk (2).png");
	animation[2].loadFromFile("assets\\flatboy\\png\\Walk (3).png");

	for (int idx_sprite = 0; idx_sprite < animation.size(); idx_sprite++)
	{
		animation[idx_sprite].loadFromFile("assets\\flatboy\\png\\Walk (" + std::to_string(idx_sprite + 1) + ").png");
	}

	sf::Sprite flatboy;
	flatboy.setTexture(animation[0]);

	// Animation from loading Rect
	std::array<sf::IntRect, 8> animation_rects;
	sf::Sprite animated_robot;
	animated_robot.setTexture(texture_robot_full);
	animated_robot.setScale(0.3f, 0.3f);

	for(int idx_rect = 0; idx_rect < 8; idx_rect++)
	{
		int x, y, width, height;
		y = 1024;
		width = 192;
		height = 256;
		x = idx_rect * 192;

		animation_rects[idx_rect] = sf::IntRect(x, y, width, height);

	}


	sf::Clock clock;
	float dt = 0;
	float interval = 1 / 60.f;
	int idx_animation = 0;

	float dt_robot = 0;
	float interval_robot = 1 / 20.f;
	int idx_robot = 0;

	do
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if(dt >= interval)
		{
			flatboy.setTexture(animation[idx_animation++]);
			if(idx_animation >= animation.size())
			{
				idx_animation = 0;
			}
			dt = 0;
		}

		if(dt_robot >= interval_robot)
		{
			animated_robot.setTextureRect(animation_rects[idx_robot++]);
			if (idx_robot >= animation_rects.size())
			{
				idx_robot = 0;
			}
			dt_robot = 0;
		}
		

		window.clear();
		//window.draw(sprite_full);
		//window.draw(flatboy);
		window.draw(animated_robot);
		window.display();

		auto time = clock.restart();
		dt += time.asSeconds();
		dt_robot += time.asSeconds();

	} while (window.isOpen());

	return EXIT_SUCCESS;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
