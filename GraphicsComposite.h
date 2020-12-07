#ifndef __GRAPHICSCOMPOSITE_H__
#define __GRAPHICSCOMPOSITE_H__

#include "Graphics.h"

class GraphicsComposite : public Graphics {
    
private:
    vector <Graphics*> graphics;
    
public:
    void drawBoard();
    void add(Graphics*);
    
};


#endif //__GRAPHICSCOMPOSITE_H__
