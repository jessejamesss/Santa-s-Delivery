#ifndef __MAINBOARD_H__
#define __MAINBOARD_H__

#include "Graphics.h"

using namespace std;

class MainBoard : public Graphics {
public:
    MainBoard();
    void drawBoard();
    void update(int* grid);


};

#endif //__MAINBOARD_H__
