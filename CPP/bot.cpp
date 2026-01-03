#include "../HPP/bot.hpp"

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
bot::bot() : player(true)
{
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void bot::reset_think(){
    think_bot = 0;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void bot::add_to_think_bot(float delta){
    think_bot+=delta;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
float bot::get_think_bot(){
    return think_bot;
}