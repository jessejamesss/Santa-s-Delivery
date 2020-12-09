#include "Attempts.h"

Attempts::Attempts() {
    this->numAttempts = 1;
}

void Attempts::drawBoard() {
    cout << "Attempts left: " << numAttempts << endl << endl;
}

void Attempts::updateAttempts(int newAttempts) {
    this->numAttempts = newAttempts;
}

void Attempts::updateBoard(int** newGrid) {
    return;
}

void Attempts::updatePoints(int newPoints) {
    return;
}

