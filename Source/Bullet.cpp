#include "Headers/Bullet.hpp"


Bullet::Bullet(sf::Vector2f position, float rotation, sf::Vector2f size, float maxSpeed, float speed)
    : Moveable(position, rotation, size, maxSpeed, speed)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Yellow);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(rotation);
}

Bullet::Bullet(sf::Vector2f position, float rotation)
    : Bullet(position, rotation, sf::Vector2f(10.f, 10.f), 15.f, 15.f)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Yellow);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(rotation);
}

