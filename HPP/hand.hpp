#ifndef HAND_HPP
#define HAND_HPP

#include "heap_card.hpp"

#define MAXSIZE 7

class hand: public heap_card
{
    public:
        bool is_max_size();
        void render(sf::RenderWindow& window, bool is_bot);
        card_gen* play_one(int i);
};

#endif