#include "gtest/gtest.h"

#include <iostream>
#include <vector>
#include "addBonus.hpp"
#include "AttemptsBoard.h"
#include "GameOver.h"
#include "GameState.hpp"
#include "GraphicsComposite.h"
#include "Graphics.h"
#include "MainBoard.h"
#include "Neighborhood.h"
#include "Nightmare.h"
#include "removeBonus.hpp"
#include "SkipTurn.h"
#include "visitor.hpp"
#include "Wonderland.h"
#include "Points.h"
#include "Text.h"
#include <ctype.h>
#include "AutoWin.h"
#include "Attempts.h"
#include <stdlib.h>
#include<ios> //used to get stream size
#include<limits>

TEST(Visitor, AddBonus){

  Wonderland* player_one = new Wonderland();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        } 
  player_one->setBlocks();

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }

   int value = arr3[0][0];    
 
  player_one->accept(new AddBonus()); 
  
  int** arr2 = player_one->getGrid();

  int value2 = arr2[0][0]; 

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(arr2, player_one->getGrid());
  EXPECT_EQ(value * 2, value2);
}

TEST(Visitor, AddBonusEndEdge){

  Wonderland* player_one = new Wonderland();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        }
  player_one->setBlocks();

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }

   int value = arr3[0][5];

  player_one->accept(new AddBonus());

  int** arr2 = player_one->getGrid();

  int value2 = arr2[0][5];

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(arr2, player_one->getGrid());
  EXPECT_EQ(value * 2, value2);
}

TEST(Visitor, AddBonusEndEdge2){

  Neighborhood* player_one = new Nightmare();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        }
  player_one->setBlocks();

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }


  player_one->accept(new AddBonus());

  int** arr2 = player_one->getGrid();

  int value2 = arr2[player_one->getBonusCoordinateX()][player_one->getBonusCoordinateY()];

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(arr2, player_one->getGrid());
  EXPECT_EQ(30, value2);
}

TEST(Visitor, AddBonusEndEdge3){

  Neighborhood* player_one = new Nightmare();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        }
  player_one->setBlocks();

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }


  player_one->accept(new AddBonus());

  int** arr2 = player_one->getGrid();

  int value2 = arr2[player_one->getBonusCoordinateX()][player_one->getBonusCoordinateY()];

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(arr2, player_one->getGrid());
  EXPECT_EQ(30, value2);
}

TEST(Visitor, RemoveBonus){

  Wonderland* player_one = new Wonderland();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        }
  player_one->setBlocks();


  player_one->accept(new AddBonus());

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }

  int value = arr3[0][0];

  player_one->accept(new RemoveBonus());

  int** arr2 = player_one->getGrid();

  int value2 = arr2[0][0];

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(arr2, player_one->getGrid());
  EXPECT_EQ(value / 2, value2);
}


TEST(Visitor, RemoveBonusEdge){

  Wonderland* player_one = new Wonderland();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        }

  player_one->setBlocks();


  player_one->accept(new AddBonus());

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }

  int value = arr3[0][5];

  player_one->accept(new RemoveBonus());

  int** arr2 = player_one->getGrid();

  int value2 = arr2[0][5];

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(arr2, player_one->getGrid());
  EXPECT_EQ(value / 2, value2);
}

TEST(Visitor, NightmareRemove){

  Neighborhood* player_one = new Nightmare();
  int** arr = player_one->getGrid();
  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr[i][j] << ",";
                }
                cout << endl;
        }
  player_one->setBlocks();


  player_one->accept(new AddBonus());

  int** arr3 = player_one->getGrid();

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }

  int** arr2 = player_one->getGrid();

  int value2 = arr2[player_one->getBonusCoordinateX()][player_one->getBonusCoordinateY()];

  player_one->accept(new RemoveBonus());

  int value = arr2[player_one->getBonusCoordinateX()][player_one->getBonusCoordinateY()];

  for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

  EXPECT_EQ(value2, 30);
  EXPECT_EQ(value, -1);
  EXPECT_EQ(30, value2);
}


int main(int argc, char **argv) {
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}
