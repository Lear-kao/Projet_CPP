#include "../HPP/game_controller.hpp"

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
            break;
        case phase_turn::main1:
            p_turn = phase_turn::fight;
            break;

        case phase_turn::fight:
            p_turn = phase_turn::main2;
            break;

        case phase_turn::main2:
            p_turn = phase_turn::end;
            break;

        case phase_turn::end:
            player *temp = current_player;
            current_player = waiting_player;
            waiting_player = temp;
            p_turn = phase_turn::draw;
            break;
    }
}