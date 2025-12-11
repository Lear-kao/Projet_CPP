#ifndef PLAYER
#define PLAYER

#include "heap_card.hpp"
#include "hand.hpp"

class player
{
    private:
        heap_card deck;
        hand hand_player;
        heap_card board;
        int charge;
        int life;
    public:
        player(void);
    //logic
        void play_card();
        void hitted(int damage);
        bool is_dead();
        std::vector<bool> get_board();
    //lib_graph
        void render_general(sf::RenderWindow& window);
        void render_board(sf::RenderWindow& window);
        void render_hand(sf::RenderWindow& window);
};


#endif