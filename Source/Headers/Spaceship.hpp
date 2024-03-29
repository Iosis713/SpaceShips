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
    std::vector<std::shared_ptr<Bullet>> bulletManager_;
    size_t bulletsQuantity_ = 20;
    unsigned deltaTime = 0; //ms
    bool shootAbility_ = true;
    std::chrono::time_point<std::chrono::steady_clock> previousShootTime_;
    const unsigned shootUnabilityTime_ = 150; //ms
    size_t points_ = 0;

public:
    Spaceship();    
    virtual ~Spaceship() = default;
    
    void checkBulletsCollision(std::vector<std::shared_ptr<Sprite>>& vectorOfSprites);
    void checkSpaceshipCollision(std::vector<std::shared_ptr<Sprite>>& vectorOfSprites);
    void draw(sf::RenderWindow& i_window) override;
    void organizeBullets();
    void shoot();
    void updatePosition() override;

    std::vector<std::shared_ptr<Bullet>>& getBulletManager();
    size_t getPoints() const;
        
};

#endif

