#pragma once
#ifndef SPRITE
#define SPRITE

#include <memory>
#include "Global.hpp"
#include <SFML/Graphics.hpp>

class Sprite
{
protected:
    int HP_ = 1;
    sf::Vector2f position_{200.f, 300.f};
    sf::Vector2f size_{30.f, 30.f};
    sf::Sprite sprite_;
    sf::Vector2f velocity_{0.f, 0.f};
    size_t counter_ = 0;

public:
    Sprite();
    Sprite(sf::Vector2f position);
    Sprite(sf::Vector2f position, float rotation);
    Sprite(sf::Vector2f position, float rotation, sf::Vector2f size);
    virtual ~Sprite() = default;
    
    bool checkCollision(const std::shared_ptr<Sprite>& sprite);  
    virtual bool checkSpritesCollision(std::vector<std::shared_ptr<Sprite>>& vectorOfSprites);
    virtual void draw(sf::RenderWindow& i_window);

    bool isInMap(); 
    
    size_t getCounter() const;
    int getHP() const;
    sf::Vector2f getPosition() const;
    float getRotation() const;
    sf::Vector2f getSize() const;
    sf::Sprite getSprite() const;
    sf::Vector2f getVelocity() const;
    
    void increaseCounter();
    void setHP(int const hp);   
    void setPosition(sf::Vector2f const newPos);
    void setSize(sf::Vector2f const size);
    void setRotation(float const rotation);

    Sprite& operator--();
};

#endif

