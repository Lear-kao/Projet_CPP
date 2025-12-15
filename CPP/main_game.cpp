#include "../HPP/main_game.hpp"
#include <SFML/Graphics.hpp>

void main_game::render( sf::RenderWindow& window)
{
    sf::Texture texture;
    texture.loadFromFile("/home/axel/Projet_CPP/assets_lib_g/maison.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(100, 100);
    window.draw(sprite);
}

void main_game::update()
{
    return;
}