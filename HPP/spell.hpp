#ifndef SPELL_HPP
#define SPELL_HPP

#include "card_gen.hpp"

class player;
class unit;

/*  
Objectif : Class hérité de card_gen représentanat les sorts lancés pendant la partie.
Point à améliorer, la manière dont les sorts de voleurs sont gérés est beaucoup trop contraignante
pour ajouter d'autres sorts.
*/
class spell: public card_gen
{
    private: 
        std::string target;
    public:
        spell(int v_e);
        virtual ~spell();
        void render(sf::RenderWindow& window, int x, int y, bool hidden);
        std::string type_target();
        void resolve(unit* current_target);
        void resolve(player* current_target);
};

#endif