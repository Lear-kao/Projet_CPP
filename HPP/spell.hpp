#include "card_gen.hpp"

class sort: public card_gen
{
    private: 
        int value_effect;
    public:
        unit(int cost);
        int get_strenght(void);
        int get_stamina(void);
};