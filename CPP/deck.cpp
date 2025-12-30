#include "../HPP/deck.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>

deck::deck(bool bot) : is_bot(bot)
{
    std::ifstream f("DOC/cards.txt");

    std::string chemin, categorie, classe;
    int charge;

    while (f >> chemin >> categorie >> classe >> charge)
    {
        card_gen* c = nullptr;

        if (categorie == "unite")
            c = new unit(charge);
        else
            c = new spell(charge);

        c->set_categorie(categorie);
        c->set_classe(classe);
        c->set_sprite(chemin);

        heap.push_back(c);
    }
    shuffle();

    if (!texture.loadFromFile("assets_lib_g/back_card.png"))
        throw std::runtime_error("texture back_card manquante");

    sprite.setTexture(texture);
    if (!is_bot)
        sprite.setPosition(128, 515);
    else
    {
        sprite.setPosition(631, 20);
    }
}


void deck::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void deck::shuffle( void )
{
    std::mt19937 rng{std::random_device{}()};
    std::shuffle(heap.begin(),heap.end(),rng);
}