#ifndef __ATTEMPTSBOARD_H__
#define __ATTEMPTSBOARD_H__

#include "Graphics.h"

using namespace std;

class AttemptsBoard : public Graphics {
public:
    void drawBoard();
    void update(int* grid);

};

#endif //__ATTEMPTSBOARD_H__
