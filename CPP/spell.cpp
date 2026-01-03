#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/player.hpp"

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
spell::spell(int v_e)
{
    set_cost(v_e);
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void spell::render(sf::RenderWindow& window, int x, int y)
=======
=======
>>>>>>> Stashed changes
/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void spell::render(sf::RenderWindow& window, int x, int y, bool hidden)
>>>>>>> Stashed changes
{
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
void spell::resolve(unit* current_target)
{
    current_target->killed();
    return;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
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

