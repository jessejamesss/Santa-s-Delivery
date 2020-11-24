#ifndef NEIGHBORHOOD.H
#define NEIGHBORHOOD.H

#include <iostream>
#include <stdio.h>
#include <ctype.h>


using namespace std;

class Neighborhood {
    public:
        void accept(Vistor* v) = 0;
        int getGrid();
        int retrieveCoordinate(char x, int y) = 0;
        char getXCoordinate() = 0;
        int getYCoordinate() = 0;
        void setBlocks() = 0;
        int getPoints() = 0;
        void setPoints(int points) = 0;
        string getTheme() = 0;
        bool checkValidity(char x, int y) = 0;
        bool getGameOver() = 0;
        void setTheme(string name) = 0;
        

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
        void twoNeighborhoods() = 0;
        void threeNeighborhoods() = 0;
        void fourNeighborhoods() = 0;
        void setPoint() = 0;
        bool checkValidNeighbors(int x, int y) = 0;
        

};
#endif
