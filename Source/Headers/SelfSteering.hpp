#pragma once
#ifndef SELFSTEERING
#define SELFSTEERING

#include <cmath>
#include <cstdlib>
#include <memory>
#include <random>

#include "Controllable.hpp"

class SelfSteering : public Controllable
{
protected:
    sf::Vector2f targetPosition_{0.0, 0.0};
    float targetDirection_ = 180.f;
public:
    SelfSteering();
    SelfSteering(sf::Vector2f position);
    virtual ~SelfSteering() = default;
    
    void aimTarget(const Sprite& sprite);
    void aimTarget(const std::shared_ptr<Sprite>& sprite_ptr);
    void regulateDirection();

    int getRandom();

};
#endif
