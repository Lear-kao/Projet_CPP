#include "card_gen.hpp"

class unit: public card_gen
{
    private: 
        int strenght;
        int stamina;
    public:
        unit(int cost);
        int get_strenght(void);//fait
        int get_stamina(void);//fait
};