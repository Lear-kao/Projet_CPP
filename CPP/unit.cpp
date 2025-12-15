#include "../HPP/unit.hpp"


void unit::render(sf::RenderWindow& window, int x, int y)
{
    sprite.setPosition(x,y);
    window.draw(sprite);
    return;
}

int unit::get_strenght(void)
{
    return strenght;
}

int unit::get_stamina(void)
{
    return stamina;
}