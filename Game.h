#pragma once
#include "States/GameState.h"

class Game
    {
    private:
        //Variables
        sf::RenderWindow *window;
        sf::Event sfEvent;
        sf::Clock dtClock;
        float dt;
        std::stack<State*> states;
        //Initializers
        void initWindow();
        void initStates();
    public:
        //Constructors/destructors
        Game();
        virtual ~Game();
        //Functions
        void endApplication();
        //Update
        void updateDt();
        void updateSFMLEvents();
        void update();
        //Core
        void render();
        void run();
    };
