#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include <SFML/Graphics.hpp>
#include "game_controller.hpp"
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
    private:
        game_controller *controller;
        player *r_player = new player(false);
        player *bot = new player(true);
    public:
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void update(void);
        void render(sf::RenderWindow& window);

};

#endif