#include "MainBoard.h"

void MainBoard:: drawBoard() {
    string grid[7][7] = {{" ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 "},
                          {"A","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"B","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"C","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"D","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"E","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"F","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}};

    //Draw the main board
    for (int i =0; i < 7; i ++){
        for (int j =0; j < 7; j++){
            cout << grid[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

void MainBoard:: update(int* grid) {
    //Needs Implementation
}
