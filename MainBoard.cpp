#include "MainBoard.h"

MainBoard::MainBoard() {}

void MainBoard:: updateBoard(int** newGrid) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (newGrid[i][j] == 5 || newGrid[i][j] == 3 ) {
                grid[i][j] = "[☆]";
            }
            if (newGrid[i][j] == 40 || newGrid[i][j] == 50 || newGrid[i][j] == 60 || newGrid[i][j] == 70) {
               grid[i][j] = "[☄]";
            }
        }
    }
}

void MainBoard:: drawBoard() {
    char x = 'A';
    cout << "              0   1   2   3   4   5" << endl;
    for (int i = 0; i < 6; i ++){
        cout << "           ";
        cout << x << " ";
        x++;
        for (int j =0; j < 6; j++){
            cout << grid[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

void MainBoard::updatePoints(int newPoints) {
    return;
}

void MainBoard:: updateAttempts(int newAttempts) {
    return;
}

