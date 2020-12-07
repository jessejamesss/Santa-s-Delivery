#include "AttemptsBoard.h"

void AttemptsBoard:: drawBoard() {
     string grid[7][7] = {{" ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 "},
                          {"A","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"B","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"C","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"D","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"E","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                          {"F","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}};
    
     //Draw the board 
     for (int i =0; i < 7; i ++){
        for (int j =0; j < 7; j++){
            cout << grid[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

void AttemptsBoard:: update(int* grid) {
    //Needs Implementation
}
