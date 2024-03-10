#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float rotation, float maxSpeed, float speed)
    : Sprite(position, rotation)
    , maxSpeed_(maxSpeed)
    , speed_(speed)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
}

Moveable::Moveable(sf::Vector2f position, float rotation)
    : Sprite(position, rotation)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
}

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

void Moveable::updatePosition()
{
    float angle = rectangle_.getRotation() * M_PI / 180; // deg to radians
    using namespace std;

    velocity_.x = -speed_ * sin(angle);
    velocity_.y = speed_ * cos(angle);

    position_ += velocity_;
    
    //cout << rectangle_.getRotation() << '\n';
    //cout << position_.x << ", " << position_.y << '\n';
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

