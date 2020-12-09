#include "AttemptsBoard.h"

AttemptsBoard::AttemptsBoard() { }

void AttemptsBoard::drawBoard() {
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

void AttemptsBoard::updateBoard(int** newGrid) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (newGrid[i][j] == -2) {
                grid[i][j] = "[·]";
            }
            if (newGrid[i][j] == -3) {
                grid[i][j] = "[☆]";
            }
        }
    }
}

void AttemptsBoard::updatePoints(int newPoints) {
    return;
}

void AttemptsBoard::updateAttempts(int newAttempts) {
    return;
}
