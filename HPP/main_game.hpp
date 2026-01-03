#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP
#include <SFML/Graphics.hpp>
#include "game_controller.hpp"
#include "player.hpp"
#include "bot.hpp"
#include "unit.hpp"
#include "class_button.hpp"

class board;

/* 
Objectif : Avoir un socle sur lequel les joueurs et le game controller peuvent se reposer pour
executer leurs tâches.
Point à améliorer, étendre le champ de détéction du main game qui se content de repérer les clicks de souris.
*/
class main_game
{
    private:
        int turn = 0;
        float delta; //le timer pour chaque frame, permet de gérer le temps sur l'update
        sf::Sprite board_;
        sf::Texture texture;
        player *r_player = new player(0);
        bot *b_player = new bot();
        game_controller *controller = new game_controller(r_player,b_player);
        gen_button *next_phase = new gen_button("assets_lib_g/button_next_phase.png");
    
        public:
        main_game(void);
        void set_board(void);

        //gestion des evenements
        player* who_s_dead( void );
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        void click_on_hand(sf::Vector2f mousePos);
        void click_on_current_attacker(sf::Vector2f mousePos);
        void click_on_board(sf::Vector2f mousePos);
        bool update(float d);
        void render(sf::RenderWindow& window);
};

#endif