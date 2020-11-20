#include "Game.h"
//Static functions

//Initializer functions
void Game::initWindow()
    {
        std::ifstream ifs("config/window.ini");
        std::string title="None";
        sf::VideoMode window_bounds(800,600);
        unsigned framerate_limit=120;
        bool vertical_sync_enabled=false;

        if (ifs.is_open())
        {
            std::getline(ifs, title);
            ifs>>window_bounds.width>>window_bounds.height;
            ifs>>framerate_limit;
            ifs>>vertical_sync_enabled;
        }
        ifs.close();
        this->window= new sf::RenderWindow (window_bounds, title);
        this->window->setFramerateLimit(framerate_limit);
        this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    }
void Game::initStates()
    {
        this->states.push(new GameState(this->window));
    }
//Constructors/destructors
Game::Game()
    {
        this->initWindow();
        this->initStates();
    }
Game::~Game()
    {
        delete this->window;
        while(!states.empty())
        {
            delete this->states.top();
            this->states.pop();
        }
    }
void Game::endApplication()
    {
        std::cout<<"Ending application"<<std::endl;
    }
//Functions
void Game::updateDt()
    {
        //update time to render 1 frame
        this->dt = this->dtClock.restart().asSeconds();
        system("cls");
        std::cout<< this->dt<<std::endl;
    }
void Game::updateSFMLEvents()
    {
        while (this->window->pollEvent(this->sfEvent))
        {
            if (this->sfEvent.type == sf::Event::Closed)
                this->window->close();
        }
    }

void Game::update()
    {
        this->updateSFMLEvents();
        if(!states.empty())
        {
            states.top()->update(this->dt);
            if(this->states.top()->getQuit())
            {
                this->states.top()->endState();
                delete this->states.top();
                this->states.pop();
            }
        }
        //closing ap
        else
        {
            this->endApplication();
            this->window->close();
        }
    }
void Game::render()
    {
        //render things
        this->window->clear();

        if(!states.empty())
            states.top()->render();

        this->window->display();
    }
void Game::run()
    {

    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
    }
