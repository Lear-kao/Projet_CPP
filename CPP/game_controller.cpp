#include "../HPP/game_controller.hpp"
#include "../HPP/player.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/class_button.hpp"




void game_controller::selected_card_board(unit *u)
{
    if(u->is_tapped()) return;
    if(p_turn == phase_turn::fight)
    {
        if(p_fight == phase_fight::selection_attacker)
        {
            if(u->is_tapped()) 
                return;
            select_attacker(u);
        }
        if(p_fight == phase_fight::selection_blocker)
        {
            if(u->is_tapped()) 
                return;
            select_blocker(u);
        }
        return;
    }
    waiting_spell->resolve(u);
}

void game_controller::select_attacker(unit* u)
{
    attacker = u;
}

void game_controller::select_blocker(unit* u)
{
    blocker = u;
}

void game_controller::resolve_fight()
{
    if(blocker == NULL)
    {
        waiting_player->hitted(attacker->get_strenght());
        return ;
    }
    if(attacker->get_strenght() >= blocker->get_stamina()) blocker->killed();
    if( blocker -> get_strenght() >= attacker->get_stamina()) attacker->killed();
    attacker->tap();
    return;
}

void game_controller::selected_card_hand(card_gen* card)
{
    if (p_turn != phase_turn::main1 && p_turn != phase_turn::main2) return;

    if(card->get_categorie() == "sort")
    { 
        spell* u_cp = (spell*)card;
        /* 
        Lance le sort
        si une target est necessaire, attendre la target
        sinon, résoudre le sort pour le joueur qui le lance
        */
        return;
    }
    if(card->get_categorie() == "unite")
    { 
        unit* s_cp = (unit*)card;
        /* 
        pose l'unité sur le board
        */
        return;
    }
}

void game_controller::next_phase()
{
    switch (p_turn)
    {
        case phase_turn::draw:
            current_player->draw_card();
            p_turn = phase_turn::main1;
            printf("darw\n");
            break;
        case phase_turn::main1:
            p_turn = phase_turn::fight;
            printf("main1\n");
            break;

        case phase_turn::fight:
            p_turn = phase_turn::main2;
            printf("fight\n");
            break;

        case phase_turn::main2:
            p_turn = phase_turn::end;
            printf("main2\n");
            break;

        case phase_turn::end:
            /* player *temp = current_player;
            current_player = waiting_player;
            waiting_player = temp; */
            p_turn = phase_turn::draw;
            printf("end\n");
            break;
    }
}

void game_controller::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets_lib_g/arial.ttf")){
        return;
    }  
    sf::Text text;
    text.setFont(font);
    std::string text_aff;
    switch(p_turn)
    {
        case phase_turn::draw:
            text_aff.append("draw");
            break;
        case phase_turn::main1:
            text_aff.append("main");
            break;

        case phase_turn::fight:
            text_aff.append("fight");
            break;

        case phase_turn::main2:
            text_aff.append("main");
            break;

        case phase_turn::end:
            text_aff.append("end");
            break; 
    }
    text.setString(text_aff);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(20.f, 300.f);
    
    // ligne magique 👇
    window.draw(text);

}

game_controller::game_controller(player *p1,player *p2)
{
    if(p1 != nullptr)
    {
        current_player = p1;
    }
    if(p2 != nullptr)
    {
        waiting_player = p2;
    }
}