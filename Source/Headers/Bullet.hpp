#pragma once
#ifndef BULLET
#define BULLET

#include "Moveable.hpp"

class Bullet : public Moveable
{
protected:
    size_t damage_ = 1;

public:
    Bullet(sf::Vector2f position, float rotation);
    Bullet(sf::Vector2f position, float rotation, sf::Vector2f size, float maxSpeed, float speed);

    virtual ~Bullet() = default;
};

#endif

