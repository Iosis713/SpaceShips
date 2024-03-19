#pragma once
#ifndef SPACESHIP
#define SPACESHIP

#include "Controllable.hpp"
#include "Bullet.hpp"

#include <chrono>
#include <thread>
#include <memory>
#include <vector>

class Spaceship : public Controllable
{
protected:
    std::vector<std::unique_ptr<Bullet>> bulletManager_;
    size_t bulletsQuantity_ = 20;
    unsigned deltaTime = 0; //ms
    bool shootAbility_ = true;
    std::chrono::time_point<std::chrono::steady_clock> previousShootTime_;
    const unsigned shootUnabilityTime_ = 150; //ms
public:
    Spaceship();    
    virtual ~Spaceship() = default;
    
    void checkBulletsCollision(std::vector<std::unique_ptr<Sprite>>& vectorOfSprites);
    void draw(sf::RenderWindow& i_window) override;
    void organizeBullets();
    void shoot();
    void updatePosition() override;

    std::vector<std::unique_ptr<Bullet>>& getBulletManager();
};

#endif

