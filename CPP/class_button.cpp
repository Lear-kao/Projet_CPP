#include "../HPP/class_button.hpp"


/* 
Objectif : Constructeur de la classe button
Entrée :
    - Une chaine de charactère correspondant au chemin vers l'image du boutton.
Sortie : 
    - void
*/
gen_button::gen_button(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

/* 
Objectif : Afficher le bouton a la localisation en x, y.
Entrée :
    - L'objet sfml de la fenêtre.
Sortie : 
    - void
*/
void gen_button::render(sf::RenderWindow& window)
{
    sprite.setPosition(localisation.first, localisation.second);
    window.draw(sprite);
    return;
}

/* 
Objectif : Setter de la localisation x et y dans la fenêtre du boutton.
Entrée :
    - Deux entier x et y.
Sortie : 
    - void
*/
void gen_button::set_loc(int x, int y)
{
    localisation.first = x;
    localisation.second = y;
}

/* 
Objectif : Getter de le localisation x et y dans la fenêtre du boutton.
Entrée :
    - void
Sortie : 
    - Une pair x et y des entiers.
*/
std::pair<int,int> gen_button::get_loc( void )
{
    return localisation;
}

/* 
Objectif : Getter de l'objet de sfml sprite du boutton.
Entrée :
    - void
Sortie : 
    - L'objet de sfml sprite.
*/
sf::Sprite gen_button::get_sprite( void )
{
    return sprite;
}