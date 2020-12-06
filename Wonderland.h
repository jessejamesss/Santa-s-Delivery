#include "Neighborhood.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
class Wonderland : public Neighborhood {
    public:
        Wonderland();
        int getGrid();
        int retrieveCoordinate(char x, int y);
        char getXCoordinate();
        int getYCoordinate();
        void setBlocks();
        int getPoints();
        void addPoints(int points);
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
        int attempts;
        void twoNeighborhoods();
        void threeNeighborhoods();
        void setPoint();
        bool check2ValidNeighbors(char x, int y, char z, int zz);
        bool check3ValidNeighbors(char x, int y, char z, int zz, char x1, int x2);
        char setXCoord(); // implement later
        int setYCoord(); // implement later
        

};
#endif

