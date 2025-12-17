#ifndef HAND_HPP
#define HAND_HPP

#include "heap_card.hpp"

#define MAX_SIZE 6

class hand: public heap_card
{
    private:
        int border_x;
        int border_y;
    public:
        hand(bool is_bot);
        bool is_max_size();
        void render(sf::RenderWindow& window);

        card_gen* play_one(int i);
};

#endif