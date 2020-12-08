#include <iostream>
#include "visitor.hpp"
#include "removeBonus.hpp"
#include "addBonus.hpp"
#include "Nightmare.h"
#include "Neighborhood.h"
#include "Wonderland.h"

using namespace std;

int main() {
   Neighborhood* player2 = new Wonderland();
   Neighborhood* player1 = new Nightmare();

    	
    int** arr = player1->getGrid(); 


    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            cout << arr[i][j] << ",";
        }
        cout << endl;
    }
    cout << "-------------------------------------" << endl << endl; 
    player1->accept(new AddBonus());

    for(int i = 0; i < 6; ++i){
	for(int j = 0; j < 6; ++j){
	    cout << arr[i][j] << ",";
	}
	cout << endl; 
    }
		
    player1->accept(new RemoveBonus());
	
     cout << "-------------------------------------" << endl << endl;

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            cout << arr[i][j] << ",";
        }
        cout << endl;
    }
player1->setBlocks();
//player2->setBlocks();

cout << endl << endl << endl;

for(int i = 0; i < 6; ++i){
   for(int j = 0; j < 6; ++j){
      cout << arr[i][j] << ",";
        }
        cout << endl;

}    //Wonderland* player2 = new Wonderland();
}
