#include <iostream>
#include <chrono>
#include <thread>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"
#include "Source/Headers/Bullet.hpp"
#include "Source/Headers/Spaceship.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



int main()
{   
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SpaceShips");
    
    Sprite sprite1;
    
    Spaceship spaceship;

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
        
        spaceship.accelerate();
        spaceship.changeDirection();
        spaceship.shoot();
        spaceship.updatePosition();

        spaceship.draw(window);

        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
        window.clear();
    }

    return 0;
}
