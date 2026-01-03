#include <iostream>
#include "../HPP/game_controller.hpp"
#include "../HPP/player.hpp"
#include "../HPP/bot.hpp"
#include "../HPP/hand.hpp"
#include "../HPP/unit.hpp"
#include "../HPP/spell.hpp"
#include "../HPP/board.hpp"
#include "../HPP/class_button.hpp"

/* 
Objectif : Constructeur de la class game_controller.
Entrée :
    - Des pointeurs vers les objets représentants les 2 joueurs.
Sortie : 
    - void
*/
game_controller::game_controller( player *p1,player *p2 )
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

/* 
Objectif : Afficher les elements propre au game controller tel que la phase du tour, le timer ou les combats pendant le tour.
Entrée :
    - L'objet sfml de la fenêtre.
Sortie : 
    - void
*/
void game_controller::render( sf::RenderWindow& window )
{
    //création du texte en fonction de la phase
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

    //affiche le timer
    std::string text_aff2 = std::to_string((int)timer);
    affichage_timer.render(text_aff2,window);
    //afficher les combattants
    render_fight(window);
}

/* 
Objectif : Afficher les différentes unités présente dans que ce soit attaquant ou bloqueurs les uns en face des autres
        en fonction de qui bloque qui.
Entrée :
    - L'objet sfml de la fenêtre.
Sortie : 
    - void
*/
void game_controller::render_fight( sf::RenderWindow& window )
{
    for( long unsigned int i = 0; i < list_fight.size(); i++)
    {
        //affichage de l'attaquant
        list_fight[i].attacker->render(window,i*40+160,215, false);

        //affichage du defenseur
        unit* t_bl = list_fight[i].blocker;
        if(t_bl != nullptr)
        {
            t_bl->render(window, i*40+160, 310, false);
        }
    }
}

/* 
Objectif : Détecte en fonction d'un vecteur si un attaquant a été cliqué et agis en fonction.
Entrée :
    - Un vecteur de 2 flotants propre à sfml.
Sortie : 
    - void
*/
void game_controller::clicked_attacker( sf::Vector2f mousePos )
{
    for(long unsigned int i = 0; i < list_fight.size(); i++) 
    {
        unit* card = list_fight[i].attacker;
        if(card->get_sprite().getGlobalBounds().contains(mousePos))
        {
            if(blocker == nullptr) return;
            select_blocker_target(card);
            return ;
        }
    }
    return ;
}

/* 
Objectif : Reçois une unité et un joueur et en fonction de la phase du jeu agit différement.
Entrée :
    - Un pointeur vers une unitée.
    - Un pointeur vers un joueur.
Sortie : 
    - void
*/
void game_controller::selected_card_board( unit *u, player* p_clicked )
{

    if(p_clicked == current_player)
    {
        if(p_turn == phase_turn::selection_attacker)
        {
            //si les conditions si dessus sont remplies le joueur attaque avec l'unité appellée.
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
                //si les conditions si dessus sont remplies le joueur lance un sort.
                target_spell = u;
            }
            return;
        }
        if(p_turn == phase_turn::selection_blocker)
        {
            //si les conditions si dessus sont remplies le joueur attaqué selectionne quel unité bloque.
            select_blocker(u);
            return;
        }
    }
}

/* 
Objectif : Reçois une carte et un joueur et en fonction de la phase du jeu agit différement.
Entrée :
    - Un pointeur vers une unitée.
    - Un pointeur vers un joueur.
Sortie : 
    - void
*/
void game_controller::selected_card_hand( card_gen* card, player* p_clicked )
{
    if(p_clicked != current_player || 
        (p_turn != phase_turn::main1 && p_turn != phase_turn::main2))
        //si ce n'est le bon joueur ou la bonne pahse du jeu on quitte immédiatement.
        return;
    
    //on essaie de lancer ou un sort ou une unité 
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

/* 
Objectif : Invoquer sur le board du joueur actuel l'unité cliqué si cela est possible.
Entrée :
    - Une unité.
Sortie : 
    - void
*/
void game_controller::summon_unit( unit* casted )
{
    if(casted->get_cost() <= current_player->get_charge())
    {
        current_player->summon_card(casted);
        current_player->set_charge(current_player->get_charge()-casted->get_cost());
        current_player->pop_from(HAND,casted);
    }
}

/* 
Objectif : Active un sort du joueur actuel si cela est possible.
Entrée :
    - Un sort.
Sortie : 
    - void
*/
void game_controller::spell_clicked( spell* casted )
{
    if(casted->get_classe() != "voleur")
    {
        if(waiting_player->get_player_board_size() == 0)
        {
            return;
        }
        current_player->cast_spell(casted, current_player);
    }
    waiting_spell = casted; 
}

/* 
Objectif : Séléctionne comme attaquant l'unité si celle ci n'est pas engagée.
Entrée :
    - Une unité.
Sortie : 
    - void
*/
void game_controller::select_attacker( unit* u )
{
    if(u->is_tapped())return;
    u->tap();
    list_fight.push_back({u,nullptr});
}

/* 
Objectif : Séléctionne comme bloqueur l'unité si celle ci n'est pas engagée.
Entrée :
    - Une unité.
Sortie : 
    - void
*/
void game_controller::select_blocker( unit* u )
{
    if(u->is_tapped()) return;
    blocker = u;
}

/* 
Objectif : Séléctionner quel unité attaquante sera bloquée par le bloqueur courant.
Entrée :
    - Une unité.
Sortie : 
    - void
*/
void game_controller::select_blocker_target( unit* u )
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

/* 
Objectif : Executer les combats entre les unités puis les renvoyer chez leurs propriétaires.
Entrée :
    - void
Sortie : 
    - void
*/
void game_controller::resolve_fight( void )
{
    //parcour la liste des combats
    for( size_t i = 0; i < list_fight.size(); i++)
    {
        unit* t_unit = list_fight[i].blocker;
        unit* a_unit = list_fight[i].attacker;
        if(t_unit != nullptr)
        {
            //calcule la force réel des unité en fonction de la classe adverse puis fait se battre les unités.
            int pv_attack = a_unit->get_stamina();
            int strenght_attack = a_unit->get_strenght();
            int pv_block = t_unit->get_stamina();
            int strenght_block = t_unit->get_strenght();

            if(a_unit->counter(t_unit))
            {
                pv_attack = pv_attack*2;
                strenght_attack = strenght_attack*2;
            }
            if(t_unit->counter(a_unit))
            {
                pv_block = pv_block*2;
                strenght_block = strenght_block*2;
            }

            pv_attack-=strenght_block;

            pv_block-=strenght_attack; 

            if(pv_attack <= 0)
            {
                a_unit->killed();
            }
            if(pv_block <= 0)
            {
                t_unit->killed();
            }
            current_player->summon_card(a_unit);
            waiting_player->summon_card(t_unit);

        }
        else
        {
            //l'unité frappe directement le joueur attaqué si personne ne bloque
            unit* a_unit = list_fight[i].attacker;
            waiting_player->hitted(a_unit->get_strenght());
            current_player->summon_card(a_unit);
        }
    }
    list_fight.clear();
    blocker = nullptr;
    return;
}

/* 
Objectif : Execute les opérations d'entrée dans la phase suivante puis entre dans la phase suivante.
Entrée :
    - void
Sortie : 
    - void
*/
void game_controller::next_phase( void )
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

/* 
Objectif : Calcule le nombre de charge actuel pour les joueurs.
Entrée :
    - void
Sortie : 
    - Un entier correspondant au nombre de charge donné au joueur.
*/
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

/* 
Objectif : Getter de la liste des combattants.
Entrée :
    - void
Sortie : 
    - Un vecteur de la structure fight.
*/
std::vector<fight> game_controller::get_current_attacker( void )
{
    return list_fight;
}

/* 
Objectif : Joue le tour du bot selon la phase du tour  :
    main1 ou main2: il pose des cartes
    selection_attacker: il attaque
    selection_blocker: il bloque
Entrée : 
    void
Sortie :
    void
*/
void game_controller::bot_turn( void )
{
    if(p_turn == phase_turn::main1 || p_turn == phase_turn::main2){
        bot_play_main();
    }

    if(p_turn == phase_turn::selection_attacker){
        bot_play_attacker();
    }
}

/* 
Objectif : Le bot pose les cartes les moins chers pour pouvoir poser le plus d'unités
    et utiliser le plus de sort dans un tour
Entrée : 
    void
Sortie :
    void
*/
void game_controller::bot_play_main()
{
    bot* clanker = (bot*)current_player;
    int charge_min = clanker->charge_min_hand();
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
                charge_min = clanker->charge_min_hand();
                break;
            }
        }
    }
    next_phase();
}

/* 
Objectif : Le bot attaque avec la moitié de ses unités + 1 sur le board
Entrée : 
    void
Sortie :
    void
*/
void game_controller::bot_play_attacker( void )
{
    size_t board_size = current_player->get_player_board_size();
    if(board_size!=0){
        for(size_t i = 0; i < board_size/2 +1;++i){
            unit* t_unit = (unit*) current_player->get_card_from_board(0); 
            selected_card_board(t_unit,current_player);
        }
    }
    next_phase();
}

/* 
Objectif : Le bot bloque avec l'unité la plus pertinente, une unité bloque si elle 
        tue l'unité attaquante ou si le bot peut perdre la partie s'il ne bloque pas.
Entrée : 
    void
Sortie :
    void
*/
void game_controller::bot_play_blocker( void )
{
    for(size_t i =0 ; i < list_fight.size();++i){
        unit* t_attacker = list_fight[i].attacker;
        size_t board_size = waiting_player->get_player_board_size();
        for(size_t j =0 ; j < board_size ; ++j){
            unit* t_unit = (unit*) waiting_player->get_card_from_board(j);
            bool attack_counter_block = t_attacker->counter(t_unit);
            bool block_counter_attacker = t_unit->counter(t_attacker);
            int blocker_stam = t_unit->get_stamina();
            int attacker_stam = t_attacker->get_stamina();
            
            //Le bot bloque avec cette créature seulement si les deux meurent 
            //ou si seulement la créature attaquante meurt
            if((block_counter_attacker && blocker_stam*2 >= attacker_stam) ||
            (!attack_counter_block && blocker_stam >= attacker_stam) ||
            (attack_counter_block && blocker_stam >= 2*attacker_stam))
            {
                select_blocker(t_unit);
                select_blocker_target(t_attacker);
            }
            break;
        }
    }
    //calcule s'il meurt après que toutes les unités sans bloquants aient attaquées
    int degats_max = 0;
    for(size_t i =0 ; i < list_fight.size();++i){
        unit* attacker = list_fight[i].attacker;
        if(list_fight[i].blocker == nullptr){
            degats_max += attacker->get_strenght();
        }
    }
    if(degats_max>=waiting_player->get_pv()){ //si le bot meurt:
        for(size_t i =0 ; i < list_fight.size();++i){
            unit* t_attacker = list_fight[i].attacker;
            size_t board_size = waiting_player->get_player_board_size();
            for(size_t j =0 ; j < board_size ; ++j){
                unit* t_unit = (unit*) waiting_player->get_card_from_board(j);
                //aucune des créatures ne bat celle d'en face donc on choisit la première qui vient
                select_blocker(t_unit);
                select_blocker_target(t_attacker);
                break;
            }
        }
    }
    
    next_phase();
}

/* 
Objectif : méthode appellé à chaque tic qui sert a executer les méthodes devant être activée automatiquement.
Entrée :
    - Un flotant delta correspondant à l'écart de temps entre 2 itérations.
Sortie :
    - void
*/
void game_controller::update( float delta )
{
    timer -= delta;
    if((current_player->is_bot() && p_turn !=  phase_turn::selection_blocker)){
        bot* player_bot;
        player_bot = (bot*) current_player;
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