#include "Headers/Menu.hpp"

Menu::Menu()
{
    buttons_[static_cast<int>(selected_)].setStatus(true);
}

void Menu::changeSelected()
{   
    deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousOptionChangeTime_).count();
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
        previousOptionChangeTime_ = std::chrono::steady_clock::now();
    }
}

void Menu::confirmOption()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        optionConfirmed_ = true;
    }
}

void Menu::drawButtons(sf::RenderWindow& i_window)
{
    for(auto& button : buttons_)
    {
        button.draw(i_window);
    }
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

/*______________________________GETTERS_________________________________*/

bool Menu::getOptionConfirmed()
{
    return this->optionConfirmed_;
}

Menu::Selected Menu::getSelected()
{
    return this->selected_;   
}

/*____________________________SETTERS___________________________________*/

void Menu::setOptionConfirmed(bool newStatus)
{
    optionConfirmed_ = newStatus;
}
