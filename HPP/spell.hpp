#ifndef SPELL_HPP
#define SPELL_HPP

#include "card_gen.hpp"
#include "../HPP/player.hpp"

class spell: public card_gen
{
    private: 
        std::string target;
    public:
        spell(int v_e);
        void render(sf::RenderWindow& window, int x, int y);
        std::string type_target();
        void resolve(auto target);
};

#endif