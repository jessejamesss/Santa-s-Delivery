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
//#include "Neighborhood.hpp"
#include "Nightmare.h"
#include "removeBonus.hpp"
#include "SkipTurn.h"
#include "visitor.hpp"
#include "Wonderland.h"
#include "Points.h"
#include "Text.h" 


using namespace std; 

main(){
	vector<Neighborhood*> neighborhoods; 

//Player One seup 
	//set Theme
	Neighborhood* player_one;
	cout << "Hello, what is your name?" << endl;
	string name = "TEMPORARY"; 
	//cin >> name; 
	cout << name << ",  choose your theme, select 1 or 2" << endl;
	cout << "1. Wonderland" << endl;
	cout << "2. Nightmare" << endl;
	int theme;
	cin >> theme;
	if(theme == 1){player_one = new Wonderland();}
	else player_one = new Nightmare();
	//player_one->setName(name); // AJ 

	//Create Board 
	GraphicsComposite* playerOneWindow = new GraphicsComposite(); // this will be the class with the vector to draw to the console

        Graphics* mainBoardOne = new MainBoard();
        playerOneWindow->add(mainBoardOne);

        Graphics* attemptsBoardOne = new AttemptsBoard();
        playerOneWindow->add(attemptsBoardOne);

        Graphics* pointsGraphicOne = new Points(0);
        playerOneWindow->add(pointsGraphicOne);

        Graphics* attemptsGraphicOne = new AttemptsBoard;
        playerOneWindow->add(attemptsGraphicOne);

        Graphics* textOne = new Text(theme, name);
        playerOneWindow->add(textOne);

	//set Blocks
	player_one->setBlocks(); // will give options to set all the different blocks
	mainBoardOne->updateBoard(player_one->getGrid()); // shows where houses are located`

	playerOneWindow->drawBoard();

//Player Two setup

	//set theme	
	Neighborhood* player_two;
        cout << "Hello, what is your name?" << endl;
        string name_two = "TEMP TWO";
        //cin >> name_two;
        cout << name_two << ",  choose your theme, select 1 or 2" << endl;
        cout << "1. Wonderland" << endl;
        cout << "2. Nightmare" << endl;
        int theme_two;
        cin >> theme_two;
        if(theme_two == 1){player_two = new Wonderland();}
        else player_two = new Nightmare();
        //player_two->setName(name_two); // AJ 
	
	//create board
	GraphicsComposite* playerTwoWindow = new GraphicsComposite(); // this will be the class with the vector to draw to the console

        Graphics* mainBoardTwo = new MainBoard();
        playerTwoWindow->add(mainBoardTwo);

        Graphics* attemptsBoardTwo = new AttemptsBoard();
        playerTwoWindow->add(attemptsBoardTwo);

        Graphics* pointsGraphicTwo = new Points(0);
        playerTwoWindow->add(pointsGraphicTwo);

        Graphics* attemptsGraphicTwo = new AttemptsBoard();
        playerTwoWindow->add(attemptsGraphicTwo);

        Graphics* textTwo = new Text(theme_two, name_two);
        playerTwoWindow->add(textTwo);
    	
	//set blocks
	player_two->setBlocks(); // will give options to set all the different blocks
        mainBoardTwo->updateBoard(player_two->getGrid()); // shows where houses are located`	

	//update visitor vector
	neighborhoods.push_back(player_one); 
    	neighborhoods.push_back(player_two);

//Game loop 
	int bonusValueTurns = -1; 
	int player_one_attempts = 1; 
	int player_two_attempts = 1;

	while(player_one->getGameOver() == false && player_two->getGameOver() == false)
	{
		cout << "_______________________________________________________________________________________" << endl << endl;
		//cout << "************************ " << player_one->getName() << "'s Turn ************************" << endl;
		cout << "_______________________________________________________________________________________" << endl << endl;
		//cout << "Press Enter when "  << player_one->getName() << " is ready " << endl;   
		char enter; 
		cin >> enter; 

		playerOneWindow->drawBoard();
		
		cout << "Please enter a coordinate. For example \"A1\"" << endl;   
		string coordinate; 
		cin >> coordinate; 
	
		char x = 'z'; 
		int y = -1; 
		bool loop = true; 
		bool check = false; 

		while(loop){
			if(coordinate.size() > 1){
				x = coordinate.at(0);  // gets an x coordinate from the player. AJ - will this function ask the player to enter the coordinate? 
				y = coordinate.at(1); // gets a y coordinate from the player 
				loop = false; 
			}
			
			check = player_two->checkValidity(x,y);//checks if the coordinates are valid. 
			
			if(loop == true || check == false){ 
				cout << "Invalid coordinate, please try again:" << endl;
				cin >> coordinate;
			} 
			
		}


		if(check == true)
		{
	//player one's turn				this part is to check if player_two has extra attempts
		    if(player_one->getAttempts() > 0 && player_two->getAttempts() <= 1){
			int value_two = player_two->retrieveCoordinate(x,y); //gets the value at those coordinates from palyer two
			
			// if the value is a miss
			if(value_two == -1){
				//player_two->miss(x, y); // needs to update the grid of player_two
                                //attemptsBoardOne->updateBoard(player_two->getGrid());
                                cout << "miss working :) " << endl; 
			}
			// if the value is between 30 and 0 then these are points
			if(value_two <= 30 && value_two > 0){ 
				player_one->addPoints(value_two); //check with AJ
				//player_two->hit(x, y); // needs to update the grid of player_two
				attemptsBoardOne->updateBoard(player_two->getGrid());
				pointsGraphicOne->updatePoints(player_one->getPoints());  
			}
			//if the value equals the bonus coordinate value (check with AJ) 
                      	if(value_two == 40){ 
				for(int i = 0; i < neighborhoods.size(); ++i){ 
					neighborhoods.at(i)->accept(new AddBonus());  
				}
				//the players get three turns with this setting. After three turns it goes back to the normal setting
				bonusValueTurns = 3;
				mainBoardOne->updateBoard(player_one->getGrid()); //since getGrid() returns an array pointer I may not neet to do this b/c it'll automatically get updated									            when playerOneWindow->draw(); is called. 			 
			}
			//if the value is Skip Turn
			if(value_two == 50){
				player_one->setStratFunction(new SkipTurn()); //player_one or two??
				//player_one->editGameState(); //editGameState will set player_one's attempts to zero
				attemptsGraphicOne->updateAttempts(0); 				 
				player_one_attempts = 0; 
			}
			//if the value is AutoWin
			if(value_two == 60){
                                //player_one->setStratFunction(new AutoWin());
                                //player_one->editGameState();
                                cout << "strategy working :) " << endl;
                        }
	
			//deduct points takes points away from player_one. If it hits a 70 it means it's a Wonder class b/c Nightmare won't have a 70 in it 
			if(value_two == 70){

				//player_one->deductPoints(); 
				pointsGraphicTwo->updatePoints(player_one->getPoints());
				attemptsGraphicOne->updateAttempts(player_one->getAttempts()); 		 
			} 
			
		
			playerOneWindow->drawBoard(); 
		     }

	//player two's turn 


                cout << "_______________________________________________________________________________________" << endl << endl;
                //cout << "************************ " << player_two->getName() << "'s Turn ************************" << endl;
                cout << "_______________________________________________________________________________________" << endl << endl;
                //cout << "Press Enter when "  << player_two->getName() << " is ready " << endl;
                char enter2;
                cin >> enter2;

                playerTwoWindow->drawBoard();
                
                cout << "Please enter a coordinate. For example \"A1\"" << endl;
                string coordinate2;
                cin >> coordinate2;

                char x2 = 'z';
                int y2 = -1;
                bool loop2 = true;
                bool check2 = false;

                while(loop2){
                        if(coordinate2.size() > 1){
                                x2 = coordinate2.at(0);  // gets an x coordinate from the player. AJ - will this function ask the player to enter the coordinate? 
                                y2 = coordinate2.at(1); // gets a y coordinate from the player 
                                loop2 = false;
                        }
                        
                        check2 = player_one->checkValidity(x2,y2);//checks if the coordinates are valid. 
                        
                        if(loop2 == true || check2 == false){ 
                                cout << "Invalid coordinate, please try again:" << endl;
                                cin >> coordinate2;
                        }
                 
                }
//************
		   if(player_two->getAttempts() > 0 && player_one->getAttempts() <= 1){
			int value_one = player_one->retrieveCoordinate(x,y); //gets the value at those coordinates from palyer two
                        
			 if(value_one == -1){
                                //player_one->miss(x, y); // needs to update the grid of player_two
                                attemptsBoardTwo->updateBoard(player_one->getGrid());
                        }

			if(value_one <= 30){
                                player_two->addPoints(value_one); //check with AJ
                                //player_one->hit(x, y); // needs to update the grid of player_two
                                attemptsBoardTwo->updateBoard(player_two->getGrid());
                                pointsGraphicTwo->updatePoints(player_two->getPoints());
                        }

			//if the value equals the bonus coordinate value (check with AJ)  
                        if(value_one == 40){
                                for(int i = 0; i < neighborhoods.size(); ++i){
                                        neighborhoods.at(i)->accept(new AddBonus());
                                }
                                //the players get three turns with this setting. After three turns it goes back to the normal setting
                                bonusValueTurns = 3;
                                mainBoardTwo->updateBoard(player_two->getGrid()); //since getGrid() returns an array pointer I may not neet to do this b/c it'll automatically get updated                                                                                when playerOneWindow->draw(); is called.                     
                        }
                        //if the value is Skip Turn
                        if(value_one == 50){
                                player_two->setStratFunction(new SkipTurn()); //player_one or two??
                                //player_two->editGameState(); //editGameState will set player_one's attempts to zero
                                attemptsGraphicTwo->updateAttempts(0);
                                player_two_attempts = 0;
                        }

			
			if(value_one == 60){
                                //player_two->setStratFunction(new AutoWin());
                                //player_two->editGameState();
                        }
			
                        if(value_one == 70){

                                //player_two->deductPoints();
                                pointsGraphicTwo->updatePoints(player_two->getPoints());
                                attemptsGraphicTwo->updateAttempts(player_two->getAttempts());
                        }
			
		
			playerTwoWindow->drawBoard(); 		
	           }
		//if one of the players SkipTurn functions was set we want to count how many times we've passed them and then reset their turns. 
		//I created the player_one_attempts variable instead of adding an incrementAttempts function b/c I don't want to break encapsulation.  
		if(player_one_attempts > -2 && player_one_attempts <= 0){
			--player_one_attempts;
			if(player_one_attempts == -2){
				player_one->setAttempts(1);
				player_one_attempts = 1; 
			}
		}

		 if(player_two_attempts > -2 && player_two_attempts <= 0){
                        --player_two_attempts;
                        if(player_two_attempts == -2){
                                player_two->setAttempts(1);
                                player_two_attempts = 1;
                        }
                }

		if(bonusValueTurns > 0) {--bonusValueTurns;}

		if(bonusValueTurns == 0){
			for(int i = 0; i < neighborhoods.size(); ++i){
                                        neighborhoods.at(i)->accept(new RemoveBonus());
                                }
                                //set turns back to -1 so this if statement isn't executed every time 
				bonusValueTurns = -1;
		}	
	}
    }	
}
