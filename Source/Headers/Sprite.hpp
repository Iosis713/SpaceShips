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
    const sf::Vector2f size_{30.f, 30.f};
    sf::RectangleShape rectangle_;
    
public:
    Sprite();
    Sprite(sf::Vector2f position);
    Sprite(sf::Vector2f position, float rotation);
    Sprite(sf::Vector2f position, float rotation, sf::Vector2f size);
    virtual ~Sprite() = default;
    
    bool checkCollision(const std::unique_ptr<Sprite>& sprite);  
    virtual void draw(sf::RenderWindow& i_window);
    bool isInMap(); 
    
    size_t getHP() const;
    sf::Vector2f getPosition() const;
    sf::RectangleShape getRectangle() const;
    sf::Vector2f getSize() const;
    

    void setHP(size_t hp);   
    void setPosition(sf::Vector2f const newPos);

};

#endif

