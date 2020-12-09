#include "SkipTurn.h"
#include "Neighborhood.h"
#include "GameState.hpp"

SkipTurn::SkipTurn(){}

void SkipTurn::editGameState(Neighborhood* n){
   n->setAttempts(0);
   cout << "IN SKIP TURN ***************** " << endl << endl;  
}
