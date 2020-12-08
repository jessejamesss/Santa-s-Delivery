#include "AutoWin.h"
#include "Neighborhood.h"
#include "GameState.hpp"

AutoWin::AutoWin(){}

void AutoWin::editGameState(Neighborhood* n){
   n->setGameOver();
}                     
