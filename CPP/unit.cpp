#include "../HPP/unit.hpp"

/* 
Objectif : Constructeur de la class unit hérité de card_gen.
Entrée :
    - Un entier représentant a la fois le coût en charge et la force/endurance.
Sortie : 
    - void
*/
unit::unit( int cost )
{
    set_cost(cost);
    strenght = cost;
    stamina = cost;
}

unit::~unit( void )
{
    
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
void unit::render( sf::RenderWindow& window, int x, int y, bool hidden )
{
    if(hidden)
    {
        //affiche de dos si demandé.
        sprite_back.setPosition(x,y);
        window.draw(sprite_back);
        return;
    }
    //change l'orientation de la carte si elle est engagée.
    if(is_tapped())
        sprite.setRotation(15.0);
    else 
        sprite.setRotation(0.0);

    sprite.setPosition(x,y);
    window.draw(sprite);
    return;
}

/* 
Objectif : Renvoie la force de la créature.
Entrée :
    - void
Sortie : 
    - Un entier.
*/
int unit::get_strenght( void )
{
    return strenght;
}

/* 
Objectif : Renvoie l'endurance de la créature.
Entrée :
    - void
Sortie : 
    - Un entier.
*/
int unit::get_stamina( void )
{
    return stamina;
}

/* 
Objectif : Engage la créature.
Entrée :
    - void
Sortie : 
    - void
*/
void unit::tap( void )
{
    tapped = true;
}

/* 
Objectif : Désengage la créature.
Entrée :
    - void
Sortie : 
    - void
*/
void unit::untap( void )
{
    tapped = false;
}

/* 
Objectif : Renvoie true si l'unité est engagée.
Entrée :
    - void
Sortie : 
    - Un booléen.
*/
bool unit::is_tapped( void )
{
    return tapped;
}

/* 
Objectif : Enregistre que l'unité a été tuée pour le prochain update().
Entrée :
    - void
Sortie : 
    - void
*/
void unit::killed( void )
{
    alive = false;
}

/* 
Objectif : Renvoie true si l'unité a été tuée.
Entrée :
    - void
Sortie : 
    - Un booléen.
*/
bool unit::is_dead( void )
{
    return !alive;
}