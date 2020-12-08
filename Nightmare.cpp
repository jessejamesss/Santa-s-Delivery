#include "Nightmare.h"
//#include "Neighborhood.h"

using namespace std;

Nightmare::Nightmare(){
    points = 0;
    theme = "Nightmare";
    attempts = 1;
    gameOver = false;
    BonusCoordinateX = 0; 
    BonusCoordinateY = 0; 
	
    grid = new int*[6];
          int val = 0;
          for(int i = 0; i < 6; ++i)
          {
              grid[i] = new int[6];
              for(int j = 0; j < 6; ++j)
              {
                      ++val;
                      grid[i][j] = -1;
               }
           }
}
void Nightmare::accept(Visitor* v){
	v->visitNightmare(this);
}

void Nightmare::setAttempts(int x){
	attempts = x;
}
void Nightmare::setGameOver(){
	gameOver = true;
}

void Nightmare::setBonusCoordinateX(int row){
	BonusCoordinateX = row; 
}

void Nightmare::setBonusCoordinateY(int col){
	BonusCoordinateY = col; 
}

void Nightmare::setStratFunction(Strategy* strat) {
    s = strat;
}

void Nightmare::setStratCoords(){
    bool empty =  false;
    int xCoord;
    int yCoord;
    srand(time(NULL));   

    while(empty != true){
        xCoord = rand() % 5;
        yCoord = rand() % 5;
        if(grid[xCoord][yCoord] == -1){
            empty = true;
            grid[xCoord][yCoord] = 40;
        }
    }

    empty = false;
    
    srand(time(NULL));
    while(empty != true){ 
        xCoord = rand() % 5;
        yCoord = rand() % 5;
        if(grid[xCoord][yCoord] == -1){
            empty = true;
            grid[xCoord][yCoord] = 50;
        }
    }

    empty = false;
    srand(time(NULL));
    while(empty != true) {
        xCoord = rand() % 5;
        yCoord = rand() % 5;
        if(grid[xCoord][yCoord] == -1){
            empty = true;
            grid[xCoord][yCoord] = 60;
        }
    }
    empty = false;

    srand(time(NULL));
    while(empty != true){
        xCoord = rand() % 5;
        yCoord = rand() % 5;
        if(grid[xCoord][yCoord] == -1){
            empty = true;
            grid[xCoord][yCoord] = 70;
        }
    }


}

Nightmare::~Nightmare(){delete []grid;}

//int (&Nightmare::getGrid())[6][6] { return tempGrid; }

int** Nightmare::getGrid(){

       return grid;
}

int Nightmare::getBonusCoordinateX(){
	return BonusCoordinateX; 	
}

int Nightmare::getBonusCoordinateY(){
	return BonusCoordinateY; 
}

int Nightmare::retrieveCoordinate(char x, int y){
    int index = x - 'a';
    return grid[index][y];
}

int Nightmare::getPoints(){
    return points;
}

char Nightmare::getXCoordinate() {
    return coordinateX;
}

int Nightmare::getYCoordinate(){
    return coordinateY;
}


void Nightmare::addPoints(int addPts){
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
	return false; 
}



void Nightmare::setPoints(char x, int index2, int type){
    int index1 = x - 'a';
    grid[index1][index2] = type;
}

void Nightmare::twoNeighborhoods() {
    char row1, row2;
    int column1, column2;
    bool satisfied = false;
    char coordinateRow1;
    int coordinateCol1;
    char coordinateRow2;
    int coordinateCol2;
    bool valid = false;
    int counter = 0; 
    char temp;
    while(valid == false){
        cout << "\nPlease select a row on the grid where you want to place your first Coordinate for your Nightmare of 2 (A-F)\n";
        while(satisfied == false){
            cin >> row1;
            row1 = tolower(row1);
            if(row1 == 'a' ||row1 == 'b' ||row1 == 'c' ||row1 == 'd' || row1 == 'e' ||row1 == 'f'){
                coordinateRow1 = row1;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
        
        while(satisfied == false){
            cin >> temp;
	    if(isdigit(temp) == true) {
		column1 = temp - '0';
           	 if(column1 >= 0 && column1 < 6) {
                	coordinateCol1 = column1; // maybe change to one specific variable later
                	satisfied = true;
           	 }
            }
	    else {
              	cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a row on the grid where you want to place your second Coordinate for your Nightmare of 2 (A-F)\n";
        while(satisfied == false){
            cin >> row2;
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
            cin >> temp;
            if(isdigit(temp) == true) {
                column2 = temp - '0';
           	if(column2 >= 0 && column2 < 6) {
               	   coordinateCol2 = column2;
                   satisfied = true;
            	}
	   }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied
        
        if(checkValidity(coordinateRow1, coordinateCol1) == true && checkValidity(coordinateRow2, coordinateCol2) == true && check2ValidNeighbors(coordinateRow1, coordinateCol1, coordinateRow2, coordinateCol2) == true){
            setPoints(coordinateRow1, coordinateCol1, 5);
            setPoints(coordinateRow2, coordinateCol2, 5);
            valid = true;
	    cout << "Neighborhood set successfully! Let's set the next points!" << endl << endl;
 
	   // counter += 1;
           // if(counter == 2){
           //     valid = true;
           // }
           // else {
            //    cout << "Point set successfully! Let's set the next point!" << endl << endl;
           // }
        }
        else {
            cout << "Oops! Looks like one of the points you selected was already taken or not adjacent to the other coordinates. Remember,the coordinates have to be right next to each other on the grid (A1, A2 is valid, but A1, A3 is not). Try again." << endl << endl;
        }
    }
}



bool Nightmare::check2ValidNeighbors(char coordrow1, int col1, char coordrow2, int col2){
    bool vertical = false;
    bool horizontal = false;
    int row1 = coordrow1 - 'a';
    int row2 = coordrow2 - 'a';
   
    if(row1 - row2 == 0 && (col1 - col2 >= -1 && col1 - col2 <= 1)){
        horizontal = true;
    }
    
    if(col1 - col2 == 0 && (row1 - row2 >= -1 && row1 - row2 <= 1)) {
        vertical = true;
    }

    
    if(horizontal == true && vertical == false || vertical == true && horizontal == false){
        return true;
    }
    return false;
}




void Nightmare::threeNeighborhoods() {
    char row1, row2, row3;
    int column1, column2, column3;
    bool satisfied = false;
    char coordinateRow1;
    int coordinateCol1;
    char coordinateRow2;
    int coordinateCol2;
    char coordinateRow3;
    int coordinateCol3;
    int counter = 0; 
    char temp;
    bool valid = false;

    while(valid == false){
        cout << "\nPlease select a row on the grid where you want to place your first Coordinate for your Nightmare of 3 (A-F)\n";
        while(satisfied == false){
            cin >> row1;
            row1 = tolower(row1);
            if(row1 == 'a' ||row1 == 'b' ||row1 == 'c' ||row1 == 'd' || row1 == 'e' ||row1 == 'f'){
                coordinateRow1 = row1;
                satisfied = true;
            }
            else {
                cout << "\nThat is not a valid row. Please select a row between the letters A - F\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a column that corresponds with the row you just selected (0 - 5)";
        
        while(satisfied == false){
            cin >> temp;
            if(isdigit(temp) == true) {
                column1 = temp - '0';
            	if(column1 >= 0 && column1 < 6) {
                coordinateCol1 = column1; // maybe change to one specific variable later
                satisfied = true;
            	}
	    }
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a row on the grid where you want to place your second Coordinate for your Nightmare of 3 (A-F)\n";
        while(satisfied == false){
            cin >> row2;
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
            cin >> temp;
            if(isdigit(temp) == true) {
                column2 = temp - '0';
                if(column2 >= 0 && column2 < 6) {
               	    coordinateCol2 = column2;
                    satisfied = true;
    	        }
            }
	    else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        cout << "\nPlease select a row on the grid where you want to place your third Coordinate for your Nightmare of 3 (A-F)\n";

        while(satisfied == false){
            cin >> row3;
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
            cin >> temp;
            if(isdigit(temp) == true) {
                column3 = temp - '0';
                if(column3 >= 0 && column3 < 6) {
                     coordinateCol3 = column3;
                     satisfied = true;
                 }
	   } 
            else {
                cout << "\nThat is not a valid column. Please select a column between the numbers 0 - 5\n";
            }
        }
        satisfied = false; // resets the satisfied

        if(checkValidity(coordinateRow1, coordinateCol1) == true && checkValidity(coordinateRow2, coordinateCol2) == true && 
            checkValidity(coordinateRow3, coordinateCol3) == true && 
            check3ValidNeighbors(coordinateRow1, coordinateCol1, coordinateRow2, coordinateCol2, coordinateRow3, coordinateCol3) == true){

            setPoints(coordinateRow1, coordinateCol1, 3);
            setPoints(coordinateRow2, coordinateCol2, 3);
            setPoints(coordinateRow3, coordinateCol3, 3);
            valid = true;
	    cout << "Neighborhood set successfully! Let's set the next points!" << endl << endl;

           // counter += 1;
           // if(counter == 3){
            //    valid = true;
            //    cout << "All points for this Nightmare have successfully been placed. Let's move on!" << endl << endl;
           // }
           // else {
           //     cout << "Point set successfully! Let's set the next point!" << endl << endl;
           // }
        }
        else {
            cout << "Oops! Looks like one of the points you selected was already taken or not adjacent to the other coordinates. Remember, the coordinates have to be right next to each other on the grid (A1, A2 is valid, but A1, A3 is not). Try again." << endl << endl;
        }
    }
}




bool Nightmare::check3ValidNeighbors(char coordrow1, int col11, char coordrow2, int col22, char coordrow3, int col33){
    bool vertical = false;
    bool horizontal = false;
    int row1 = coordrow1 - 'a';
    int row2 = coordrow2 - 'a';
    int row3 = coordrow3 - 'a';
    int col1 = col11;
    int col2 = col22;
    int col3 = col33;
    
    if(row1 == row2 && col1 == col2){
        return false;
    }

    if(row2 == row3 && col2 == col3){
        return false;
    }

    if(row1 == row3 && col1 == col3){
        return false;
    }
    // check to see if any of the points are equal to each other
    if(row1 - row2 == 0 && row2 - row3 == 0){
        if(((col1 - col2 >= -1 && col1 - col2 <= 1) && (col2 - col3 >= -1 && col2 - col3 <= 1)) || ((col3 - col1 >= -1 && col3 - col1 <= 1) && (col2 - col3 >= -1 && col2 - col3 <= 1)) || ((col3 - col1 >= -1 && col3 - col1 <= 1) && (col2 - col1 >= -1 && col2 - col1 <= 1)))
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
void Nightmare::setBlocks(){

    twoNeighborhoods(); // 3
    threeNeighborhoods();
    setStratCoords();	
}
