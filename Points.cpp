#include "Points.h"

Points::Points(int points) {
    this->points = points;
}

void Points::drawBoard() {
    cout << "Points: " << points << endl;
    cout << endl;
}

void Points::updatePoints(int newPoints) {
    this->points = newPoints;
}

void Points::updateBoard(int** newGrid) {
    return;
}

void Points::updateAttempts(int newAttempts) {
    return;
}

