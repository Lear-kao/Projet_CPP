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

        //lib_graphique
        void render();//affiche les cartes en fonction de leurs propres méthodes
};


#endif