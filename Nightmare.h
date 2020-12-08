#ifndef __NIGHTMARE_H__
#define __NIGHTMARE_H__
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "visitor.hpp"
#include "GameState.hpp"

class Strategy;
class Visitor;

#include "Neighborhood.h"

class Nightmare : public Neighborhood {
    public:
        Nightmare();
        ~Nightmare();
	int** getGrid(); 
        int retrieveCoordinate(char x, int y);
        char getXCoordinate();
        int getYCoordinate();
        char getBonusCoordX();
        int getBonusCoordY();
        void setBlocks();
        int getPoints();
        void addPoints(int x);
        void setPoints(char x, int index2, int type);
        std::string getTheme();
        bool checkValidity(char x, int y);
        bool getGameOver();
        int getBonusCoordinateX();
        int getBonusCoordinateY(); 
	void setBonusCoordinateX(int);
        void setBonusCoordinateY(int);
	void accept(Visitor* v); 
	void setAttempts(int x);
        void setGameOver();
	void setStratCoords();
        int getAttempts();
        void miss(char, int);
        void hit(char, int);
        void editGameState();
        void setName(std::string);
        std::string getName();
        void setStratFunction(GameState*);
	bool checkRow(char);
	bool checkCol(char); 
   private:
        int points;
        std::string theme;
        /*int grid[6][6] = {{-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1}};*/
        GameState* s;
	Visitor* v;
	int** grid; 
        bool gameOver;
        char coordinateX;
        int coordinateY;
        char bonusCoordinateX;
        int bonusCoordinateY;
        int attempts;
        void twoNeighborhoods();
        void threeNeighborhoods();
        bool check2ValidNeighbors(char x, int y, char z, int zz);
        bool check3ValidNeighbors(char x, int y, char z, int zz, char x1, int x2);
        //char setXCoord(); // implement later
        //int setYCoord(); // implement later
        std::string name;
 	

};
#endif /* Nightmare_h */

