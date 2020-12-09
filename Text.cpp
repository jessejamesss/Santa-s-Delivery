#include "Text.h"

Text::Text(int theme, string name) {
    this->name = name;
    if (theme == 0) {
        this->theme = "Attempts";
        this->name = "";
    }
    if (theme == 1) {
        this->theme = "Wonderland";
    }
    if (theme == 2) {
        this->theme = "Nightmare";
    }
}

void Text:: drawBoard() {
    if (theme == "Attempts") {
        cout << "                 "  << theme << " Board";
    }
    else {
        cout << "           " << name << "'s " << theme << " Board";
    }
}

void Text::updateBoard(int** newGrid) {
    return;
}

void Text::updatePoints(int newPoints) {
    return;
}

void Text::updateAttempts(int newAttempts) {
    return;
}
