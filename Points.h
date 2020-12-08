#ifndef __POINTS_H__
#define __POINTS_H__

#include "Graphics.h"
#include <iostream>

using namespace std;

class Points : public Graphics {
private:
    int points;
public:
    Points(int points);
    void drawBoard();
    void updateBoard(int** newGrid);
    void updatePoints(int newPoints);
    void updateAttempts(int newAttempts);

};

#endif //__POINTS_H__
