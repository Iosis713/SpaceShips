#include "Headers/Spaceship.hpp"

Spaceship::Spaceship()
    : Controllable(sf::Vector2f(static_cast<float>(SCREEN_WIDTH/2), static_cast<float>(SCREEN_HEIGHT/2)),
                  0.f, // rotation
                  sf::Vector2f(40.f, 30.f), //size
                  9.f, //maxSpeed
                  0.f, //speed
                  0.2f, //acceleration
                  3.f) //rotationalSpeed
{
    setHP(5);
    previousInvulnerabilityTime_ = std::chrono::steady_clock::now();
    bulletManager_.reserve(bulletsQuantity_);
       
    sprite_.setOrigin(size_.x/2, size_.y/2);
    sprite_.setPosition(position_);
    sprite_.setRotation(180.f);
}

void Spaceship::checkBulletsCollision(std::vector<std::shared_ptr<Sprite>>& vectorOfSprites)
{   
    for(auto& bullet : bulletManager_)
    {
        bullet->checkSpritesCollision(vectorOfSprites);
        if(bullet->getHP() <= 0 and bullet->isInMap())
        {   
            points_++;
            if(bulletsQuantity_ < (maxBulletsQuantity_ - 1))
            {
                bulletsQuantity_ += 1;
                if(getRandom() == 4)
                {
                    //20% chance for bonus bullet
                    bulletsQuantity_ += 1;
                }
            }
            else if(bulletsQuantity_ == (maxBulletsQuantity_ - 1))
            {
                bulletsQuantity_ = maxBulletsQuantity_;
            }
        }
    }
}

bool Spaceship::checkSpritesCollision(std::vector<std::shared_ptr<Sprite>>& vectorOfSprites) 
{   
    auto HPbeforeCollision = getHP();
    auto collisionStatus = false;
    if(Sprite::checkSpritesCollision(vectorOfSprites) and invulnerability_ == false)
    {
        invulnerability_ = true;
        previousInvulnerabilityTime_ = std::chrono::steady_clock::now();
        collisionStatus = true;
    }
    
    else if(Sprite::checkSpritesCollision(vectorOfSprites) and invulnerability_ == true)
    {
        this-> HP_ = HPbeforeCollision;
        collisionStatus = true;
    }

    invulnerabilityDT = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousInvulnerabilityTime_).count();
        
    if(invulnerabilityDT >= invulnerabilityTime_)
    {
        invulnerability_ = false;
    }

    return collisionStatus;
}

void Spaceship::draw(sf::RenderWindow& i_window)
{
    sf::Texture texture;
    texture.loadFromFile("../Source/Images/Spaceship.png");

    sprite_.setTexture(texture);
    sprite_.setPosition(position_);

    i_window.draw(sprite_);
    
    if(speed_ > 0)
    {
        sf::Sprite light;
        sf::Texture engineTexture;
        engineTexture.loadFromFile("../Source/Images/EngineLight.png");
        light.setOrigin(7.5f, 26.f);
        light.setTexture(engineTexture);
        light.setRotation(getRotation());
        //light.setPosition(sf::Vector2f(position_.x, position_.y - cos(getRotation() * M_PI / 180) * 15));
        light.setPosition(sf::Vector2f(position_.x, position_.y));
        light.setTextureRect(sf::IntRect(15 * std::floor(static_cast<int>(speed_)/3), 0, 15, 15));
        i_window.draw(light);
    }

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
    maxBulletsQuantity_ = 20 + (points_ / 10) * 10;
}

void Spaceship::reset()
{
    HP_ = 5;
    position_ = sf::Vector2f(static_cast<float>(SCREEN_WIDTH/2), static_cast<float>(SCREEN_HEIGHT/2));
    bulletsQuantity_ = 20;
    points_ = 0;
    speed_ = 0.f;
    sprite_.setRotation(180.f);
}

void Spaceship::shoot()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and
       shootAbility_ and
       bulletsQuantity_ > 0)
    {
        bulletManager_.push_back(std::make_shared<Bullet>(position_, Spaceship::getRotation()));
        previousShootTime_ = std::chrono::steady_clock::now();
        bulletsQuantity_--;
        shootAbility_ = false;
    }

    deltaTime_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousShootTime_).count();
    
    if(deltaTime_ > shootUnabilityTime_)
    {
        shootAbility_ = true;
    }

}

void Spaceship::shootBack()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) and
       shootAbility_ and
       bulletsQuantity_ > 2)
    {   
        std::array<float, 3> rotation = {Spaceship::getRotation() - 180.f - 45.f,
                                         Spaceship::getRotation() - 180.f,
                                         Spaceship::getRotation() - 180.f + 45.f};

        for(auto& value : rotation)
        {   
            bulletManager_.push_back(std::make_shared<Bullet>(position_, value));
        }
        previousShootTime_ = std::chrono::steady_clock::now();
        bulletsQuantity_ -= 3;
        shootAbility_ = false;
    }
    
    deltaTime_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousShootTime_).count();

    if(deltaTime_ > shootUnabilityTime_)
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

size_t Spaceship::getBullets() const
{
    return this->bulletsQuantity_;
}

std::vector<std::shared_ptr<Bullet>>& Spaceship::getBulletManager()
{
    return this->bulletManager_;
}

size_t Spaceship::getPoints() const
{
    return this->points_;
}

int Spaceship::getRandom()
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> distribution(0, 4);
    return distribution(randGenerator);
}

