#ifndef HAND_HPP
#define HAND_HPP

#include "heap_card.hpp"

#define MAX_SIZE 8

class hand: public heap_card
{
    private:
        int border_x;
        int border_y;
    public:
        hand(bool is_bot);
        bool is_max_size(void);
        void render(sf::RenderWindow& window);
        void update( void );
        card_gen* play_one(int i);
};

#endif