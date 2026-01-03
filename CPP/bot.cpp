#include "../HPP/bot.hpp"

bot::bot() : player(true)
{
/* 
    Objectif : Constructeur de la classe bot héritée de player
    Entrée : 
        void
    Sortie :
        void
*/
    //Appelle le constructeur de player en mettant true pour préciser que c'est un bot
}

void bot::reset_think(){
    /* 
    Objectif : Reset le temps de réflexion du bot à 0
    Entrée : 
        void
    Sortie :
        void
    */
    think_bot = 0;
}

void bot::add_to_think_bot(float delta){
    /* 
    Objectif : Ajoute delta au temps de réflexion du bot 
    (delta étant le temps entre la dernière itération et la suivante)
    Entrée :
        float delta
    Sortie :
        void
    */
    think_bot+=delta;
}

float bot::get_think_bot(){
    /* 
    Objectif : Récupère le temps de réflexion du bot
    Entrée :
        void
    Sortie :
        float
    */
    return think_bot;
}