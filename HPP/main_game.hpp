#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "unit.hpp"

class main_game
{
    private:
        player m_player;
    public:
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void update();
        void render(sf::RenderWindow& window);
};

#endif