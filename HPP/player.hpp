#ifndef PLAYER
#define PLAYER

#include "heap_card.hpp"
#include "hand.hpp"
#include "board.hpp"

class player
{
    private:
        heap_card *deck;
        hand *hand_player;
        board *board_player;
        int charge;
        int life = 20;
        bool bot;
    public:
        player(bool a);
    //logic
        void draw_card(void);
        void play_card();
        void hitted(int damage);
        void healled(int heal);
        bool is_dead();
        std::vector<bool> get_board();
    //lib_graph
        void render_general(sf::RenderWindow& window);
        void render_board(sf::RenderWindow& window);
        void render_hand(sf::RenderWindow& window);
};


#endif