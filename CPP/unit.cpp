#include "../HPP/unit.hpp"

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
unit::unit(int cost){
    set_cost(cost);
    strenght = cost;
    stamina = cost;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void unit::render(sf::RenderWindow& window, int x, int y, bool hidden)
{
    if(hidden)
    {
        sprite_back.setPosition(x,y);
        window.draw(sprite_back);
        return;
    }
    
    if(is_tapped()) 
        sprite.setRotation(15.0);
    else 
        sprite.setRotation(0.0);

    sprite.setPosition(x,y);
    window.draw(sprite);
    return;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
int unit::get_strenght(void)
{
    return strenght;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
int unit::get_stamina(void)
{
    return stamina;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void unit::tap(void)
{
    tapped = true;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void unit::untap(void)
{
    tapped = false;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
bool unit::is_tapped(void)
{
    return tapped;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void unit::killed(void)
{
    alive = false;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
bool unit::is_dead(void)
{
    return !alive;
}