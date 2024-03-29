#pragma once
#ifndef ENEMIESMANAGER
#define ENEMIESMANAGER

#include "Moveable.hpp"
#include "Bullet.hpp"

#include <chrono>
#include <vector>
#include <memory>
#include <random>
#include <thread>

using Manager = std::vector<std::shared_ptr<Sprite>>;
using Time = std::chrono::time_point<std::chrono::steady_clock>;
class EnemiesManager
{
protected:
    unsigned deltaTime = 200;
    Manager manager_;
    unsigned maxEnemies = 30;
    Time previousEnemyRelease; 
public:
    EnemiesManager();
    ~EnemiesManager() = default;
    void addMoveable();
    void drawAll(sf::RenderWindow& i_window);
    void organizeEnemies();
    void clearEnemies();

    Manager& getManager();
    int getRandom();
};

#endif

