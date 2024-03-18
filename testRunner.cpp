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
    ship1.getBulletManager().push_back(std::make_unique<Bullet>(sf::Vector2f(200, 500), 0));
    ship1.getBulletManager().push_back(std::make_unique<Bullet>(sf::Vector2f(200, 500), 0));
    ship1.getBulletManager().push_back(std::make_unique<Bullet>(sf::Vector2f(200, 500), 0));

    ship1.getBulletManager()[1]->setPosition(sf::Vector2f(-10, 500));
    ship1.updatePosition();
    ship1.organizeBullets();

    ASSERT_EQ(2, ship1.getBulletManager().size());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

