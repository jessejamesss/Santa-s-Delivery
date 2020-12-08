#ifndef __NEIGHBORHOOD_H__
#define __NEIGHBORHOOD_H__

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "visitor.hpp"
#include "GameState.hpp"

class Strategy;
class Visitor; 

class Neighborhood {
    public:
        Neighborhood(){}
        //virtual int &getGrid() = 0;
        virtual int retrieveCoordinate(char x, int y) = 0;
        virtual  char getXCoordinate() = 0;
        virtual int getYCoordinate() = 0;
        virtual void setBlocks() = 0;
        virtual int getPoints() = 0;
        virtual void addPoints(int points) = 0;
        virtual std::string getTheme() = 0;
        virtual bool checkValidity(char x, int y) = 0;
        virtual  bool getGameOver() = 0;
 	//int (&getGrid())[6][6] { return grid; }       
        virtual	int** getGrid() = 0; 
	~Neighborhood(){}
	virtual int getBonusCoordinateX() = 0; 
	virtual int getBonusCoordinateY() = 0;  
	virtual void setBonusCoordinateX(int) = 0; 
	virtual void setBonusCoordinateY(int) = 0; 
	virtual void accept(Visitor* v) = 0; 
	virtual void setAttempts(int x) = 0;
	virtual void setGameOver() = 0;
	virtual void setStratCoords() = 0;
	virtual void setStratFunction(Strategy* s) = 0;
    protected:
        int points;
        std::string theme;
        int** grid; 
	//int grid[6][6]; 
	/*= {{-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1}};*/
        int BonusCoordinateX;  
	int BonusCoordinateY;
	bool gameOver;
        char coordinateX;
        int coordinateY;
        int attempts;
        virtual void twoNeighborhoods() = 0;
        virtual void threeNeighborhoods() = 0;
        virtual bool check2ValidNeighbors(char x, int y, char z, int zz) = 0;
        virtual bool check3ValidNeighbors(char x, int y, char z, int zz, char x1, int x2) = 0;
        //virtual char setXCoord() = 0; // implement later
        //virtual int setYCoord() = 0; // implement later
};
#endif
