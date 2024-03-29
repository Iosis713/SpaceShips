#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"
#include "Source/Headers/Bullet.hpp"
#include "Source/Headers/Spaceship.hpp"
#include "Source/Headers/EnemiesManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window.hpp>

size_t LVL = 1;

int main()
{   
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SpaceShips");
   
    Spaceship spaceship;
    
    EnemiesManager enemiesManager;
    
    sf::Font font;
    font.loadFromFile("../Source/Arial.ttf");

    sf::Text LVL_TEXT;
    LVL_TEXT.setFont(font);
    LVL_TEXT.setFillColor(sf::Color::Green);
    LVL_TEXT.setCharacterSize(24);
    LVL_TEXT.setStyle(sf::Text::Bold);

    sf::Text POINTS_TEXT;
    POINTS_TEXT.setFont(font);
    POINTS_TEXT.setFillColor(sf::Color::Blue);
    POINTS_TEXT.setPosition(sf::Vector2f(0.0, 50.f));
    POINTS_TEXT.setCharacterSize(24);
    POINTS_TEXT.setStyle(sf::Text::Bold);

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
            
        LVL_TEXT.setString("Level: " + std::to_string(LVL));
        POINTS_TEXT.setString("Points: " + std::to_string(spaceship.getPoints()));
        //spritesVec[0]->draw(window);
        
        enemiesManager.organizeEnemies(LVL);

        spaceship.accelerate();
        spaceship.changeDirection();
        spaceship.shoot();
        spaceship.updatePosition();
        spaceship.checkBulletsCollision(enemiesManager.getManager());
        LVL = (spaceship.getPoints() / 10) + 1;
        //std::cout << "LVL" << LVL << '\n';
        //std::cout << "Points: " << spaceship.getPoints() << '\n';
        spaceship.checkSpritesCollision(enemiesManager.getManager());
        if(spaceship.getHP() <= 0)
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(5s);
            return 0;
        }
        spaceship.organizeBullets();
        enemiesManager.clearEnemies();

        spaceship.draw(window);       
        enemiesManager.drawAll(window);
        window.draw(LVL_TEXT);
        window.draw(POINTS_TEXT);
        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
        window.clear();
    }

    return 0;
}
