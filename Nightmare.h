#ifndef NIGHTMARE.H
#define NIGHTMARE.H

#include "Neighborhood.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

class Nightmare : public Neighborhood {
    public:
        void accept(Vistor* v);
        int getGrid();
        int retrieveCoordinate(char x, int y);
        char getXCoordinate();
        int getYCoordinate();
        void setBlocks();
        int getPoints();
        void setPoints(int points);
        string getTheme();
        bool checkValidity(char x, int y);
        bool getGameOver();
        void setTheme(string name);
        

    private:
        int points = 0;
        string theme;
        int [6][6]grid = {{-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1},
                          {-1,-1,-1,-1,-1,-1}}
        Vistor* vistor;
        Strategy* strategy;
        bool gameOver;
        char coordinateX;
        int coordinateY;
        char bonusCoordinateX;
        int bonusCoordinateY;
        int attempts = 1;
        void twoNeighborhoods();
        void threeNeighborhoods();
        void fourNeighborhoods();
        void setPoint();
        bool checkValidNeighbors(int x, int y);
        

};
#endif

