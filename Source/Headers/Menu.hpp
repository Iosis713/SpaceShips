#pragma once
#ifndef MENU
#define MENU

#include <SFML/Graphics.hpp>

#include <array>
#include <chrono>
#include <iostream>
#include <thread>

#include "Button.hpp"

using Time = std::chrono::time_point<std::chrono::steady_clock>;

class Menu
{
protected:
    std::array<Button, 2> buttons_{Button(sf::Vector2f(400.f, 400.f), "PLAY"),
                                   Button(sf::Vector2f(400.f, 550.f), "EXIT")};

    unsigned int deltaTime = 0;
    enum class Selected
    {
        PLAY = 0,
        EXIT = 1
    };
    Selected selected_ = Selected::PLAY;
    Time previousOptionChangeTime;

public:
    Menu();
    ~Menu() = default;
    
    void changeSelected();
    void drawButtons(sf::RenderWindow& i_window);
    void organizeButtons();
};
#endif

