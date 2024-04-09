#include "Headers/SelfSteering.hpp"

SelfSteering::SelfSteering()
{   
    setSize(sf::Vector2f(15.f, 30.f));
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Yellow);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(180.f);
    speed_ = 10.f;
    rotationSpeed_ = 5.f;
}

SelfSteering::SelfSteering(sf::Vector2f position)
    : Controllable(position)
{   
    setSize(sf::Vector2f(15.f, 30.f));
    rectangle_.setOrigin(size_.x/2, size_.y/2);
    rectangle_.setFillColor(sf::Color::Yellow);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);
    rectangle_.setRotation(180.f);
    speed_ = 10.f;
    rotationSpeed_ = 5.f;
}

void SelfSteering::aimTarget(const Sprite& sprite)
{
    targetPosition_ = sprite.getPosition();
    targetDirection_ = atan((position_.x - targetPosition_.x) 
                             / (targetPosition_.y - position_.y)) * (180.f / M_PI);

    if(targetPosition_.y < position_.y)
    {
        targetDirection_ += 180.f;
    }

    if(targetDirection_ < 0)
    {
        targetDirection_ += 360.f;
    }
}

void SelfSteering::aimTarget(const std::shared_ptr<Sprite>& sprite_ptr)
{
    targetPosition_ = sprite_ptr->getPosition();
    targetDirection_ = atan((position_.x - targetPosition_.x) 
                             / (targetPosition_.y - position_.y)) * (180.f / M_PI);

    if(targetPosition_.y < position_.y)
    {
        targetDirection_ += 180.f;
    }

    if(targetDirection_ < 0)
    {
        targetDirection_ += 360.f;
    }
}

void SelfSteering::regulateDirection()
{
    auto rotationDifference = 0.f;
    
    rotationDifference = getRotation() - targetDirection_;
 
    //turn left or right
    
    if(getRotation() > targetDirection_ and
       getRotation() - targetDirection_ <= 180.f and
       getRotation() - targetDirection_ > 0.f)
    {
        rotationDifference = getRotation() - targetDirection_;
        if(rotationDifference < rotationSpeed_)
        {
            rectangle_.setRotation(targetDirection_);
        }
        else
        {
            turnLeft();
        }
    }
    
    else if(getRotation() > targetDirection_ and
            getRotation() - targetDirection_ > 180.f)
    {
        rotationDifference = getRotation() - targetDirection_ - 180.f;
        if(rotationDifference < rotationSpeed_)
        {
            rectangle_.setRotation(targetDirection_);
        }
        else
        {
            turnRight();
        }
    }
    
    else if(getRotation() < targetDirection_ and
            getRotation() - targetDirection_ < 0.f and
            getRotation() - targetDirection_ > -180.f)
    {
        rotationDifference = targetDirection_ - getRotation();
        if(rotationDifference < rotationSpeed_)
        {
            rectangle_.setRotation(targetDirection_);
        }
        else
        {
            turnRight();
        }
    }
    
    else if(getRotation() < targetDirection_ and
            getRotation() - targetDirection_ < 0.f)
    {
        rotationDifference = targetDirection_ - getRotation();
        if(rotationDifference < rotationSpeed_)
        {
            rectangle_.setRotation(targetDirection_);
        }
        else
        {
            turnLeft();
        }
    }
}

int SelfSteering::getRandom()
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> distribution(200, SCREEN_WIDTH - 200);
    return distribution(randGenerator);
}

