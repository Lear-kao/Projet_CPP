#include <iostream>
#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/player.hpp"

/* 
Objectif : Constructeur de la class spell hérité de card_gen.
Entrée :
    - Un entier représentant le coût en charge.
Sortie : 
    - void
*/
spell::spell( int v_e )
{
    set_cost(v_e);
}

/* 
Objectif : Afficher la carte à la position x,y ou bien de dos ou bien de face.
Entrée :
    - 2 entiers x et y.
    - Un booléen indiquant si la carte est face cachée.
    - L'objet sfml représentant la fenêtre.
Sortie : 
    - void
*/
void spell::render(sf::RenderWindow& window, int x, int y, bool hidden)
{
    if(hidden)
    {
        sprite_back.setPosition(x,y);
        window.draw(sprite_back);
        return;
    }
    
    sprite.setPosition(x,y);
    window.draw(sprite);
    return;
}

/* 
Objectif : Méthode suchargée en fonction de quelle cible est désignée pour le sort. Ici une unité ennemie.
Entrée :
    - Un pointeur vers une unité ennemie.
Sortie : 
    - void
*/
void spell::resolve(unit* current_target)
{
    current_target->killed();
    return;
}

/* 
Objectif :  Méthode suchargée en fonction de quelle cible est désignée pour le sort. Ici le joueur ayant lancé le sort.
Entrée :
    - Un pointeur vers le joueur ayaent lancé le sort.
Sortie : 
    - void
*/
void spell::resolve(player* current_target)
{
    if(get_classe() == "guerrier")
    {
        current_target->healled(3);
        return;
    }
    else if( get_classe() == "mage")
    {
        current_target->draw_card();
        current_target->draw_card();
        current_target->draw_card();
    }
}

