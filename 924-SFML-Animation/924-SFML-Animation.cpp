// 924-SFML-Animation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Texture texture_full;
    texture_full.loadFromFile("assets\\character_robot_sheetHD.png");

    //"attackKick" x = "192" y = "512" width = "192" height = "256" / >
    //<SubTexture name="rope" x="1536" y="768" width="192" height="256"/>


    sf::Sprite sprite_full;
    sprite_full.setTexture(texture_full);
    sprite_full.setTextureRect(sf::IntRect(1536, 768, 192, 256));

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Animation exercice");

    do
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

	    window.clear();
	    window.draw(sprite_full);
	    window.display();

    }
    while (window.isOpen());

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
