#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"

class Moveable : public Sprite
{
protected:
    float speed_ = 3.f;
    float rotationSpeed_ = 2.f; //deg
    
public:
    Moveable();
    Moveable(sf::Vector2f position);

    virtual ~Moveable() = default;

    void changeDirection();

    float getSpeed() const;
    float getRotation() const;

    void setSpeed(float newSpeed);

};

#endif

