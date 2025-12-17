#include "../HPP/deck.hpp"
#include <fstream>

deck::deck(bool bot){
    std::ifstream f("../DOC/cards.txt");
    std::string chemin, categorie, classe;
    int charge;

    is_bot = bot;

    while(f >> chemin >> categorie >> classe >> charge) 
    //renvoie 4 s'il a bien lu 4 composantes,sinon ça veut dire que c'est la fin du fichier
    {
        if(categorie == "unite"){
            unit *u = new unit(charge);
            u->set_categorie(categorie);
            u->set_classe(classe);
            //u.set_sprite(chemin);
            heap.push_back(u);
        }
        else{
            spell *s = new spell(charge);
            s->set_categorie(categorie);
            s->set_classe(classe);
            //s.set_sprite(chemin);
            heap.push_back(s);
        }
    }
    texture.loadFromFile("../asset_lib_g/back_card.png");
    sprite.setTexture(texture);
    if(!bot) sprite.setPosition(20.0,20.0);
}

void deck::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}