#include "Nightmare.h"

void Nightmare::accept(Vistor* v){
    vistor = v;
}

int* Nightmare::getGrid(){
}

int Nightmare::retrieveCoordinate(char x, int y){
    int index = x - 'a';
    return grid[index][y];
}

char Nightmare::getXCoordinate() {
    return coordinateX;
}

int Nightmare::getYCoordinate(){
    return coordinateY;
}

int Nightmare::getPoints(){
    return points;
}

void Nightmare::setPoints(int addPts){
    points += addPts;
}

string Nightmare::getTheme() {
    return theme;
}

bool Nightmare::checkValidity(char x, int index2){   // ADD CHECK FOR BOUNDS!!!! (CHECK BOUNDS)
    int index1 = x - 'a';
    if(grid[index1][index2] != -1){
        return false;
    }
    else {
        return true;
    }
}

bool Nightmare::getGameOver(){
}

void Nightmare::setBlocks(){

    twoNightmares();
    threeNightmares();
    fourNightmares();

}

void Nightmare::twoNightmares() {

    char rowNum;
    int columnNum;
    bool satisfied = false;
    bool isValid = false; 
    int counter = 0
    while(counter < 2){
        while(isValid == false){
            cout << "\nPlease select a row on the grid where you want to place your Nightmare of 2 (A-F)\n";
            cin << rowNum;
            rowNum = tolower(rowNum);
            while(satisfied == false){
                if(rowNum == 'a' ||rowNum == 'b' ||rowNum == 'c' ||rowNum == 'd' || rowNum == 'e' ||rowNum == 'f'){
                    coordinateX = rowNum;
                    satisfied = true;
                }
                else {
                    cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
                    cin << rowNum;
                    rowNum = toupper(rowNum);
                }
            }

            satisfied = false; // resets the satisfied

            cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
            cin << columnNum;
            
            while(satisfied == false){
                if(columnNum >= 0 && columnNum < 6) {
                    coordinateY = columnNum;
                    satisfied = true;
                }
                else {
                    cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
                    cin << columnNum;
                }
            }
            satisfied = false; // resets the satisfied

            if(checkValidity(coordinateX, coordinateY) == true && checkValidNeighbors(coordinateX, coordinateY) == true){   
                setPoint(rowNum, columnNum, 30);
                isValid = true;
                counter += 1
            }
            else {
                cout << "\nThat point is already occupied. Please try again.\n"
            }
        }
    }
}


void Nightmare::setPoint(char x, int index2, int type){
    int index1 = x - 'a';
    grid[index1][index2] = 30;
}

bool Nightmare::checkValidNeighbors(int index1, int index2){
    // NEED IMPLEMENTATION OF THE FUNCTIONS
}
