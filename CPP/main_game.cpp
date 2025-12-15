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


void main_game::next_phase()
{
    switch (phase_game)
    {
        case Phase_turn::Draw:
            m_player.draw_card();
            phase_game = Phase_turn::main1;
            break;

        case Phase_turn::main1:
            phase_game = Phase_turn::fight;
            break;

        case Phase_turn::fight:
            phase_game = Phase_turn::main2;
            break;

        case Phas_turn::main2:
            phase_game = Phase_turn::end;
            break;

        case Phase_turn::end:
            phase_game = Phase_turn::Draw;
            break;
    }
}

bool mmain_game::canPlayCard(){
    return phase_game == Phase::main1 || phase_game == Phase::Main2;
}

bool mmain_game::canfight(){
    return phase_game == Phase::fight;
}


void main_game::update()
{
    return;
}