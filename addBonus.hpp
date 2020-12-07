#ifndef __ADDBONUS_HPP__
#define __ADDBONUS_HPP__

#include <iostream> 
#include "visitor.hpp"
#include "Neighborhood.h" 

#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

using namespace std; 

class AddBonus : public Visitor{

public: 
	AddBonus(){} 

        void visitWonderland(Neighborhood* neigh){
		
		int** ar = neigh->getGrid(); 
		// int ar[7][7] = Neighborhood->getGrid();

		for(int i = 1; i < 7; ++i)
    		{
        		for(int j = 1; j < 7; ++j)
        		{
            			ar[i][j] = ar[i][j] * 2; 
        		}
    		}

	}

        void visitNightmare(Neighborhood* neigh){

		int** ar = neigh->getGrid();
		//int ar[7][7] = Neighborhood->getGrid();

		bool loop = true; 

		while(loop){
	
			srand (time(NULL));
			int row = rand() % 6; //picks a number between 0 - 6
			int col = rand() % 6; //picks a number between 0 - 6

			if(ar[row][col] == -1){
			
				ar[row][col] = 30; // if the person guesses this index they will automatically get 30 points
				loop = false; 
 
				neigh->setBonusCoordinateX(row); 
				neigh->setBonusCoordinateY(col); 				
				
			}
		}

	}

}; 


#endif
