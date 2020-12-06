#ifndef __TEXT_H__
#define __TEXT_H__

#include "Graphics.h"

using namespace std;

class Text : public Graphics {
private:
    string theme;
    string name;
    
public:
    Text(int theme, string name);
    void drawBoard();
    void updateBoard(int** newGrid);
    void updatePoints(int newPoints);
    void updateAttempts(int newAttempts);
};

#endif //__TEXT_H__

