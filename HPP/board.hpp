#include "heap_card.hpp"

#define MAX_SIZE_BOARD 6

class board: public heap_card
{
    public:
        bool is_max_size();
        void render(sf::RenderWindow& window,bool is_bot);
        std::vector<card_gen*> attacking(int i);
};