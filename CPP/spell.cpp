#include "../HPP/spell.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/player.hpp"


void spell::render(sf::RenderWindow& window, int x, int y)
{
    sprite.setPosition(x,y);
    window.draw(sprite);
    return;
}


void spell::resolve(unit* current_target)
{
    if(target == "unit")
    {
        current_target->killed();
        return;
    }
}

void spell::resolve(player* current_target)
{
    if(target == "player")
    {
        current_target->healled(3);
        return;
    }
}