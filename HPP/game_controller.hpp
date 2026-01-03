#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "class_UI.hpp"

class player;
class unit;
class spell;
class button;
class card_gen;

enum phase_turn
{
    draw,
    main1,
    selection_attacker,
    selection_blocker,
    main2,
    end
};

struct fight
{
    unit* attacker = nullptr;
    unit* blocker = nullptr;
};

class game_controller
{
    private:
        int tour_actuel = 1;
        float timer = 25;

        //gestionnaire de phase
        phase_turn p_turn = phase_turn::main1;
        //phase principale
        spell* waiting_spell = nullptr; //variable d'attente si une cible est necessaire pour le sort (kill)
        unit* target_spell = nullptr;
        
        //phase de combat
        std::vector<fight> list_fight;
        unit *blocker = nullptr;

        //joueurs
        player *current_player;
        player *waiting_player;

        //render
        UI afficheur_de_phase;
        UI affichage_timer;

        int get_current_charge( void );

    public:
        game_controller(player *p1, player *p2);
        void next_phase(void);

        std::vector<fight> get_current_attacker( void );
        
        //click sur les attaquants méthode
        void clicked_attacker(sf::Vector2f mousePos);

        //phase de combat méthode
        void selected_card_board(unit *u, player* p_clicked);
        void select_attacker(unit* u);
        void select_blocker(unit *u);
        void select_blocker_target(unit* u);
        void resolve_fight();

        //phase d'invocation méthode
        void selected_card_hand(card_gen* card, player* p_clicked);   
        void spell_clicked(spell* casted );
        void summon_unit(unit* casted);

        //tour du bot
        void bot_turn(); 
        void bot_play_main();
        void bot_play_attacker();
        void bot_play_blocker();


        void render(sf::RenderWindow& window);
        void render_fight(sf::RenderWindow& window);
        void update(float delta);
};

#endif
