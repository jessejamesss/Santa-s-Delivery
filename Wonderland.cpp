#include "Wonderland.h"
using namespace std;

Wonderland::Wonderland(){
    points = 0;
    theme = "Wonderland";
    attempts = 1;
    gameOver = false;
}
int Wonderland::(&getGrid())[6][6] { return tempGrid; }

int Wonderland::retrieveCoordinate(char x, int y){
    int index = x - 'a';
    return grid[index][y];
}
int Wonderland::getPoints(){
    return points;
}

char Wonderland::getXCoordinate() {
    return coordinateX;
}

int Wonderland::getYCoordinate(){
    return coordinateY;
}

void Wonderland::addPoints(int pts){
    points += pts;
}

void Wonderland::addPoints(int addPts){
    points += addPts;
}

string Wonderland::getTheme() {
    return theme;
}

bool Wonderland::checkValidity(char x, int index2){   // ADD CHECK FOR BOUNDS!!!! (CHECK BOUNDS)
    int index1 = x - 'a';
    if(grid[index1][index2] != -1 || index1 - index2 == 0){
        return false;
    }
    else {
        return true;
    }
}

bool Wonderland::getGameOver(){
}


void Wonderland::setBlocks(){

    twoWonderlands(); // 3
    threeWonderlands();
}
void Wonderland::setPoint(char x, int index2, int type){
    int index1 = x - 'a';
    grid[index1][index2] = type;
}

void Wonderland::twoWonderlands() {
    char row1, row2;
    int column1, column2;
    bool satisfied = false;
    char coordinatRow1;
    int coordinateCol1;
    char coordinateRow2;
    int coordinateCol2;
    bool valid = false;

    while(valid == false){
        cout << "\nPlease select a row on the grid where you want to place your first Coordinate for your Wonderland of 2 (A-F) ";
        while(satisfied == false){
            cin << row1;
            row1 = tolower(row1);
            if(row1 == 'a' ||row1 == 'b' ||row1 == 'c' ||row1 == 'd' || row1 == 'e' ||row1 == 'f'){
                coordinatRow1 = row1;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5) ";
        
        while(satisfied == false){
            cin << column1;
            if(column1 >= 0 && column1 < 6) {
                coordinateCol1 = column1; // maybe change to one specific variable later
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a row on the grid where you want to place your second Coordinate for your Wonderland of 2 (A-F)\n";
        while(satisfied == false){
            cin << row2;
            row1 = tolower(row2);
            if(row2 == 'a' ||row2 == 'b' ||row2 == 'c' ||row2 == 'd' || row2 == 'e' ||row2 == 'f'){
                coordinateRow2 = row2;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
        
        while(satisfied == false){
            cin << column2;
            if(column2 >= 0 && column2 < 6) {
                coordinateCol2 = column2;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        if(checkValidity(coordinateRow1, coordinateCol1) == true && checkValidity(coordinateRow2, coordinateCol2) == true && check2ValidNeighbors(coordinateRow1, coordinateCol1, coordinateRow2, coordinateCol2) == true){
            setPoint(coordinateRow1, coordinateCol1, 5);
            setPoint(coordinateRow2, coordinateCol2, 5);
            counter += 1
            if(counter == 2){
                valid = true;
            }
            else {
                cout << "Point set successfully! Let's set the next point!" << endl << endl;
            }
        }
        else {
            cout << "Oops! Looks like one of the points you selected was already taken or not adjacent to the other coordinates. Remember,
             the coordinates have to be right next to each other on the grid (A1, A2 is valid, but A1, A3 is not). Try again." << endl << endl;
        }
    }
}



bool Wonderland::check2ValidNeighbors(char coordrow1, int col1, char coordrow2, int col2){
    bool vertical = false;
    bool horizontal = false;
    int row1 = coordrow1 - 'a';
    int row2 = coordrow2 - 'a';
    
    if(row1 - row2 == 0){
        horizontal = true;
    }
    if(col1 - col2 == 0) {
        vertical = true;
    }
    
    if(horizontal == true && vertical == false || vertical == true && horizontal == false){
        return true;
    }
    return false;
}




void Wonderland::threeWonderlands() {
    char row1, row2 row3;
    int column1, column2, column3;
    bool satisfied = false;
    char coordinatRow1;
    int coordinateCol1;
    char coordinateRow2;
    int coordinateCol2;
    char coordinateRow3;
    int coordinateCol3;

    bool valid = false;

    while(valid == false){
        cout << "\nPlease select a row on the grid where you want to place your first Coordinate for your Wonderland of 3 (A-F)\n";
        while(satisfied == false){
            cin << row1;
            row1 = tolower(row1);
            if(row1 == 'a' ||row1 == 'b' ||row1 == 'c' ||row1 == 'd' || row1 == 'e' ||row1 == 'f'){
                coordinatRow1 = row1;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
        
        while(satisfied == false){
            cin << column1;
            if(column1 >= 0 && column1 < 6) {
                coordinateCol1 = column1; // maybe change to one specific variable later
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a row on the grid where you want to place your second Coordinate for your Wonderland of 3 (A-F)\n";
        while(satisfied == false){
            cin << row2;
            row2 = tolower(row2);
            if(row2 == 'a' ||row2 == 'b' ||row2 == 'c' ||row2 == 'd' || row2 == 'e' ||row2 == 'f'){
                coordinateRow2 = row2;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
        
        while(satisfied == false){
            cin << column2;
            if(column2 >= 0 && column2 < 6) {
                coordinateCol2 = column2;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a row on the grid where you want to place your third Coordinate for your Wonderland of 3 (A-F)\n";

        while(satisfied == false){
            cin << row3;
            row3 = tolower(row3);
            if(row3 == 'a' ||row3 == 'b' ||row3 == 'c' ||row3 == 'd' || row3 == 'e' ||row3 == 'f'){
                coordinateRow3 = row3;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
        
        while(satisfied == false){
            cin << column3;
            if(column3 >= 0 && column3 < 6) {
                coordinateCol3 = column3;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        if(checkValidity(coordinateRow1, coordinateCol1) == true && checkValidity(coordinateRow2, coordinateCol2) == true 
            checkValidity(coordinateRow3, coordinateCol3) == true && 
            check3ValidNeighbors(coordinateRow1, coordinateCol1, coordinateRow2, coordinateCol2, coordinateRow3, coordinateCol3) == true){

            setPoint(coordinateRow1, coordinateCol1, 3);
            setPoint(coordinateRow2, coordinateCol2, 3);
            setPoint(coordinateRow3, coordinateCol3, 3);

            counter += 1
            if(counter == 3){
                valid = true;
                cout << "All points for this Wonderland have successfully been placed. Let's move on!" << endl << endl;
            }
            else {
                cout << "Point set successfully! Let's set the next point!" << endl << endl;
            }
        }
        else {
            cout << "Oops! Looks like one of the points you selected was already taken or not adjacent to the other coordinates. Remember,
             the coordinates have to be right next to each other on the grid (A1, A2 is valid, but A1, A3 is not). Try again." << endl << endl;
        }
    }
}

bool Wonderland::check3ValidNeighbors(char coordrow1, int col1, char coordrow2, int col2, char coordrow3, int row3){
    bool vertical = false;
    bool horizontal = false;
    int row1 = coordrow1 - 'a';
    int row2 = coordrow2 - 'a';
    int row3 = coordrow3 - 'a';
    char row1 = 'b';
    char row2 = 'd';
    char row3 = 'c';
    int col1 = 3;
    int col2 = 3;
    int col3 = 3;
    bool horizontal = false;
    bool vertical = false;
    
    if(row1 - row2 == 0 && row2 - row3 == 0){
        if((col1 - col2 >= -1 && col1 - col2 <= 1) && (col2 - col3 >= -1 && col2 - col3 <= 1))
            horizontal = true;
    }
    if(col1 - col2 == 0 && col2 - col3 == 0) {
        if((row1 - row2 >= -1 && row1 - row2 <= 1) || (row1 - row3 >= -1 && row1 - row3 <= 1)  && (row2 - row3 >= -1 && row2 - row3 <= 1))
            vertical = true;
    }
    
    if(horizontal == true && vertical == false || vertical == true && horizontal == false){
        return true;
    }
    return false;
    
}

