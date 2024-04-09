#include "Headers/Sprite.hpp"

Sprite::Sprite(sf::Vector2f position, float rotation, sf::Vector2f size)
    : position_(position)
    , size_(size)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(rotation);
}

Sprite::Sprite(sf::Vector2f position, float rotation)
    : position_(position)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(rotation);
}

Sprite::Sprite()
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);   
}

Sprite::Sprite(sf::Vector2f position)
    : Sprite(position, 0)
{
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Green);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
}

bool Sprite::checkCollision(const std::shared_ptr<Sprite>& sprite)
{
    if(rectangle_.getGlobalBounds().intersects(
            sprite->getRectangle().getGlobalBounds()
                ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Sprite::checkSpritesCollision(std::vector<std::shared_ptr<Sprite>>& vectorOfSprites)
{   
    bool CollisionStatus = false;
    for(auto& sprite : vectorOfSprites)
    {
        if(checkCollision(sprite))
        {
            HP_--;
            sprite->setHP(sprite->getHP() - 1);
            CollisionStatus = true;
        }
    }
    return CollisionStatus;
}

void Sprite::draw(sf::RenderWindow& i_window)
{   
    rectangle_.setPosition(position_);
    i_window.draw(rectangle_);
}

bool Sprite::isInMap()
{
    //checking if the center of the sprite is inside the map
    if(position_.x >= 0 and position_.x <= SCREEN_WIDTH and
       position_.y >= 0 and position_.y <= SCREEN_HEIGHT)
    {   
        return true;
    }
    else
    {   
        return false;
    }
}

/*____________________GETTERS___________________________*/

size_t Sprite::getHP() const
{
    return this->HP_;
}

sf::Vector2f Sprite::getPosition() const
{
    return this->position_;
}

sf::RectangleShape Sprite::getRectangle() const
{
    return this->rectangle_;
}

sf::Vector2f Sprite::getSize() const
{
    return this->size_;
}

/*__________________SETTERS___________________________*/

void Sprite::setPosition(sf::Vector2f const newPos)
{
    position_ = newPos;
}

void Sprite::setHP(size_t const hp)
{
    HP_ = hp;
}

void Sprite::setSize(sf::Vector2f const size)
{
    size_ = size;
}

/*______________________OPERATORS_______________________*/

Sprite& Sprite::operator--()
{
    HP_--;
    return *this;
}
/*
std::shared_ptr<Sprite>& Sprite::operator--()
{
    HP_--;
    return *this;
}
*/

