#ifndef PLAYER
#define PLAYER

#include <vector>
#include <SFML/Graphics.hpp>
#include "class_UI.hpp"

#define BOARD 0
#define HAND 1

class deck;
class board;
class hand;
class card_gen;
class unit;
class spell;
class UI;

class player
{
    private:
        int charge = 1;
        int life = 20;

    protected:
        deck *deck_player;
        hand *hand_player;
        board *board_player;
        
        //variable interface utilisateur
        UI UI_charge;
        UI UI_life;

    public:
        player(bool);
        virtual ~player();

    //méthode utilitaire
        bool is_dead();
        void pop_from(int from, card_gen* who);
        void set_charge(int);
        int get_charge(void);
        int get_pv();
        card_gen* get_card_from_hand(int);
        card_gen* get_card_from_board(int);
        size_t get_player_hand_size();
        size_t get_player_board_size();
        virtual bool is_bot() {return false;}

    //méthode de jeu
        void new_turn( int charge);
        void draw_card(void);
        void hitted(int damage);
        void healled(int heal);
        void add_board(card_gen* card);
        void summon_card(unit* unite);
        void cast_spell(spell* casted, unit* target);
        void cast_spell(spell* casted, player* target);

    //méthode d'interaction
        unit* card_clicked_board(sf::Vector2f mousePos);
        card_gen* card_clicked_hand(sf::Vector2f mousePos);
        void update(float delta);

    //méthode d'affichage
        void render_general(sf::RenderWindow& window);
        void render_charge(sf::RenderWindow& window);
        void render_deck(sf::RenderWindow& window);
        void render_board(sf::RenderWindow& window);
        void render_hand(sf::RenderWindow& window);
        void render_life(sf::RenderWindow& window);

};


#endif