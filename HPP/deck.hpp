#ifndef DECK_HPP
#define DECK_HPP

#include "heap_card.hpp"

/* 
Objectif : Class hérité de heap_card représentant le deck du joueur.
Point à améliorer, faire en sorte d'avoir moins de méthode "hardcodé" avec de permettre une
utilisation plus modulaire.
*/
class deck : public heap_card
{
    private:
        int number_card;
        sf::Sprite sprite;
        sf::Texture texture;
        bool is_bot;
    public:
        deck(bool bot);
        void shuffle(void);
        void render(sf::RenderWindow& window, bool hidden = false);
};

#endif