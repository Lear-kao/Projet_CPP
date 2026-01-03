#ifndef DECK_HPP
#define DECK_HPP

#include "heap_card.hpp"

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