#include "GameState.h"
//Constructors
GameState::GameState(sf::RenderWindow* window)
    :State(window)
    {

    }
GameState::~GameState()
    {

    }
//Functions
void GameState::endState()
    {
        std::cout<<"Ending GameState";
    }
void GameState::updateKeybinds(const float&dt)
    {
        this->checkForQuit();
    }
void GameState::update(const float&dt)
    {
        this->updateKeybinds(dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
           {
        std::cout<<"A"<<std::endl;
           }
    }
void GameState::render(sf::RenderTarget* target)
    {

    }
