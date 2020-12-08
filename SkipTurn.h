#ifndef __Skip_Turn__
#define __Skip_Turn__
#include "Neighborhood.h"
#include "GameState.hpp"

class SkipTurn : public GameState {
    public:
        SkipTurn();
        virtual void editGameState(Neighborhood* n);
}
#endif
