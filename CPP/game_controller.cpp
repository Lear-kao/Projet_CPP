#include "../HPP/game_controller.hpp"

void game_controller::selected_card_board(unit *u)
{
    if(p_turn != phase_turn::fight) return;
    if(p_fight == phase_fight::selection_attacker){select_attacker(u);}
    if(p_fight == phase_fight::selection_attacker){select_blocker(u);}
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
}