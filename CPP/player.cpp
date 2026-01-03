#include <iostream>
#include <string.h>
#include "player.hpp"
#include "card_gen.hpp"
#include "hand.hpp"
#include "board.hpp"
#include "deck.hpp"
#include "unit.hpp"
#include "spell.hpp"





/* 
Objectif : Constructeur de la class player.
Entrée :
    - Un booléen indiquant si il s'agit d'un bot ou non.
Sortie : 
    - void
*/
player::player( bool bot )
{
    hand_player = new hand(bot);
    deck_player = new deck(bot);
    board_player = new board(bot);

    for( int i = 0; i< 5; i ++)
    {
        hand_player->add_one(deck_player->pick_one());
    }
    if(bot)
    {
        UI_charge.set_position(40, 80);
        UI_life.set_position(50,30);
    }
    else
    {
        UI_charge.set_position(750, 500);
        UI_life.set_position(720,550);
    }
}

player::~player( void )
{
    delete deck_player;
    delete hand_player;
    delete board_player;
}

/* 
Objectif : Afficher la main.
Entrée :
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void player::render_hand( sf::RenderWindow& window )
{
    hand_player->render(window,is_bot());
}

/* 
Objectif : Afficher le terrain.
Entrée :
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void player::render_board( sf::RenderWindow& window )
{
    board_player->render(window);
}

/* 
Objectif : Afficher le deck.
Entrée :
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void player::render_deck( sf::RenderWindow& window )
{
    deck_player->render(window);
}

/* 
Objectif : Affciher le nombre de point de vie possédé par le joueur.
Entrée :
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void player::render_life( sf::RenderWindow& window )
{
    UI_life.render(std::to_string(life),window);
}

/* 
Objectif : Afficher le nombre de charge possédé par le joueur.
Entrée :
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void player::render_charge( sf::RenderWindow& window )
{
    UI_charge.render(std::to_string(charge),window);
}

/* 
Objectif : Afficher les différents elements appartenant au joueur.
Entrée :
    - L'objet sfml correspondant à la fenêtre.
Sortie : 
    - void
*/
void player::render_general( sf::RenderWindow& window )
{
    render_charge(window);
    render_deck(window);
    render_hand(window);
    render_board(window);
    render_life(window);
}

/* 
Objectif : Signaler au joueur qu'il commence un nouveau tour.
Entrée :
    - Un entier représentant le nombre de charge qu'il possède.
Sortie : 
    - void
*/
void player::new_turn( int n_charge )
{
    draw_card();
    board_player->untap_all();
    charge = n_charge;
}

/* 
Objectif : Enlever une carte appartenant a un objet board ou hand de celui-ci.
Entrée :
    - Un entier defined dans le hpp correspondant à BOARD ou HAND.
    - Un pointeur vers une carte.
Sortie : 
    - void
*/
void player::pop_from( int from, card_gen* who )
{
    if(from == HAND)
    {
        hand_player->pop_card(who);
    }
    else if(from == BOARD)
    {
        board_player->pop_card(who);
    }
}

/* 
Objectif : Récupérer le nombre de carte dans la main du joueur.
Entrée :
    - void
Sortie :  
    - Un size_t (long unsigned int)
*/
size_t player::get_player_hand_size( void )
{
    return hand_player->get_size();
}

/* 
Objectif : Récupérer la carte à l'emplacement i de la main du joueur.
Entrée :
    - Un entier.
Sortie : 
    - Un pointeur sur une carte.
*/
card_gen* player::get_card_from_hand( int i )
{
    return hand_player->get_card_x(i);
}

/* 
Objectif : Récupérer le nombre d'unité que le joueur possède sur le terrain.
Entrée :
    - void
Sortie : 
    - Un size_t (long unsigned int)
*/
size_t player::get_player_board_size( void )
{
    return board_player->get_size();
}

/* 
Objectif : Récupérer la carte à l'emplacement i du terrain.
Entrée :
    - Un entier i.
Sortie : 
    - Un pointeur vers une carte.
*/
card_gen* player::get_card_from_board( int i )
{
    return board_player->get_card_x(i);
}

/*
Objectif : Demander au joueur de piocher une carte.
Entrée :
    - void
Sortie : 
    - void
*/
void player::draw_card( void )
{
    hand_player -> add_one(deck_player->pick_one());
    return;
}

/* 
Objectif : Signaler au joueur qu'il a gagné de la vie.
Entrée : 
    - Un entier.
Sortie : 
    - void
*/
void player::healled(int heal)
{
    life += heal;
}

/* 
Objectif : Signaler au joueur qu'il a perdu des points de vie.
Entrée :
    - Un entier.
Sortie : 
    - void
*/
void player::hitted(int damage)
{
    life -= damage;
}

/* 
Objectif : Invoquer une créature sur le terrain.
Entrée :
    -
Sortie : 
    -
*/
void player::summon_card(unit* unite)
{
    board_player->add_one(unite);
}

/* 
Objectif : Lancer le sort passé en paramètre sur l'unité aussi passée en paramètre.
Entrée :
    - Une carte de sort.
    - Une unité.
Sortie : 
    - void
*/
void player::cast_spell(spell* casted, unit* target)
{
    std::string classe = casted->get_classe();
    int cout_reel = casted->get_cost();
    if(board_player->check(classe) == true)
    {
        cout_reel = 1;
    }
    if( charge >= cout_reel)
    {
        casted->resolve(target);
        set_charge(charge-cout_reel);
        pop_from(HAND,(card_gen*)casted);
    }
}

/* 
Objectif : Lancer le sort passé en paramètre sur le joueur aussi passé en paramètre.
Entrée :
    - Une carte de sort.
    - Un joueur.
Sortie : 
    - void
*/
void player::cast_spell(spell* casted, player* target)
{
    std::string classe = casted->get_classe();
    int cout_reel = casted->get_cost();
    if(board_player->check(classe) == true)
    {
        cout_reel = 1;
    }
    if( charge >= cout_reel)
    {
        casted->resolve(target);
        set_charge(charge-cout_reel);
        pop_from(HAND,(card_gen*)casted);
    }
}

/* 
Objectif : Assigner la valeur c à la variable charge.
Entrée :
    - Un entier.
Sortie : 
    - void
*/
void player::set_charge(int c)
{
    charge = c;
}

/* 
Objectif : Renvoie combien de charge possède le joueur.
Entrée :
    - void
Sortie : 
    - Un entier.
*/
int player::get_charge( void )
{
    return charge;
}

/* 
Objectif : Récupérer les points de vie du joueur.
Entrée :
    - void
Sortie : 
    - Un entier.
*/
int player::get_pv( void )
{
    return life;
}

/* 
Objectif : Renvoyer la carte sur laquelle le joueur a cliqué si il a cliqué sur une carte de son terrain.
Entrée :
    - La position ou la souris a cliqué grâce à un objet sfml.
Sortie : 
    - Une carte.
*/
unit* player::card_clicked_board(sf::Vector2f mousePos)
{
    for( long unsigned int i = 0; i < board_player->get_size(); i++) 
    {
        unit* card = (unit*)board_player->get_card_x(i);
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            return card;
        }
    }
    return nullptr;
}

/* 
Objectif : Renvoyer la carte sur laquelle le joueur a cliqué si il a cliqué sur une carte de sa main.
Entrée :
    - La position ou la souris a cliqué grâce à un objet sfml.
Sortie : 
    - Une carte.
*/
card_gen* player::card_clicked_hand(sf::Vector2f mousePos)
{
    for( long unsigned int i = 0; i < hand_player->get_size(); i++) 
    {
        card_gen* card = hand_player->get_card_x(i);
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            return card;
        }
    }
    return nullptr;
}

/* 
Objectif : Renvoie si le joueur est mort ou non.
Entrée :
    - void
Sortie : 
    - Un booléen.
*/
bool player::is_dead( void )
{
    if( life <= 0 ) return true;
    return false;
}

/* 
Objectif : méthode appellé à chaque tic qui sert a executer les méthodes devant être activée automatiquement.
Entrée :
    - Un flotant delta indiquant le temps écoulé depuis la dernière itération.
Sortie :
    - void
*/
void player::update( [[maybe_unused]] float delta )
{
    hand_player->update();
    board_player->update();
}