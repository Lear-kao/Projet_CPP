#include "../HPP/class_button.hpp"

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void gen_button::set_loc(int x, int y)
{
    localisation.first = x;
    localisation.second = y;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
std::pair<int,int> gen_button::get_loc( void )
{
    return localisation;
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
void gen_button::render(sf::RenderWindow& window)
{
    sprite.setPosition(localisation.first, localisation.second);
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
gen_button::gen_button(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

/* 
Objectif :
Entrée :
    -
Sortie : 
    -
*/
sf::Sprite gen_button::get_sprite()
{
    return sprite;
}