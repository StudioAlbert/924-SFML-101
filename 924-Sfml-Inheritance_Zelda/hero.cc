#include "hero.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>


Hero::Hero()
{
	texture_.loadFromFile("assets\\hero.png");
	sprite_.setTexture(texture_);

	sword_texture_.loadFromFile("assets\\sword.png");
	sword_sprite_.setTexture(sword_texture_);
	sword_sprite_.setPosition(10, 0);

}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	states.transform *= getTransform();

	target.draw(sprite_, states);
	if(sword_equiped_)
	{
		target.draw(sword_sprite_, states);
	}
}

void Hero::EquipSword(bool equip)
{
	sword_equiped_ = equip;
	// Add gameplay rules --------------------------------------
}

void Hero::SwitchSword()
{
	if(sword_equiped_ == true)
	{
		sword_equiped_ = false;
	}else
	{
		sword_equiped_ = true;
	}
}

void Hero::Run(bool is_running)
{
	is_running_ = is_running;
}

void Hero::MoveHero(sf::Vector2f direction, float dt)
{
	float speed = is_running_ ? speed_running_ : speed_walking_;

	if(is_running_)
	{
		speed = speed_running_;
	}else
	{
		speed = speed_walking_;
	}

	setPosition(getPosition() + speed * direction * dt);
}
