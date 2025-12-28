#ifndef PLAYER
#define PLAYER

#include <vector>
#include <SFML/Graphics.hpp>
#include "class_UI.hpp"

class deck;
class board;
class hand;
class card_gen;
class unit;
class UI;

class player
{
    private:
        deck *deck_player;
        hand *hand_player;
        board *board_player;
        int charge = 1;
        int life = 20;
        bool bot;

        //variable interface utilisateur
        UI UI_charge;
        UI UI_life;
    public:
        player(bool a);
        void update(float delta);
    //logic
        unit* card_clicked_board(sf::Vector2f mousePos);
        card_gen* card_clicked_hand(sf::Vector2f mousePos);

        void draw_card(void);
        void summon_card(unit* unite);
        void hitted(int damage);
        void healled(int heal);
        bool is_dead();
        hand* get_hand( void );
        board* get_board(void);
        void set_charge(int);
        int get_charge(void);
    //lib_graph
        void render_general(sf::RenderWindow& window);
        void render_charge(sf::RenderWindow& window);
        void render_deck(sf::RenderWindow& window);
        void render_board(sf::RenderWindow& window);
        void render_hand(sf::RenderWindow& window);
        void render_life(sf::RenderWindow& window);

};


#endif