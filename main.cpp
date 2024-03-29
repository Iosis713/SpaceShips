#include <iostream>
#include <chrono>
#include <thread>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"
#include "Source/Headers/Bullet.hpp"
#include "Source/Headers/Spaceship.hpp"
#include "Source/Headers/EnemiesManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



int main()
{   
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SpaceShips");
    
    //std::vector<std::shared_ptr<Sprite>> spritesVec;
    //spritesVec.push_back(std::make_shared<Sprite>());
    
    Spaceship spaceship;
    
    EnemiesManager enemiesManager;


    while(window.isOpen())
    {
        sf::Event event;
        
        //close window
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //spritesVec[0]->draw(window);
        
        

        spaceship.accelerate();
        spaceship.changeDirection();
        spaceship.shoot();
        spaceship.updatePosition();
        spaceship.checkBulletsCollision(enemiesManager.getManager());
        spaceship.organizeBullets();
        spaceship.draw(window);
    
        
        enemiesManager.clearEnemies();
        enemiesManager.organizeEnemies();
        enemiesManager.drawAll(window);
        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
        window.clear();
    }

    return 0;
}
