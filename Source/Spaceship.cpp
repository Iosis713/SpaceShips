#include "Headers/Spaceship.hpp"

Spaceship::Spaceship()
    : Controllable(sf::Vector2f(static_cast<float>(SCREEN_WIDTH/2), static_cast<float>(SCREEN_HEIGHT/2)),
                  0.f, // rotation
                  sf::Vector2f(20.f, 40.f), //size
                  8.f, //maxSpeed
                  0.f, //speed
                  0.1f, //acceleration
                  2.f) //rotationalSpeed
{
    bulletManager_.reserve(bulletsQuantity_);

    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Magenta);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(0.f);
}

void Spaceship::checkBulletsCollision(std::vector<std::unique_ptr<Sprite>>& vectorOfSprites)
{   
    for(auto& bullet : bulletManager_)
    {
        for(auto& sprite : vectorOfSprites)
        {
            if(bullet->checkCollision(sprite))
            {
                --*bullet;
                --*sprite;
                std::cout << "Bullet collision!\n";
            }
        }
    }
}

void Spaceship::draw(sf::RenderWindow& i_window)
{
    rectangle_.setPosition(position_);
    i_window.draw(rectangle_);

    for(auto& bullet : bulletManager_)
    {
        bullet->draw(i_window);
    }
}

void Spaceship::organizeBullets()
{   
    for(auto& bullet : bulletManager_)
    {
        if(bullet->getHP() <= 0)
        {
            bullet = nullptr;
        }
    }

    auto it = std::remove_if(bulletManager_.begin(), bulletManager_.end(), [&](const auto& bullet)
            {
                return (bullet == nullptr);
            });

    bulletManager_.erase(it, bulletManager_.end());
}

void Spaceship::shoot()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and
       shootAbility_)
    {
        bulletManager_.push_back(std::make_unique<Bullet>(position_, Spaceship::getRotation()));
        previousShootTime_ = std::chrono::steady_clock::now();
        shootAbility_ = false;
    }

    deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousShootTime_).count();
    
    if(deltaTime > shootUnabilityTime_)
    {
        shootAbility_ = true;
    }

}

void Spaceship::updatePosition()
{
    Moveable::updatePosition();

    for(auto& bullet : bulletManager_)
    {
        bullet->updatePosition();
        if(!bullet->isInMap())
        {
            bullet->setHP(0);
        }
    }
}

std::vector<std::unique_ptr<Bullet>>& Spaceship::getBulletManager()
{
    return this->bulletManager_;
}

