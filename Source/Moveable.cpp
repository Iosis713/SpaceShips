#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float rotation, sf::Vector2f size, float maxSpeed, float speed)
    : Sprite(position, rotation, size)
    , maxSpeed_(maxSpeed)
    , speed_(speed)
{
    sprite_.setOrigin(size_.x/2, size_.y/2);
    sprite_.setPosition(position_);
    sprite_.setRotation(rotation);    
}

Moveable::Moveable(sf::Vector2f position, float rotation, float maxSpeed, float speed)
    : Sprite(position)
    , maxSpeed_(maxSpeed)
    , speed_(speed)
{
    sprite_.setOrigin(size_.x/2, size_.y/2);
    sprite_.setPosition(position_);
    sprite_.setRotation(rotation);   
}

Moveable::Moveable(sf::Vector2f position, float rotation)
    : Sprite(position)
{
    sprite_.setOrigin(size_.x/2, size_.y/2);
    sprite_.setPosition(position_);
    sprite_.setRotation(rotation);
}   

Moveable::Moveable()
{
    sprite_.setOrigin(size_.x/2, size_.y/2);
    sprite_.setPosition(position_);
}

Moveable::Moveable(sf::Vector2f position)
    : Sprite(position)
{
    sprite_.setOrigin(size_.x/2, size_.y/2);
    sprite_.setPosition(position_);
}

void Moveable::updatePosition()
{
    float angle = sprite_.getRotation() * M_PI / 180; // deg to radians
    using namespace std;
    {
    velocity_.x = round(-speed_ * sin(angle));
    velocity_.y = round(speed_ * cos(angle));
    }
    position_ += velocity_;    
}

/*______________________GETTERS__________________________________*/

float Moveable::getSpeed() const
{
    return this->speed_;
}

/*____________________SETTERS_________________________________*/

void Moveable::setSpeed(float newSpeed)
{
    speed_ = newSpeed;
}

