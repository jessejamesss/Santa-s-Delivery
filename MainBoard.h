#ifndef __MAINBOARD_H__
#define __MAINBOARD_H__

#include "Graphics.h"

using namespace std;

class MainBoard : public Graphics {
private:
    string grid[6][6] = {{"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}};

public:
    MainBoard();
    void drawBoard();
    void updateBoard(int** newGrid);
    void updatePoints(int newPoints);
    void updateAttempts(int newAttempts);


};

#endif //__MAINBOARD_H__
