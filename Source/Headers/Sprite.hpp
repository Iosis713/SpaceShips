#pragma once
#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <memory>
#include "Global.hpp"
#include <SFML/Graphics.hpp>

class Sprite
{
protected:
    size_t HP_ = 1;
    sf::Vector2f position_{200.f, 300.f};
    sf::Vector2f size_{30.f, 30.f};
    sf::Sprite sprite_;
    
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
    
    size_t getHP() const;
    sf::Vector2f getPosition() const;
    float getRotation() const;
    sf::Vector2f getSize() const;
    sf::Sprite getSprite() const;

    void setHP(size_t const hp);   
    void setPosition(sf::Vector2f const newPos);
    void setSize(sf::Vector2f const size);
    void setRotation(float const rotation);

    Sprite& operator--();
};

#endif

