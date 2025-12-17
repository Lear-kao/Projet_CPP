#ifndef SPELL_HPP
#define SPELL_HPP

#include "card_gen.hpp"

class player;
class unit;

class spell: public card_gen
{
    private: 
        std::string target;
    public:
        spell(int v_e);
        void render(sf::RenderWindow& window, int x, int y);
        std::string type_target();
        void resolve(unit* current_target);
        void resolve(player* current_target);
};

#endif