#include "heap_card.hpp"

class hand: public heap_card
{
    public:
        bool is_max_size();
        void render(sf::RenderWindow& window);
        card_gen* play_one(int i);
}