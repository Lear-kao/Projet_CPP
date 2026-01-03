#include <iostream>
#include "../HPP/game_controller.hpp"
#include "../HPP/player.hpp"
#include "../HPP/bot.hpp"
#include "../HPP/hand.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/board.hpp"
#include "../HPP/class_button.hpp"

unit* game_controller::clicked_attacker(sf::Vector2f mousePos)
{
    for(long unsigned int i = 0; i < list_fight.size(); i++) 
    {
        unit* card = list_fight[i].attacker;
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            select_blocker_target(card);
            return card;
        }
    }
    return nullptr;
}

void game_controller::selected_card_board(unit *u, player* p_clicked)
{
    if(p_clicked == current_player)
    {
        if(p_turn == phase_turn::selection_attacker)
        {
            select_attacker(u);
            p_clicked -> pop_from(BOARD,u);
        }
        return;
    }
    else
    {
        if(p_turn == phase_turn::main1 || p_turn == phase_turn::main2)
        {
            if(waiting_spell != nullptr)
            {
                target_spell = u;
            }
            return;
        }
        if(p_turn == phase_turn::selection_blocker)
        {
            select_blocker(u);
            return;
        }
    }
}

void game_controller::selected_card_hand(card_gen* card, player* p_clicked)
{
    if(p_clicked != current_player || 
        (p_turn != phase_turn::main1 && p_turn != phase_turn::main2))
        return;
    
    if(card->get_categorie() == "sort")
    { 
        spell_clicked((spell*)card);
        return;
    }
    if(card->get_categorie() == "unite")
    { 
        summon_unit((unit*)card);
        return;
    }
}

void game_controller::summon_unit(unit* casted)
{
    if(casted->get_cost() <= current_player->get_charge())
    {
        current_player->summon_card(casted);
        current_player->set_charge(current_player->get_charge()-casted->get_cost());
        current_player->pop_from(HAND,casted);
    }
}

void game_controller::spell_clicked(spell* casted )
{
    if(casted->get_classe() != "voleur")
    {
        std::cout << "here\n";
        current_player->cast_spell(casted, current_player);
    }
    waiting_spell = casted; 
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
    blocker = u;
}

void game_controller::select_blocker_target(unit* u)
{
    if(blocker == nullptr ) return;
    for(long unsigned int i = 0;  i < list_fight.size(); i++)
    {
        if(u == list_fight[i].attacker && list_fight[i].blocker == nullptr)
        {
            list_fight[i].blocker = blocker;
            waiting_player->pop_from(BOARD,blocker);
            blocker = nullptr;
        }
    }
}

void game_controller::resolve_fight()
{
    for( size_t i = 0; i < list_fight.size(); i++)
    {
        unit* t_unit = list_fight[i].blocker;
        unit* a_unit = list_fight[i].attacker;
        if(t_unit != nullptr)
        {
            int pv_attack = a_unit->get_stamina();
            int strenght_attack = a_unit->get_strenght();
            int pv_block = t_unit->get_stamina();
            int strenght_block = t_unit->get_strenght();

            if(a_unit->counter(t_unit)){
                pv_attack = pv_attack*2;
                strenght_attack = strenght_attack*2;
            }
            if(t_unit->counter(a_unit)){
                pv_block = pv_block*2;
                strenght_block = strenght_block*2;
            }

            //combat
            pv_attack-=strenght_block;

            pv_block-=strenght_attack; 

            if(pv_attack <= 0){
                a_unit->killed();
            }
            if(pv_block <= 0){
                t_unit->killed();
            }
            current_player->add_board(a_unit);
            waiting_player->add_board(t_unit);

        }
        else{
            unit* a_unit = list_fight[i].attacker;
            waiting_player->hitted(a_unit->get_strenght());
            current_player->add_board(a_unit);
        }
    }
    list_fight.clear();
    blocker = nullptr;
    return;
}

void game_controller::next_phase()
{
    switch (p_turn)
    {
        case phase_turn::draw: 
            //distribution des charges :            
            current_player->new_turn(get_current_charge());
            timer = 25.0;  
            p_turn = phase_turn::main1;
            break;
        case phase_turn::main1:
            p_turn = phase_turn::selection_attacker;
            timer = 25.0;
            target_spell = nullptr;
            waiting_spell = nullptr;
            break;

        case phase_turn::selection_attacker:
            if(list_fight.size() == 0)
            {
                p_turn = phase_turn::main2;
                timer = 25.0;
                break;
            }
            p_turn = phase_turn::selection_blocker;
            timer = 25.0;
            break;

        case phase_turn::selection_blocker:
            p_turn = phase_turn::main2;
            timer = 25.0;
            target_spell = nullptr;
            waiting_spell = nullptr;
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
            p_turn = phase_turn::draw;
            break;
    }
}

int game_controller::get_current_charge( void )
{
    int c_charge;
    if(tour_actuel%2==0)
    { //le joueur 2 joue quand le tour est pair
        c_charge =  tour_actuel/2;
    }
    else
    { //le joueur 1 joue quand le tour est impair donc on ajoute un après division
        c_charge = tour_actuel/2 + 1; 
    }
    if(c_charge > 8)
    { //max charge = 8
        c_charge = 8;
    }
    return c_charge;
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
    render_fight(window);
}

void game_controller::render_fight(sf::RenderWindow& window)
{
    for( long unsigned int i = 0; i < list_fight.size(); i++)
    {
        //affichage de l'attaquant
        list_fight[i].attacker->render(window,i*40+160,240);

        //affichage du defenseur
        unit* t_bl = list_fight[i].blocker;
        if(t_bl != nullptr)
        {
            t_bl->render(window, i*40+160, 310);
        }
    }
}

void game_controller::update(float delta)
{
    timer -= delta;
    if(current_player->is_bot() && p_turn !=  phase_turn::selection_blocker){
        bot* player_bot = (bot*) current_player;
        player_bot->add_to_think_bot(delta);
        if(player_bot->get_think_bot() >= 1){
            bot_turn();
            player_bot->reset_think();
        }
    }

    if(waiting_player->is_bot() && p_turn == phase_turn::selection_blocker){
        bot_play_blocker();
    }

    if( timer <= 0 )
    {
        next_phase();
    }
    if(target_spell != nullptr && waiting_spell != nullptr)
    {
        current_player->cast_spell(waiting_spell,target_spell);
        waiting_spell = nullptr;
        target_spell = nullptr;
    }
    current_player->update(delta);
    waiting_player->update(delta);
}

std::vector<fight> game_controller::get_current_attacker( void )
{
    return list_fight;
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
    affichage_timer.set_position(20,430);
    afficheur_de_phase.set_position(20,460);
}


void game_controller::bot_turn(){
    if(p_turn == phase_turn::main1 || p_turn == phase_turn::main2){
        bot_play_main();
    }

    if(p_turn == phase_turn::selection_attacker){
        bot_play_attacker();
    }   
}

void game_controller::bot_play_main(){
    int charge_min = current_player->charge_min_hand();
    while(current_player->get_charge() >= charge_min){
        for(size_t i = 0; i < current_player->get_player_hand_size() ; ++i){
            card_gen* current_card = current_player->get_card_from_hand(i);
            if(current_card->get_cost() == charge_min){
                if(current_card->get_categorie() == "sort"){
                    spell * casted = (spell*) current_card;
                    if(casted->get_classe() == "voleur" && waiting_player->get_player_board_size() == 0){
                        continue;
                    }
                    else{
                        spell_clicked(casted);
                        if(casted->get_classe() == "voleur"){
                            target_spell = (unit*) waiting_player->get_card_from_board(0);
                            current_player->cast_spell(waiting_spell,target_spell);
                            waiting_spell = nullptr;
                            target_spell = nullptr;
                        }
                    }
                }
                else{
                    unit* t_unit = (unit*) current_card;
                    summon_unit(t_unit);
                }
                charge_min = current_player->charge_min_hand();
                break;
            }
        }
    }
    next_phase();
}

void game_controller::bot_play_attacker(){
    size_t board_size = current_player->get_player_board_size();
    if(board_size!=0){
        for(size_t i = 0; i < board_size/2 +1;++i){
            unit* t_unit = (unit*) current_player->get_card_from_board(0); 
            selected_card_board(t_unit,current_player);
        }
    }
    next_phase();
}

void game_controller::bot_play_blocker(){
    for(size_t i =0 ; i < list_fight.size();++i){
        unit* t_attacker = list_fight[i].attacker;
        size_t board_size = waiting_player->get_player_board_size();
        for(size_t j =0 ; j < board_size ; ++j){
            unit* t_unit = (unit*) waiting_player->get_card_from_board(j);
            if(!t_unit->is_tapped()){
                bool attack_counter_block = t_attacker->counter(t_unit);
                bool block_counter_attacker = t_unit->counter(t_attacker);
                int blocker_stam = t_unit->get_stamina();
                int attacker_stam = t_attacker->get_stamina();
                
                //Le bot bloque avec cette créature seulement si les deux meurent 
                //ou si seulement la créature attaquante meurt
                if((block_counter_attacker && blocker_stam*2 >= attacker_stam) ||
                (!attack_counter_block && blocker_stam >= attacker_stam) ||
                (attack_counter_block && blocker_stam >= 2*attacker_stam)){
                    select_blocker(t_unit);
                    select_blocker_target(t_attacker);
                }
                break;
            }
        }
    }
    next_phase();
}