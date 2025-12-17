#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include <SFML/Graphics.hpp>
#include "game_controller.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "class_button.hpp"



class main_game
{
    private:
        int turn = 0;
        game_controller *controller = new game_controller();
        player *r_player = new player(false);
        player *bot = new player(true);
        gen_button *next_phase = new gen_button("assets_lib_g/button_next_phase.png");
    public:
        main_game(void);
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void update(void);
        void render(sf::RenderWindow& window);

};

#endif