#ifndef __NEIGHBORHOOD_H__
#define __NEIGHBORHOOD_H__

#include <iostream>
#include <stdio.h>
#include <ctype.h>



class Neighborhood {
    public:
        Neighborhood(){}
        virtual int getGrid() = 0;
        virtual int retrieveCoordinate(char x, int y) = 0;
        virtual  char getXCoordinate() = 0;
        virtual int getYCoordinate() = 0;
        virtual void setBlocks() = 0;
        virtual int getPoints() = 0;
        virtual void addPoints(int points) = 0;
        virtual std::string getTheme() = 0;
        virtual bool checkValidity(char x, int y) = 0;
        virtual  bool getGameOver() = 0;
        virtual void setTheme(std::string name) = 0;
        

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
        virtual void twoNeighborhoods() = 0;
        virtual void threeNeighborhoods() = 0;
        virtual void setPoint() = 0;
        virtual bool check2ValidNeighbors(char x, int y, char z, int zz) = 0;
        virtual bool check3ValidNeighbors(char x, int y, char z, int zz, char x1, int x2) = 0;
        virtual char setXCoord() = 0; // implement later
        virtual int setYCoord() = 0; // implement later
};
#endif
