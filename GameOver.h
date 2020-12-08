#ifndef __Game_Over__
#define __Game_Over__
#include "Neighborhood.h"
#include "GameState.hpp"

class GameOver : public GameState {
    public:
        GameOver();
        virtual void editGameState(Neighborhood* n);
};
#endif

