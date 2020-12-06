#ifndef __NIGHTMARE_H__
#define __NIGHTMARE_H__
#include "Neighborhood.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>

class Nightmare : public Neighborhood {
    public:
        Nightmare();
        int getGrid();
        int retrieveCoordinate(char x, int y);
        char getXCoordinate();
        int getYCoordinate();
        char getBonusCoordX();
        int getBonusCoordY();
        void setBlocks();
        int getPoints();
        void addPoints(int x);
        void setPoints(int points);
        std::string getTheme();
        bool checkValidity(char x, int y);
        bool getGameOver();
        void setTheme(std::string name);
        

    private:
        int points;
        std::string theme;
        int grid[6][6] = {{-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1}};
        bool gameOver;
        char coordinateX;
        int coordinateY;
        char bonusCoordinateX;
        int bonusCoordinateY;
        int attempts;
        void twoNeighborhoods();
        void threeNeighborhoods();
        void setPoint();
        bool check2ValidNeighbors(char x, int y, char z, int zz);
        bool check3ValidNeighbors(char x, int y, char z, int zz, char x1, int x2);
        char setXCoord(); // implement later
        int setYCoord(); // implement later
        

};
#endif /* Nightmare_h */

