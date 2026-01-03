#include "../HPP/bot.hpp"
#include "../HPP/card_gen.hpp"

/* 
Objectif : COnstructeur de la class bot.
Entrée :
    - void
Sortie : 
    - void
*/
bot::bot( void ) : player(true)
{//appelle simplement le contructeur de player avec true pour indiquer qu'il s'agit d'un bot.
}

/* 
Objectif : Redémarre le timer qui indique que le bot réfléchis.
Entrée :
    - void
Sortie : 
    - void
*/
void bot::reset_think( void )
{
    think_bot = 0;
}

/* 
Objectif : Soustraie delta au timer de reflexion du bot pour simuler la reflexion du bot.
Entrée :
    - Un flotant delta correspondant au temps depuis la dernière itération. 
Sortie : 
    - void
*/
void bot::add_to_think_bot( float delta )
{
    think_bot+=delta;
}

/* 
Objectif : Retourne ou en est le timer de reflexion du bot.
Entrée :
    - void 
Sortie : 
    - Un flotant.
*/
float bot::get_think_bot( void )
{
    return think_bot;
}

/* 
Objectif : 
Entrée :
    -
Sortie : 
    - 
*/
int bot::charge_min_hand( void )
{
    int charge_min = 10;
    for(size_t i = 0; i < get_player_hand_size() ; ++i)
    {
        card_gen * card = get_card_from_hand(i);
        if(card->get_cost() < charge_min)
        {
            charge_min = card->get_cost();
        }
    }
    return charge_min;
}