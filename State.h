#pragma once
#include "../Entities/Entity.h"
class State
    {
    private:
        //Variables
        sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;
    public:
        State(sf::RenderWindow* window);
        virtual~State();
        //Functions
        const bool& getQuit() const;
        virtual void endState()=0;
        virtual void checkForQuit();
        virtual void updateKeybinds(const float&dt)=0;
        virtual void update(const float&dt)= 0;
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
    };
