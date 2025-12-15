#ifndef HEAP_CARD
#define HEAP_CARD

#include <SFML/Graphics.hpp>
#include "card_gen.hpp"
#include "unit.hpp"
#include "spell.hpp"
#include <vector>

class heap_card
{
    private:
        std::vector<card_gen*> heap;
    public:
        heap_card();//a faire(Noah)
        void suffle();//a faire(Noah)
        card_gen* pick_one();//fini
        void add_one( card_gen* nc);//a faire(Noah)
        int get_size(void);//a faire(Noah)
};


#endif