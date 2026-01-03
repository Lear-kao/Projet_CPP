#ifndef HAND_HPP
#define HAND_HPP

#include "heap_card.hpp"

#define MAX_SIZE 8


/* 
Objectif : Implémenter la main du joueur pour le jeu de carte.
Entrée :
    - Un booléen qui nous indique si le propriétaire de la main est un bot ou non.

Cette classe hérite de la classe heap_card et donc de ses méthodes elle partage 
de nombreuse similarité avec la classe board mais ces méthodes sont différentes 
sur certains points particuliers.

Une voie d'amélioration de la classe serait d'agrandir l'arbre d'hérédité avec 
l'implémentation d'une classe intermédiaire entre heap_card et hand et dont la 
classe board hériterais aussi. Cette classe réunirait alors les points communs 
entre board et hand.
*/
class hand: public heap_card
{
    private:
        int border_x;
        int border_y;
    public:
        hand(bool is_bot);
        bool is_max_size(void);
        void render(sf::RenderWindow& window, bool hidden);
        void update( void );
        card_gen* play_one(int i);
};

#endif