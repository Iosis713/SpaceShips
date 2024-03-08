#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"
#include <math.h>

class Moveable : public Sprite
{
protected:
    float acceleration_ = 0.1f;
    float maxSpeed_ = 6.f;
    float rotationSpeed_ = 2.f; //deg
    float speed_ = 0.f;
    sf::Vector2f velocity_{0.f, 0.f};
    
public:
    Moveable();
    Moveable(sf::Vector2f position);

    virtual ~Moveable() = default;
    
    void accelerate();
    void changeDirection();
    void updatePosition();


    float getSpeed() const;
    float getRotation() const;

    void setSpeed(float newSpeed);

};

#endif

