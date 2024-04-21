#include "Headers/EnemiesManager.hpp"

EnemiesManager::EnemiesManager()
{
    manager_.reserve(maxEnemies);
}

void EnemiesManager::addMoveable(const size_t level)
{
    manager_.push_back(std::make_shared<Moveable>(sf::Vector2f(static_cast<float>(getRandom()), -20),
                                                static_cast<float>(getRandom() % 180),
                                                level * 3.f,
                                                level * 3.f));
}

void EnemiesManager::addSelfSteering()
{
    manager_.push_back(std::make_shared<SelfSteering>(sf::Vector2f(static_cast<float>(getRandom()),
                                                        static_cast<float>(SCREEN_HEIGHT) -1 )));
}

void EnemiesManager::drawAll(sf::RenderWindow& i_window)
{
    for(auto& sprite : manager_)
    {
        sprite->draw(i_window);
    }
}

void EnemiesManager::organizeEnemies(const size_t level, const Spaceship& target)
{
    deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousEnemyRelease).count();
    
    if(deltaTime > 200 and manager_.size() < maxEnemies)
    {
        if(level >= 2 and getRandom() % (100/(level*2)) == 0)
        {
            addSelfSteering();  
        }
        else
        {
            addMoveable(level);
        }
        previousEnemyRelease = std::chrono::steady_clock::now();
    }   

    for(auto& sprite : manager_)
    {   
        //to check collision with other enemies
        auto temporaryManager = manager_;
        temporaryManager.erase(std::remove(temporaryManager.begin(), temporaryManager.end(), sprite), temporaryManager.end());

        if(typeid(*sprite) == typeid(SelfSteering))
        {
            dynamic_pointer_cast<SelfSteering>(sprite)->aimTarget(target);
            dynamic_pointer_cast<SelfSteering>(sprite)->regulateDirection();
            dynamic_pointer_cast<SelfSteering>(sprite)->updatePosition();
            
            //WithoutCollisionTest
            dynamic_pointer_cast<SelfSteering>(sprite)->aimWithoutCollision(target, temporaryManager);

            sprite->checkSpritesCollision(temporaryManager);
        }
        else
        {
            dynamic_pointer_cast<Moveable>(sprite)->updatePosition();
        }
    }
}

void EnemiesManager::clearEnemies()
{
    
    for(auto& sprite : manager_)
    {
        if(sprite->getPosition().x < 0 or
           sprite->getPosition().x > SCREEN_WIDTH or
           sprite->getPosition().y > SCREEN_HEIGHT)
        {
            sprite->setHP(0);
        }  
    }
    auto it = std::remove_if(manager_.begin(), manager_.end(), [&](const auto& sprite)
            {
                return (sprite->getHP() <= 0);
            });
    
   manager_.erase(it, manager_.end());
}

int EnemiesManager::getRandom()
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> distribution(50, SCREEN_WIDTH - 50);
    return distribution(randGenerator);
}

Manager& EnemiesManager::getManager()
{
    return this-> manager_;
}

