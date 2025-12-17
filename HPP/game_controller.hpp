#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

class player;
class unit;
class spell;
class button;
class card_gen;

enum phase_turn
{
    draw,
    main1,
    fight,
    main2,
    end
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
        unit *attacker = nullptr;
        unit *blocker = nullptr;

        //phase principale
        spell* waiting_spell = nullptr; //variable d'attente si une cible est necessaire pour le sort (kill)

    public:
        void next_phase(void);

        //phase de combat méthode
        void selected_card_board(unit *u);
        void select_attacker(unit* u);
        void select_blocker(unit *u);
        void resolve_fight();

        //phase d'invocation méthode
        void selected_card_hand(card_gen* card);    
};

#endif
