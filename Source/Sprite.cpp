#include "Headers/Sprite.hpp"

Sprite::Sprite()
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(180.f);
}

Sprite::Sprite(sf::Vector2f position)
    : position_(position)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(180.f);
}

void Sprite::draw(sf::RenderWindow& i_window)
{   
    rectangle_.setPosition(position_);
    i_window.draw(rectangle_);
}

/*____________________GETTERS___________________________*/

sf::Vector2f Sprite::getPosition() const
{
    return this->position_;
}

sf::Vector2f Sprite::getSize() const
{
    return this->size_;
}

/*__________________SETTERS___________________________*/

void Sprite::setPosition(sf::Vector2f const newPos)
{
    position_ = newPos;
}

