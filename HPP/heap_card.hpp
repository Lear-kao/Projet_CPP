#ifndef HEAP_CARD
#define HEAP_CARD

#include <SFML/Graphics.hpp>
#include "card_gen.hpp"
#include "unit.hpp"
#include "spell.hpp"
#include <vector>

class heap_card
{
    protected:
        std::vector<card_gen*> heap;
    public:
        void pop_i(int i);
        void pop_i(unit* u);
        void suffle();//a faire(Noah)
        card_gen* pick_one();//fini
        void add_one( card_gen* nc);//a faire(Noah)
        card_gen *get_card_x(int n);
        int get_size(void);//a faire(Noah)
        virtual void render(sf::RenderWindow& window) = 0;
};


#endif