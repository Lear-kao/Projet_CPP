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
        void render(sf::RenderWindow& window);
        void untap_all( void );
        bool check(std::string categorie);
        std::vector<card_gen*> attacking(int i);
};

#endif