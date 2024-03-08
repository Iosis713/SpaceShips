#include <iostream>
#include <chrono>
#include <thread>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



int main()
{   
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SpaceShips");
    
    Sprite sprite1;
    
    Moveable moveable1(sf::Vector2f(600.f, 700.f));

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
        
        moveable1.changeDirection();
            
        sprite1.draw(window);
        moveable1.draw(window);
        
        //std::cout << moveable1.getRotation() << '\n';

        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
        window.clear();
    }

    return 0;
}
