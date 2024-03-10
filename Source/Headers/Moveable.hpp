#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"
#include <math.h>

class Moveable : public Sprite
{
protected:  
    float maxSpeed_ = 6.f;
    float speed_ = 0.f;
    sf::Vector2f velocity_{0.f, 0.f};
    
public:
    Moveable();
    Moveable(sf::Vector2f position);
    Moveable(sf::Vector2f position, float rotation);
    Moveable(sf::Vector2f position, float rotation, float maxSpeed, float speed);

    virtual ~Moveable() = default;
    
    void updatePosition();

    float getSpeed() const;
    float getRotation() const;

    void setSpeed(float newSpeed);

};

#endif

