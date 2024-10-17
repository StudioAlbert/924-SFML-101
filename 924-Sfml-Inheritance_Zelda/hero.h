#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Hero : public sf::Drawable, public sf::Transformable
{

private:
	// Hero ----
	sf::Sprite sprite_;
	sf::Texture texture_;
	// Sword ---
	sf::Sprite sword_sprite_;
	sf::Texture sword_texture_;

	bool sword_equiped_ = false;
	bool is_running_ = false;

	const float speed_walking_ = 100.0f;
	const float speed_running_ = 150.0f;

public:

	Hero();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void EquipSword(bool equip);
	void SwitchSword();
	void Run(bool is_running);

	void MoveHero(sf::Vector2f direction, float dt);

};



#endif // HERO_H
