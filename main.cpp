#include <iostream>
#include "visitor.hpp"
#include "removeBonus.hpp"
#include "addBonus.hpp"
#include "Nightmare.h"
#include "Neighborhood.h"

using namespace std;

int main() {
    Neighborhood* player1 = new Nightmare();

    	
    int** arr = player1->getGrid(); 
    cout << "God is faithful who also will do it" << endl;  

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

    //Wonderland* player2 = new Wonderland();
}
