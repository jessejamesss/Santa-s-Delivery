#include "GameOver.h"
#include "Neighborhood.h"
#include "GameState.hpp"


GameOver::GameOver(){}

void GameOver::editGameState(Neighborhood* n){
   n->setGameOver();
}    
