#include "../HPP/card_gen.hpp"


/* 
Toute les fonctions de mise en place de l'objet
Méthode lourde mais explicite (voir si on fait differemment)
*/
void card_gen::render(sf::RenderWindow& window, int x, int y)
{
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    window.draw(sprite);
    return;
}

void card_gen::set_categorie(std::string c)
{
    categorie = c;
}

void card_gen::set_cost(int c)
{
    cost = c;
}


void card_gen::set_classe(std::string c)
{
    classe = c;
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

