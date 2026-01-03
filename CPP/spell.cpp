#include <iostream>
#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/player.hpp"


spell::spell(int v_e)
{
    set_cost(v_e);
}

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

void spell::resolve(unit* current_target)
{
    current_target->killed();
    return;
}

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

