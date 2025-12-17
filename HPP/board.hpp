#ifndef BOARD_CLASS
#define BOARD_CLASS

#include "heap_card.hpp"

#define MAX_SIZE_BOARD 6

class board: public heap_card
{
    private:
        int border_x;
        int border_y;
    public:
        board(bool is_bot);
        bool is_max_size();
        void render(sf::RenderWindow& window,bool is_bot);
        std::vector<card_gen*> attacking(int i);
};

#endif