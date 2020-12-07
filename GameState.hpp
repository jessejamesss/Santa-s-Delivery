#ifndef __GameState_HPP__
#define __GameState_HPP__

#include "Neighborhood.h"

class Neighborhood;

class GameState {
    public:
        GameState(){}

        virtual void editGameState(Neighborhood* n) = 0;
};

#endif //__GameState_HPP__

