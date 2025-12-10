#ifndef HEAP_CARD
#define HEAP_CARD

#include <SFML/Graphics.hpp>
#include "card_gen.hpp"
#include <vector>

class heap_card
{
    private:
        std::vector<card_gen*> heap;
    public:
        heap_card(); //récupère depuis un fichier texte chaque carte
        void suffle(); //mélange les cartes
        card_gen* pick_one(); //pioche une carte
        std::vector<heap_card*> divide(); //coupe le paquet en 2
        void add_one( card_gen* nc);
        int get_size(void);
};


#endif