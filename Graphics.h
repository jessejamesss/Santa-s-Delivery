#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Graphics {

public:
    virtual void drawBoard() = 0;
    virtual void updateBoard(int** newGrid) = 0;
    virtual void updatePoints(int newPoints) = 0;
    virtual void updateAttempts(int newAttempts) = 0;
    
    
};

#endif //__GRAPHICS_H__
