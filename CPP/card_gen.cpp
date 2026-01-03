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

void card_gen::set_sprite(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    
    texture_back.loadFromFile("assets_lib_g/back_card.png");
    sprite_back.setTexture(texture_back);
}

sf::Sprite card_gen::get_sprite(void)
{
    return sprite;
}

bool card_gen::counter(card_gen *ad){
    std::string classe_opposant = ad->get_classe();
    
    if(classe == "guerrier"){
        if(classe_opposant=="voleur"){
            return true;
        }
        return false;
    }
    else if(classe == "voleur"){
        if(classe_opposant=="mage"){
            return true;
        }
        return false;
    }
    else{
        if(classe_opposant=="guerrier"){
            return true;
        }
        return false;
    }
    
}

