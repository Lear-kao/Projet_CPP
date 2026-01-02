#include "../HPP/bot.hpp"


void bot::reset_think(){
    think_bot = 0;
}

void bot::add_to_think_bot(float delta){
    think_bot+=delta;
}

float bot::get_think_bot(){
    return think_bot;
}

void bot::play_turn(){

}
        