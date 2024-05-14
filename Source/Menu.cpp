#include "Headers/Menu.hpp"

Menu::Menu()
{
    buttons_[static_cast<int>(selected_)].setStatus(true);
}

void Menu::changeSelected()
{   
    deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousOptionChangeTime).count();
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or
       sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) and
       deltaTime > 200)
    {
        if(selected_ == Selected::PLAY)
        {
            selected_ = Selected::EXIT;
        }else
        {
            selected_ = Selected::PLAY;
        }
        previousOptionChangeTime = std::chrono::steady_clock::now();
    }
}

void Menu::drawButtons(sf::RenderWindow& i_window)
{
    for(auto& button : buttons_)
    {
        button.draw(i_window);
    }
    //std::cout << static_cast<int>(selected_) << '\n';
}

void Menu::organizeButtons()
{
    if(!buttons_[static_cast<int>(selected_)].getStatus())
    {    
        buttons_[static_cast<int>(selected_)].setStatus(true);    
    }
    //opposite set to false
    buttons_[((static_cast<int>(selected_) + 1) % 2)].setStatus(false);
}
