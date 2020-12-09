#ifndef __REMOVEBONUS_HPP__
#define __REMOVEBONUS_HPP__

#include "visitor.hpp"
#include "Neighborhood.h"

class RemoveBonus : public Visitor{
public:
	RemoveBonus(){} 

        void visitWonderland(Neighborhood* neigh){
                
                int** ar = neigh->getGrid(); 
		// int ar[7][7] = Neighborhood->getGrid();

                for(int i = 0; i < 6; ++i)
                {
                        for(int j = 0; j < 6; ++j)
                        {
                               if(ar[i][j] > 0 && ar[i][j] <= 30){ar[i][j] = ar[i][j] / 2;} 
                        }
                }

        }

	void visitNightmare(Neighborhood* neigh){

                int** ar = neigh->getGrid();
               // int ar[7][7] = Neighborhood->getGrid();

		int row = neigh->getBonusCoordinateX();
		int col = neigh->getBonusCoordinateY();

		ar[row][col] = -1; 

                 neigh->setBonusCoordinateX(row);
                 neigh->setBonusCoordinateY(col);

          }

};


#endif
