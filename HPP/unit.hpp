#ifndef UNIT_HPP
#define UNIT_HPP
#include "card_gen.hpp"

class unit: public card_gen
{
    private: 
        int strenght;
        int stamina;
        bool tapped = false;
        bool alive = true;
    public:
        unit(int cost);
        void tap( void ); //engage l'unitée
        void untap(void); //désengage l'unitée
        bool is_tapped( void ); //vérifie si l'unité est tappée
        int get_strenght(void); //fait
        int get_stamina(void); //fait
        void render(sf::RenderWindow& window, int x, int y);
        void killed( void ); //!!! cette fonction ne tue pas imédiatement la carte, elle doit être supprimé au prochain update() du board
};

#endif
