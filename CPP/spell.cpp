#include "../HPP/spell.hpp"


void spell::render(sf::RenderWindow& window, int x, int y)
{
    sprite.setPosition(x,y);
    window.draw(sprite);
    return;
}

void resolve(auto *target)
{
    if(target == "player")
    {
        player *temp = (player*) target;
        if(get_classe() == "guerrier")
        {
            player->healled(3);
        }
        temp->
    }
}