#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <map>
class Entity
    {
    private:

    public:
        Entity();
        virtual ~Entity();

        //Functions
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
    };
