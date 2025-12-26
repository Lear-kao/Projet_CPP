#include "../HPP/unit.hpp"

unit::unit(int cost){
    set_cost(cost);
    strenght = cost;
    stamina = cost;
}

void unit::render(sf::RenderWindow& window, int x, int y)
{
    if(is_tapped()) sprite.setRotation(35.f);
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