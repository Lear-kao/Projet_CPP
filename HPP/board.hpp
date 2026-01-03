#ifndef BOARD_CLASS
#define BOARD_CLASS

#include "heap_card.hpp"

#define MAX_SIZE_BOARD 6


/* 
Objectif : Class hérité de heap card servant à représenter le terrain.
Point à améliorer, faire en sorte que le game controller puisse lui déléguer 
plus de tâche sur la gestion des unité à l'intérieur.
*/
class board: public heap_card
{
    private:
        int border_x;
        int border_y;
    public:
        board(bool is_bot);
        void render(sf::RenderWindow& window, bool hidden = false);
        void untap_all( void );
        bool check(std::string categorie);
        void update(void);
};

#endif