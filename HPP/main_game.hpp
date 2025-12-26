#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include <SFML/Graphics.hpp>
#include "game_controller.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "class_button.hpp"

class board;

class main_game
{
    private:
        int turn = 0;
        float delta; //le timer pour chaque frame, permet de gérer le temps sur l'update
        sf::Sprite board_;
        sf::Texture texture;
        player *r_player = new player(false);
        player *bot = new player(true);
        game_controller *controller = new game_controller(r_player,bot);
        gen_button *next_phase = new gen_button("assets_lib_g/button_next_phase.png");
    public:
        main_game(void);
        void set_board(void);

        //gestion des evenements
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void click_on_hand(sf::Vector2f mousePos);
        void click_on_current_attacker(sf::Vector2f mousePos);
        void click_on_board_current_player(sf::Vector2f mousePos);
        void click_on_board_waiting_player(sf::Vector2f mousePos);

        void update(float d);
        void render(sf::RenderWindow& window);
};

#endif