#include <iostream> 
#include <vector> 
#include "addBonus.hpp"
#include "AttemptsBoard.h"
#include "GameOver.h"
#include "GameState.hpp"
#include "GraphicsComposite.h"
#include "Graphics.h"
#include "MainBoard.h"
#include "Neighborhood.h"
#include "Nightmare.h"
#include "removeBonus.hpp"
#include "SkipTurn.h"
#include "visitor.hpp"
#include "Wonderland.h"
#include "Points.h"
#include "Text.h" 
#include <ctype.h>
#include "AutoWin.h"
#include "Attempts.h"
#include <stdlib.h>
#include<ios> //used to get stream size
#include<limits>

using namespace std; 

main(){
	vector<Neighborhood*> neighborhoods; 

//Player One seup 
	//set Theme
	Wonderland* player_one = new Wonderland();
	string name = "TEMPORARY"; 
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl; 
	cout << "                           SANTA'S DELIVERY SERVICE" << endl << endl; 
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
	cout << "          Hello, what is your name?" << endl;
	cout << "          Name: "; 
	cin >> name;
	cout << endl << endl << "--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --" << endl << endl;   

	player_one->setName(name); // AJ 

	//Create Board 
	GraphicsComposite* playerOneWindow = new GraphicsComposite(); // this will be the class with the vector to draw to the console
	
	 Graphics* textOne = new Text(1, name);
        playerOneWindow->add(textOne);

        Graphics* mainBoardOne = new MainBoard();
        playerOneWindow->add(mainBoardOne);

	Graphics* textBoarderOne = new Text(0, "");
        playerOneWindow->add(textBoarderOne);

        Graphics* attemptsBoardOne = new AttemptsBoard();
        playerOneWindow->add(attemptsBoardOne);

        Graphics* pointsGraphicOne = new Points(0);
        playerOneWindow->add(pointsGraphicOne);

        Graphics* attemptsGraphicOne = new Attempts();
        playerOneWindow->add(attemptsGraphicOne);


	playerOneWindow->drawBoard();
	
	//set Blocks
	player_one->setBlocks(); // will give options to set all the different blocks
	mainBoardOne->updateBoard(player_one->getGrid()); // shows where houses are located`


	//******************** TEMP CODE ****************************
	int** arr2 = player_one->getGrid();
        cout << "******************** TEMP CODE ****************************" << endl << endl;
	cout << "~~~~~~~~~~~~~~~~ " << player_one->getName() << "'s Grid ~~~~~~~~~~~~~~~~~~~~" << endl; 
        for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr2[i][j] << ",";
                }
                cout << endl;
        }

        cout << "******************* END TEMP CODE *************************" << endl;
	//******************* END TEMP CODE *************************

	playerOneWindow->drawBoard();
        
	cout << "          Player two's turn, press any key then press Enter when player two is ready" << endl; 
	char enter2;
	cin >> enter2;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	if(enter2 > 0){system("clear");} 

//Player Two setup

	//set theme	
	Neighborhood* player_two = new Nightmare();
     
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
        cout << "                           SANTA'S DELIVERY SERVICE" << endl << endl;
        cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
        cout << "          Hello, what is your name?" << endl;
        string name_two = "TEMP TWO";
	 cout << "          Name: "; 
        cin >> name_two;
	cout << endl << endl << "--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --" << endl << endl; 
        
	player_two->setName(name_two); // AJ 
	
	//create board
	GraphicsComposite* playerTwoWindow = new GraphicsComposite(); // this will be the class with the vector to draw to the console

	Graphics* textTwo = new Text(2 , name_two);
        playerTwoWindow->add(textTwo);

        Graphics* mainBoardTwo = new MainBoard();
        playerTwoWindow->add(mainBoardTwo);

	Graphics* textBoarder = new Text(0, "");
        playerTwoWindow->add(textBoarder);

        Graphics* attemptsBoardTwo = new AttemptsBoard();
        playerTwoWindow->add(attemptsBoardTwo);

        Graphics* pointsGraphicTwo = new Points(0);
        playerTwoWindow->add(pointsGraphicTwo);

        Graphics* attemptsGraphicTwo = new Attempts();
        playerTwoWindow->add(attemptsGraphicTwo);

    	
	playerTwoWindow->drawBoard();
	
	//set blocks
	player_two->setBlocks(); // will give options to set all the different blocks
        mainBoardTwo->updateBoard(player_two->getGrid()); // shows where houses are located`	

	int** arr3 = player_two->getGrid();
        cout << "******************** TEMP CODE ****************************" << endl;
	 cout << "~~~~~~~~~~~~~~~~ " << player_two->getName() << "'s Grid ~~~~~~~~~~~~~~~~~~~~" << endl;
        for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr3[i][j] << ",";
                }
                cout << endl;
        }

        cout << "******************* END TEMP CODE *************************" << endl;

	playerTwoWindow->drawBoard();

	//update visitor vector
	neighborhoods.push_back(player_one); 
    	neighborhoods.push_back(player_two);

//Game loop 
	int bonusValueTurns = -1; 
	int player_one_attempts = 1; 
	int player_two_attempts = 1;

	bool hitHouse = false; 
	bool missedHouse = false; 
	bool gotBonus = false; 
	bool skip = false; 
	bool deduct = false; 

	bool hitHouse2 = false;
        bool missedHouse2 = false;
        bool gotBonus2 = false;
        bool skip2 = false;

	int houseCount1 = 0; 
	int houseCount2 = 0; 
	
	while(player_one->getGameOver() == false && player_two->getGameOver() == false)
	{

	   if(player_one->getAttempts() > 0 && player_two->getAttempts() <= 1){
		if(player_one->getAttempts() == 2) {
			player_one->setAttempts(1);
			attemptsGraphicOne->updateAttempts(1);
		}
		cout << "_______________________________________________________________________________________" << endl << endl;
		cout << "************************ " << player_one->getName() << "'s Turn ************************" << endl;
		cout << "_______________________________________________________________________________________" << endl << endl;
		cout << "Press any key then press enter when "  << player_one->getName() << " is ready " << endl;   
		char enter = 0; 
		cin >> enter; 
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if(enter > 0){system("clear");}
	
		cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
        	cout << "                           SANTA'S DELIVERY SERVICE" << endl << endl;
        	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
		
		int** ar = player_two->getGrid();
        /*cout << "******************** TEMP CODE ****************************" << endl;
	 cout << "~~~~~~~~~~~~~~~~ " << player_two->getName() << "'s Grid ~~~~~~~~~~~~~~~~~~~~" << endl;
        for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << ar[i][j] << ",";
                }
                cout << endl;
        }

        cout << "******************* END TEMP CODE *************************" << endl;*/
		
		playerOneWindow->drawBoard();
		
		cout <<"          " <<  player_one->getName() << ", please enter a coordinate. For example \"A1\"" << endl;   
		string coordinate; 
		cin >> coordinate; 
	
		char x = 'z'; 
		int y = -1; 
		bool loop = true; 
		bool check = false; 

		while(loop){
			if(coordinate.size() > 1){
				x = tolower(coordinate.at(0));  // gets an x coordinate from the player. AJ - will this function ask the player to enter the coordinate? 
				cout << "X ----> " << x << endl; 
				y = coordinate.at(1) - '0'; // gets a y coordinate from the player
				cout << "Y ----> " << y << endl; 
				loop = false; 
			}
			
			if(x >= 97 && x <= 102 && y >= 0 && y <= 5){
				check = true;//checks if the coordinates are valid. 
			}

			if(loop == true || check == false){ 
				cout << "Invalid coordinate, please try again:" << endl;
				cin >> coordinate;
			} 
			
		}


	
	//player one's turn				this part is to check if player_two has extra attempts
			int value_two = player_two->retrieveCoordinate(x,y); //gets the value at those coordinates from palyer two
			cout << "Guess on Player Two's Board" << value_two <<  endl;		
			

			// if the value is a miss
			if(value_two == -1){
				player_two->miss(x, y); // needs to update the grid of player_two
                                attemptsBoardOne->updateBoard(player_two->getGrid());
                                cout << "Player one miss working :) " << endl; 
        			 missedHouse = true;
			}
			// if the value is between 30 and 0 then these are points
			if(value_two <= 30 && value_two > 0){ 
				 cout << "Player One hit working :)" << endl;
				player_one->addPoints(value_two); //check with AJ
				player_two->hit(x, y); // needs to update the grid of player_two
				attemptsBoardOne->updateBoard(player_two->getGrid());
				pointsGraphicOne->updatePoints(player_one->getPoints());  
				hitHouse = true;
				++houseCount1;
				if(houseCount1 == 5){player_one->setGameOver();}
			}
			//if the value equals the bonus coordinate value (check with AJ) 
                      	if(value_two == 40){ 
				 cout << "Player One Visitor working :)" << endl;
				cout << "SIZE ----> " << neighborhoods.size() << endl;
				for(int i = 0; i < neighborhoods.size(); ++i){
					cout << "GETTING ATTEMPTS ----> " << neighborhoods.at(i)->getAttempts() << endl;  
					neighborhoods.at(i)->accept(new AddBonus());  
        				 gotBonus = true;

				}
				//the players get three turns with this setting. After three turns it goes back to the normal setting
				bonusValueTurns = 3;
				mainBoardOne->updateBoard(player_one->getGrid()); //since getGrid() returns an array pointer I may not neet to do this b/c it'll automatically get updated									            when playerOneWindow->draw(); is called. 			 
				player_two->hit(x, y);
                                attemptsBoardOne->updateBoard(player_two->getGrid());
				--houseCount1;
			}
			//if the value is Skip Turn
			if(value_two == 50){
				 cout << "Player One SkipTurn working :)" << endl;
				player_one->setStratFunction(new SkipTurn()); //player_one or two??
				player_one->editGameState(); //editGameState will set player_one's attempts to zero
				attemptsGraphicOne->updateAttempts(0); 				 
				player_one_attempts = 0; 
        			skip = true;
				player_two->hit(x, y);
                                attemptsBoardOne->updateBoard(player_two->getGrid());
			}
			//if the value is AutoWin
			if(value_two == 60){
				 cout << "Player One AutoWin working :)" << endl;
                                player_one->setStratFunction(new AutoWin());
                                player_one->editGameState();
                                cout << "strategy working :) " << endl;
				player_two->hit(x, y);
                                attemptsBoardOne->updateBoard(player_two->getGrid());
			}
	
			//deduct points takes points away from player_one. If it hits a 70 it means it's a Wonder class b/c Nightmare won't have a 70 in it 
			if(value_two == 70){
				cout << "Player One DeductPoints working :)" << endl;
				player_one->deductPoints(); 
				pointsGraphicOne->updatePoints(player_one->getPoints());
				player_two->hit(x, y); 
				attemptsBoardOne->updateBoard(player_two->getGrid());
				attemptsGraphicOne->updateAttempts(player_one->getAttempts()); 		 
        			deduct = true;
			} 
						
		
		system("clear");				
			cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
                	cout << "                           SANTA'S DELIVERY SERVICE" << endl << endl;
                	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
	
			if(hitHouse == true){
				cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  YOU HIT A HOUSE!! :D  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
				hitHouse = false; 
			}
			if(missedHouse == true){
				cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  YOU MISSED :(  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
				missedHouse = false; 
			}
			if(gotBonus == true){
				cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  YOU HIT A BONUS POINT :D  *~*~*~*~*~*~*~*~*~*~*~* " << endl 
						  << "1. For the next three turns your houses will be worth double for your opponent" << endl 
						  << "2. Your opponents grid has one house that will be worth 30 points... if you can find it " << endl;
				gotBonus = false; 
			}
			if(skip == true){
				cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  Awww Sorry, we have to skip your turn once  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
				skip = false; 
			}
			if(deduct == true){
				cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  So sorry but we had to deduct your points," 
							    << " but to make up for it we're giving you an extra turn  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
				deduct = false; 
			}
			playerOneWindow->drawBoard(); 
		     }


// +++++++++++++++++++++++++++++++++++++++++  PLAYER TWO'S TURN   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 

	  if(player_two->getAttempts() > 0 && player_one->getAttempts() <= 1){
                cout << "_______________________________________________________________________________________" << endl << endl;
                cout << "************************ " << player_two->getName() << "'s Turn ************************" << endl;
                cout << "_______________________________________________________________________________________" << endl << endl;
                cout << "Press Enter when "  << player_two->getName() << " is ready " << endl;
                
//*******   clearing screen   ****************
		char  enter3 = 0;
                cin >> enter3;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        	if(enter3 > 0){system("clear");}

			cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
                        cout << "                           SANTA'S DELIVERY SERVICE" << endl << endl;
                        cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;


// ---------   creating array --------------------	
		/* int** arr5 = player_one->getGrid();
        cout << "******************** TEMP CODE ****************************" << endl;
         cout << "~~~~~~~~~~~~~~~~ " << player_one->getName() << "'s Grid ~~~~~~~~~~~~~~~~~~~~" << endl;
        for(int i = 0; i < 6; ++i){
                for(int j = 0; j < 6; ++j){
                        cout << arr5[i][j] << ",";
                }
                cout << endl;
        }

        cout << "******************* END TEMP CODE *************************" << endl;*/

// ```````````  Getting coordinates from player two ```````````````````
	
				

                playerTwoWindow->drawBoard();
                
                cout << "Please enter a coordinate. For example \"A1\"" << endl;
                string coordinate2;
                getline(cin,coordinate2);
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

                char x2 = 'z';
                int y2 = -1;
                bool loop2 = true;
                bool check2 = false;

                while(loop2){
                        if(coordinate2.size() > 1){
                                x2 = tolower(coordinate2.at(0));  // gets an x coordinate from the player. AJ - will this function ask the player to enter the coordinate? 
				cout << "X2 ----> " << x2 << endl; 
				y2 = coordinate2.at(1) - '0'; // gets a y coordinate from the player 
                                cout << "Y2 ----> " << y2 << endl;
				 loop2 = false;
                        }
                        
			if(x2 >= 97 && x2 <= 102 && y2 >= 0 && y2 <= 5){
                                check2 = true;//checks if the coordinates are valid. 
                        }                        

                        if(loop2 == true || check2 == false){ 
                                cout << "Invalid coordinate, please try again:" << endl;
                                cin >> coordinate2;
                        	cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
                 
                }
//************   Checking the coordinates that player two picked *****************************

			int value_one = player_one->retrieveCoordinate(x2,y2); //gets the value at those coordinates from palyer two
                         cout << "Guess on Player One's Board ---> " << value_one <<  endl; 
			 if(value_one == -1){
				cout << "Player Two miss working :)" << endl; 
                                player_one->miss(x2, y2); // needs to update the grid of player_two
                                attemptsBoardTwo->updateBoard(player_one->getGrid());
                		missedHouse2 = true;
			}

			if(value_one <= 30 && value_one > 0){
				cout << "Player Two hit working :)" << endl;
                                player_two->addPoints(value_one); //check with AJ
                                player_one->hit(x2, y2); // needs to update the grid of player_two
                                attemptsBoardTwo->updateBoard(player_one->getGrid());
                                pointsGraphicTwo->updatePoints(player_two->getPoints());
        			hitHouse2 = true;
				++houseCount2;
				if(houseCount2 == 5){player_two->setGameOver();}  
			}

			//if the value equals the bonus coordinate value (check with AJ)  
                        if(value_one == 40){
        			gotBonus2 = true;

                                for(int i = 0; i < neighborhoods.size(); ++i){
                                        neighborhoods.at(i)->accept(new AddBonus());
			        }
                                //the players get three turns with this setting. After three turns it goes back to the normal setting
                                bonusValueTurns = 3;
				player_one->hit(x2, y2);
                                mainBoardTwo->updateBoard(player_two->getGrid()); //since getGrid() returns an array pointer I may not neet to do this b/c it'll automatically get updated                                                                                when playerOneWindow->draw(); is called.                     
                        	attemptsBoardTwo->updateBoard(player_one->getGrid());
			}
                        //if the value is Skip Turn
                        if(value_one == 50){
        			skip2 = true; 
				cout << "Player Two skipTurns working :)" << endl;
                                player_two->setStratFunction(new SkipTurn()); //player_one or two??
                                player_two->editGameState(); //editGameState will set player_one's attempts to zero
                                player_one->hit(x2, y2);
				attemptsGraphicTwo->updateAttempts(0);
				attemptsBoardTwo->updateBoard(player_one->getGrid());
                                player_two_attempts = 0;
                        }

			
			if(value_one == 60){
				 cout << "Player Two AutoWin working :)" << endl;
                                player_two->setStratFunction(new AutoWin());
                                player_two->editGameState();
				player_one->hit(x2, y2);
				attemptsBoardTwo->updateBoard(player_one->getGrid());
				cout << "Working after AutoWin " << player_two->getGameOver() << endl; 
                        }
			
			
// **************  Clearing Console *******************************
		system("clear");

			 cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
                        cout << "                           SANTA'S DELIVERY SERVICE" << endl << endl;
                        cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;


			if(hitHouse2 == true){
                                cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  YOU HIT A HOUSE!! :D  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
                                hitHouse2 = false;
                        }
                        if(missedHouse2 == true){
                                cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  YOU MISSED :(  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
                                missedHouse2 = false;
                        }
                        if(gotBonus2 == true){
                                cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  YOU HIT A BONUS POINT :D  *~*~*~*~*~*~*~*~*~*~*~* " << endl
                                                  << "1. For the next three turns your houses will be worth double for your opponent" << endl
                                                  << "2. Your opponents grid has one house that will be worth 30 points... if you can find it " << endl;
                                gotBonus2 = false;
                        }
                        if(skip2 == true){
                                cout << endl << " *~*~*~*~*~*~*~*~*~*~*~*  Awww Sorry, we have to skip your turn once  *~*~*~*~*~*~*~*~*~*~*~* " << endl << endl;
                                skip2 = false;
                        }

			playerTwoWindow->drawBoard();

 		
	           }

	   

//#########################  If the SkipTurns() is set this checks how many times the player was skipped and then sets them back to 1 attempt 
		//if one of the players SkipTurn functions was set we want to count how many times we've passed them and then reset their turns. 
		//I created the player_one_attempts variable instead of adding an incrementAttempts function b/c I don't want to break encapsulation.  
		if(player_one_attempts > -2 && player_one_attempts <= 0){
			--player_one_attempts;
			if(player_one_attempts == -2){
				player_one->setAttempts(1);
				attemptsGraphicOne->updateAttempts(1);
				player_one_attempts = 1; 
			}
		}

		 if(player_two_attempts > -2 && player_two_attempts <= 0){
                        --player_two_attempts;
                        if(player_two_attempts == -2){
                                player_two->setAttempts(1);
				attemptsGraphicTwo->updateAttempts(1);
                                player_two_attempts = 1;
                        }
                }
//~~~~~~~~~~~~~~~~~  This updates the attemps if the AddBonus() class was called. It allows the Game loop to run three times untill it resets the attempts and 
		if(bonusValueTurns > 0) {--bonusValueTurns;}

		if(bonusValueTurns == 0){
			for(int i = 0; i < neighborhoods.size(); ++i){
                                        neighborhoods.at(i)->accept(new RemoveBonus());
                                }
                                //set turns back to -1 so this if statement isn't executed every time 
				bonusValueTurns = -1;
	        }	
	
    }

    if(player_one->getGameOver() == true) {cout <<  endl << endl << "*_*_*_*_*_*_*_*_*_*_*_*_*_*  PLAYER ONE IS THE WINNER!!! :)  *_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl<<  endl << endl;} 
    else  cout <<  endl << endl << "*_*_*_*_*_*_*_*_*_*_*_*_*_*  PLAYER TWO IS THE WINNER!!! :)  *_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl << endl << endl;
	
}
