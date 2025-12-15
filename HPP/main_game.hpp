#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "unit.hpp"

enum Phase_turn
{
    Draw,
    main1,
    fight,
    main2,
    end
};


class main_game
{

    public:
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void update(void);
        void render(sf::RenderWindow& window);

};

#endif