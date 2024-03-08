#include "Headers/Moveable.hpp"

Moveable::Moveable()
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(180.f);
}

Moveable::Moveable(sf::Vector2f position)
    : Sprite(position)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Red);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(180.f);
}

void Moveable::accelerate()
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

void Moveable::updatePosition()
{
    float angle = rectangle_.getRotation() * M_PI / 180; // deg to radians
    using namespace std;

    velocity_.x = -speed_ * sin(angle);
    velocity_.y = speed_ * cos(angle);

    position_ += velocity_;
    
    cout << rectangle_.getRotation() << '\n';
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

