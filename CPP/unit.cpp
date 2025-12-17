#include "../HPP/unit.hpp"

unit::unit(int cost){
    cost = cost;
}

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

void unit::tap(void)
{
    tapped = true;
}

void unit::untap(void)
{
    tapped = false;
}

bool unit::is_tapped(void)
{
    return tapped;
}

void unit::killed(void)
{
    alive = false;
}