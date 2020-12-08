#ifndef __Auto_Win__
#define __Auto_Win__
#include "Neighborhood.h"
#include "GameState.hpp"

class AutoWin : public GameState {
    public:
        AutoWin();
        virtual void editGameState(Neighborhood* n);
};
#endif
