#ifndef __ATTEMPTSBOARD_H__
#define __ATTEMPTSBOARD_H__

#include "Graphics.h"

using namespace std;

class AttemptsBoard : public Graphics {
private:
    string grid[6][6] = {{"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}};
public:
    AttemptsBoard();
    void drawBoard();
    void updateBoard(int** newGrid);
    void updatePoints(int newPoints);
    void updateAttempts(int newAttempts);

};

#endif //__ATTEMPTSBOARD_H__
