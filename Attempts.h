#ifndef __ATTEMPTS_H__
#define __ATTEMPTS_H__

#include "Graphics.h"

class Attempts : public Graphics {
private:
    int numAttempts;
    
public:
    Attempts();
    void drawBoard();
    void updateAttempts(int newAttempts);
    void updateBoard(int** newGrid);
    void updatePoints(int newPoints);
    
};


#endif //__ATTEMPTS_H__
