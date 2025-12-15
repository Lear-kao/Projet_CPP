#include "../HPP/unit.hpp"

unit::unit(int cost){
    cost = cost;
}

int unit::get_strenght(void)
{
    return strenght;
}

int unit::get_stamina(void)
{
    return stamina;
}