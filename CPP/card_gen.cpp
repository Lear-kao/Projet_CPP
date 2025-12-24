#include "../HPP/card_gen.hpp"


/* 
Toute les fonctions de mise en place de l'objet
Méthode lourde mais explicite (voir si on fait differemment)
*/

void card_gen::set_categorie(std::string c)
{
    categorie = c;
}

std::string card_gen::get_categorie(void)
{
    return categorie;
}

void card_gen::set_cost(int c)
{
    cost = c;
}

int card_gen::get_cost()
{
    return cost;
}


void card_gen::set_classe(std::string c)
{
    classe = c;
}

std::string card_gen::get_classe(void)
{
    return classe;
}

void card_gen::set_name(std::string n)
{
    name = n;
}




/* 
fonction pur la mise en place de l'apparence graphique, 
seul point vraiment sensible de cette partie 
*/
void card_gen::set_sprite(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

sf::Sprite card_gen::get_sprite(void)
{
    return sprite;
}



