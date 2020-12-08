#include "GraphicsComposite.h"

void GraphicsComposite:: drawBoard() {
    for (int i = 0; i < graphics.size(); ++i) {
        graphics[i]->drawBoard();
        cout << endl;
    }
}

void GraphicsComposite:: add(Graphics* grid) {
    graphics.push_back(grid);
}

void GraphicsComposite::updateBoard(int** newGrid) {
    return;
}

void GraphicsComposite::updatePoints(int newPoints) {
    return;
}

void GraphicsComposite::updateAttempts(int newAttempts) {
    return;
}
