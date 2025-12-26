#include "../HPP/game_controller.hpp"
#include "../HPP/player.hpp"
#include "../HPP/hand.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/board.hpp"
#include "../HPP/class_button.hpp"


bool game_controller::s_is_blocking(void)
{
    if(blocker) return true;
    return false;
}

player* game_controller::get_current_player( void )
{
    return current_player;
}

phase_turn game_controller::get_current_phase( void )
{
    return p_turn;
}

void game_controller::selected_card_board(unit *u)
{
    if(p_turn == phase_turn::selection_attacker)
    {
        select_attacker(u);
    }
    if(p_turn == phase_turn::selection_blocker)
    {
        if(blocker == nullptr)
        {
            select_blocker(u);
        }
        else select_blocker_target(u);
    }
    /* if(p_turn == phase_turn::main1 || p_turn == phase_turn::main2)
    {
        waiting_spell->resolve(u);
    } */
    return;
    
}

void game_controller::select_attacker(unit* u)
{
    /* 
    !!! attention, faire en sorte que un joueur ne puisse pas séléctionner les unitées du joueur adverse
    */
    if(u->is_tapped())return;
    u->tap();
    list_fight.push_back({u,nullptr});
}

void game_controller::select_blocker(unit* u)
{
    /* 
    !!! attention, faire en sorte que un joueur ne puisse pas séléctionner les unitées du joueur adverse
    */
    if(u->is_tapped())return;
    blocker = u;
}

void game_controller::select_blocker_target(unit* u)
{

    for( int i = 0;  i < list_fight.size(); i++)
    {
        if(u == list_fight[i].attacker)
        {
            list_fight[i].blocker = blocker;
            blocker = nullptr;
        }
    }
}

void game_controller::resolve_fight()
{
    for( int i = 0; i < list_fight.size(); i++)
    {
        if(list_fight[i].blocker == nullptr)
        {
            waiting_player->hitted(list_fight[i].attacker->get_strenght());
        }
    }
    /* 
    faire se combattre les créatures avec le counter à faire
    */
    list_fight.clear();
    blocker = nullptr;
    return;
}

void game_controller::selected_card_hand(int i)
{
    if (p_turn != phase_turn::main1 && p_turn != phase_turn::main2) return;

    auto* hand = current_player->get_hand();
    auto* card = hand->get_card_x(i);

    if(card->get_categorie() == "sort")
    { 
        spell* u_cp = (spell*)card;
        int cout_reel = card->get_cost();
        board* b = current_player->get_board();
        if(u_cp->get_classe() == "guerrier" )
        {
            if(b->check("guerrier") == true){
                cout_reel = 1;
            }
            if(current_player->get_charge()>=cout_reel){
                u_cp->resolve(current_player);
                current_player->set_charge(current_player->get_charge()-cout_reel);
                hand->pop_i(i);
            }
        }
        else if(u_cp->get_classe()=="mage"){
            if(b->check("mage")==true){
                cout_reel = 1;
            }
            if(current_player->get_charge()>=cout_reel){
                u_cp->resolve(current_player);
                current_player->set_charge(current_player->get_charge()-cout_reel);
                hand->pop_i(i);
            }
        }
        else{
            if(b->check("voleur")){
                cout_reel = 1;
            }
            if(current_player->get_charge()>=cout_reel){
                current_player->set_charge(current_player->get_charge()-cout_reel);
                hand->pop_i(i);
            }
        }
    }
    if(card->get_categorie() == "unite")
    { 
        if(card->get_cost() <= current_player->get_charge()){
            unit* s_cp = (unit*)card;
            current_player->summon_card(s_cp);
            current_player->set_charge(current_player->get_charge()-card->get_cost());
            hand->pop_i(i);
        }
    }
}

void game_controller::next_phase()
{
    switch (p_turn)
    {
        case phase_turn::draw: 
            //distribution des charges :
            if(tour_actuel%2==0){ //le joueur 2 joue quand le tour est pair
                current_player->set_charge(tour_actuel/2);
            }
            else{ //le joueur 1 joue quand le tour est impair donc on ajoute un après division
                current_player->set_charge(tour_actuel/2 + 1); 
            }
            if(current_player->get_charge() > 8){ //max charge = 8
                current_player->set_charge(8);
            }
            current_player->draw_card();
            timer = 25.0;  
            p_turn = phase_turn::main1;
            break;
        case phase_turn::main1:
            p_turn = phase_turn::selection_attacker;
            timer = 25.0;
            break;

        case phase_turn::selection_attacker:
            p_turn = phase_turn::selection_blocker;
            timer = 25.0;
            break;

        case phase_turn::selection_blocker:
            p_turn = phase_turn::main2;
            timer = 25.0;
            printf("ouch\n");
            resolve_fight();
            break;

        case phase_turn::main2:
            timer = 0.0;
            p_turn = phase_turn::end;
            break;

        case phase_turn::end:
            timer = 0.0;
            player *temp = current_player;
            current_player = waiting_player;
            waiting_player = temp;
            tour_actuel++;
            current_player->get_board()->untap_all();
            p_turn = phase_turn::draw;
            break;
    }
}

void game_controller::render(sf::RenderWindow& window)
{
    std::string text_aff;
    switch(p_turn)
    {
        case phase_turn::draw:
            text_aff.append("draw");
            break;
        case phase_turn::main1:
            text_aff.append("main");
            break;

        case phase_turn::selection_attacker:
            text_aff.append("select_attacker");
            break;

        case phase_turn::selection_blocker:
            text_aff.append("select_blocker");
            break;

        case phase_turn::main2:
            text_aff.append("main");
            break;

        case phase_turn::end:
            text_aff.append("end");
            break; 
    }
    afficheur_de_phase.render(text_aff,window);

    std::string text_aff2 = std::to_string((int)timer);
    affichage_timer.render(text_aff2,window);
}

void game_controller::update(float delta)
{
    timer -= delta;
    if( timer <= 0 )
    {
        next_phase();
    }
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
    affichage_timer.set_position(20,350);
    afficheur_de_phase.set_position(20,300);
}