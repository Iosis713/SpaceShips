#include "Headers/Controllable.hpp"

Controllable::Controllable(sf::Vector2f position, float rotation, sf::Vector2f size,  float maxSpeed, float speed, float acceleration, float rotationSpeed)
    : Moveable(position, rotation, size, maxSpeed, speed)
    , acceleration_(acceleration)
    , rotationSpeed_(rotationSpeed)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Magenta);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(rotation);
}

Controllable::Controllable(sf::Vector2f position, float rotation, float maxSpeed, float speed, float acceleration, float rotationSpeed)
    : Moveable(position, rotation,  maxSpeed, speed)
    , acceleration_(acceleration)
    , rotationSpeed_(rotationSpeed)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Magenta);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(rotation);
}

Controllable::Controllable()
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Magenta);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(0.f);
}

Controllable::Controllable(sf::Vector2f position)
    : Moveable(position)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Magenta);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(0.f);
}

void Controllable::accelerate()
{
    //speed up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and
       speed_ < maxSpeed_)
    {
        if(speed_ >= maxSpeed_ - acceleration_)
        {
            speed_ = maxSpeed_;
        }
        else
        {
            speed_ += acceleration_;
        }
    }
    //slow down
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and
       speed_ > 0.f)
    {
        if(speed_ < acceleration_)
        {
            speed_ = 0.f;
        }
        else
        {
            speed_ -= acceleration_;
        }
    }
}

void Controllable::changeDirection()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        turnLeft();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        turnRight();
    }
}

void Controllable::turnLeft()
{
    rectangle_.setRotation(rectangle_.getRotation() - rotationSpeed_);
}

void Controllable::turnRight()
{
    rectangle_.setRotation(rectangle_.getRotation() + rotationSpeed_);
}

/*________________________GETTERS________________________________*/

float Controllable::getAcceleration() const
{
    return this->acceleration_;
}

float Controllable::getRotationSpeed() const
{
    return this->rotationSpeed_;
}

/*____________________SETTERS_________________________________*/

void Controllable::setAcceleration(float acceleration)
{
    acceleration_ = acceleration;
}

void Controllable::setRotationSpeed(float rotationSpeed)
{
    rotationSpeed_ = rotationSpeed;
}


