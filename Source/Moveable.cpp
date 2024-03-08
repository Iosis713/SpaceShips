#include "Headers/Moveable.hpp"

Moveable::Moveable()
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
}

Moveable::Moveable(sf::Vector2f position)
    : Sprite(position)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
}

void Moveable::changeDirection()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rectangle_.setRotation(rectangle_.getRotation() - rotationSpeed_);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rectangle_.setRotation(rectangle_.getRotation() + rotationSpeed_);
    }
}

/*______________________GETTERS__________________________________*/

float Moveable::getSpeed() const
{
    return this->speed_;
}

float Moveable::getRotation() const
{
    return this->rectangle_.getRotation();
}

/*____________________SETTERS_________________________________*/

void Moveable::setSpeed(float newSpeed)
{
    speed_ = newSpeed;
}

