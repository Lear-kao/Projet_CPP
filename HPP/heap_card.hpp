#ifndef HEAP_CARD
#define HEAP_CARD

#include <SFML/Graphics.hpp>
#include "card_gen.hpp"
#include "unit.hpp"
#include "spell.hpp"
#include <vector>

#define MIDDLE_X 380
#define MIDDLE_y 300

class heap_card
{
    protected:
        std::vector<card_gen*> heap;
    public:
        virtual ~heap_card();
        void pop_card(card_gen* u);
        void suffle();//a faire(Noah)
        card_gen* pick_one();//fini
        void add_one( card_gen* nc);//a faire(Noah)
        card_gen *get_card_x(int n);
        size_t get_size(void);//a faire(Noah)
        virtual void render(sf::RenderWindow& window, bool hidden) = 0;
};


#endif