#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "player.hpp"
#include "unit.hpp"
#include "spell.hpp"

enum phase_turn
{
    main1,
    fight,
    main2
};

enum phase_fight
{
    not_in_fight,
    selection_attacker,
    selection_blocker
};


class game_controller
{
    private:
        //gestionnaire de phase
        phase_fight p_fight = phase_fight::not_in_fight;
        phase_turn p_turn = phase_turn::main1;

        //joueurs
        player *current_player;
        player *waiting_player;

        //phase de combat
        unit *attacker = NULL;
        unit *blocker = NULL;

        //phase principale
        spell* waiting_spell = NULL; //variable d'attente si une cible est necessaire pour le sort (kill)

    public:
        //phase de combat méthode
        void selected_card_board(unit *u);
        void select_attacker(unit* u);
        void select_blocker(unit *u);
        void resolve_fight();
        //phase d'invocation méthode
        void selected_card_hand(card_gen* card);    
}

#endif
