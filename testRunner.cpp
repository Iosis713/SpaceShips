#include <iostream>
#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"
#include "Source/Headers/Bullet.hpp"
#include "Source/Headers/Spaceship.hpp"

TEST(BulletsTest, killingTest)
{
    Spaceship ship1;
    ship1.getBulletManager().push_back(std::make_shared<Bullet>(sf::Vector2f(200, 500), 0));
    ship1.getBulletManager().push_back(std::make_shared<Bullet>(sf::Vector2f(200, 500), 0));
    ship1.getBulletManager().push_back(std::make_shared<Bullet>(sf::Vector2f(200, 500), 0));

    ship1.getBulletManager()[1]->setPosition(sf::Vector2f(-10, 500));
    ship1.updatePosition();
    ship1.organizeBullets();

    ASSERT_EQ(2, ship1.getBulletManager().size());
}

TEST(SpriteCollision, positiveTest1)
{
    std::shared_ptr<Sprite> sprite1 = std::make_shared<Sprite>(sf::Vector2f(200, 200));
    std::shared_ptr<Sprite> sprite2 = std::make_shared<Sprite>(sf::Vector2f(215, 220));

    ASSERT_TRUE(sprite1->checkCollision(sprite2));
}

TEST(SpriteCollision, positiveTest2)
{
    std::shared_ptr<Sprite> sprite1 = std::make_shared<Sprite>(sf::Vector2f(200, 200));
    std::shared_ptr<Sprite> sprite2 = std::make_shared<Sprite>(sf::Vector2f(229, 229));

    ASSERT_TRUE(sprite1->checkCollision(sprite2));
}

TEST(SpriteCollision, negativeTest1)
{
    std::shared_ptr<Sprite> sprite1 = std::make_shared<Sprite>(sf::Vector2f(200, 200));
    std::shared_ptr<Sprite> sprite2 = std::make_shared<Sprite>(sf::Vector2f(235, 220));

    ASSERT_FALSE(sprite1->checkCollision(sprite2));
}


TEST(SpriteCollision, negativeTest2)
{
    std::shared_ptr<Sprite> sprite1 = std::make_shared<Sprite>(sf::Vector2f(170, 170));
    std::shared_ptr<Sprite> sprite2 = std::make_shared<Sprite>(sf::Vector2f(200, 200));

    ASSERT_FALSE(sprite1->checkCollision(sprite2));
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

