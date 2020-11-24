#include <iostream> 
#include <vector> 

using namespace std; 

main(){
	vector<Neighborhood*> neighborhoods; 

//Player One seup 
	//set Theme
	Neighborhood* player_one;
	cout << "Hello, what is your name?" << endl;
	string name; 
	cin >> name; 
	cout << name ",  choose your theme, select 1 or 2" << endl;
	cout << "1. Wonderland" << endl;
	cout << "2. Nightmare" << endl;
	int theme;
	cin >> theme;
	if(theme == 1){player_one = new Wonderland();}
	else player_one = new Nightmare();
	player_one->setName(name); // AJ 

	//Create Board 
	Graphic playerOneWindow = new GraphicsComposite(); // this will be the class with the vector to draw to the console

        Graphic mainBoardOne = new MainBoard();
        playerOneWindow->add(mainBoardOne);

        Graphic attemptsBoardOne = new AttemptsBoard();
        playerOneWindow->add(attemptsBoardOne);

        Graphic pointsGraphicOne = new Points();
        playerOneWindow->add(pointsGraphicOne);

        Graphic attemptsGraphicOne = new Attempts();
        playerOneWindow->add(attemptsGraphicOne);

        Graphic textOne = new Text(theme, name);
        playerOneWindow->add(textOne);

	//set Blocks
	player_one->setBlocks(); // will give options to set all the different blocks
	mainBoardOne->update(player_one.getGrid()); // shows where houses are located`

	playerOneWindow->draw();

//Player Two setup

	//set theme	
	Neighborhood* player_two;
        cout << "Hello, what is your name?" << endl;
        string name_two;
        cin >> name_two;
        cout << name_two ",  choose your theme, select 1 or 2" << endl;
        cout << "1. Wonderland" << endl;
        cout << "2. Nightmare" << endl;
        int theme_two;
        cin >> theme_twp;
        if(theme_two == 1){player_two = new Wonderland();}
        else player_two = new Nightmare();
        player_two->setName(name); // AJ 
	
	//create board
	Graphic playerTwoWindow = new GraphicsComposite(); // this will be the class with the vector to draw to the console

        Graphic mainBoardTwo = new MainBoard();
        playerTwoWindow->add(mainBoardTwo);

        Graphic attemptsBoardTwo = new AttemptsBoard();
        playerTwoWindow->add(attemptsBoardTwo);

        Graphic pointsGraphicTwo = new Points();
        playerTwoWindow->add(pointsGraphicTwo);

        Graphic attemptsGraphicTwo = new Attempts();
        playerTwoWindow->add(attemptsGraphicTwo);

        Graphic textTwp = new Text(theme_two, name_two);
        playerTwoWindow->add(textTwo);
    	
	//set blocks
	player_two->setBlocks(); // will give options to set all the different blocks
        mainBoardTwo->update(player_two.getGrid()); // shows where houses are located`	

	//update visitor vector
	neighborhoods.push_back(player_one); 
    	neighborhoods.push_back(player_two);

	while(player_one.getGameOver() == false && player_two.getGameOver == false)
	{
	//	cout << "_______________________________________________________________________________________" << endl << endl;
	//	cout << "************************ " << player_one.getName() << "'s Turn ************************" << endl;
	//	cout << "_______________________________________________________________________________________" << endl << endl;
	//	cout << "Press Enter when "  << player_one.getName() << " is ready " << endl;   
	//	char enter; 
	//	cin >> enter; 
		
		playerOneWindow->draw(); 
		int x = player_one.getXCoordinate(); // gets an x coordinate from the player
		char y = player_one.getYCoordinate(); // gets a y coordinate from the player 
		bool check = player_two.checkBounds(x,y);//checks if the coordinates are valid 
		if(check == true)
		{
	//player one's turn
		    if(player_two->getAttempts() > 0){
			int value_two = player_two.retrieveCoordinate(x,y); //gets the value at those coordinates from palyer two
			
			// if the value is a miss
			if(value_two == -1){
				player_two->miss(x, y); // needs to update the grid of player_two
                                attemptsBoardOne->update(player_two.getGrid());
			}
			// if the value is less than 30 then these are points
			if(value_two <= 30){ 
				player_one->addPoints(value_two); //check with AJ
				player_two->hit(x, y); // needs to update the grid of player_two
				attemptsBoardOne->update(player_two.getGrid());
				pointsGraphicOne->update(player_one.getPoints());  
			}
			//if the value equals the bonus coordinate value (check with AJ) 
                      	if(value_two == 40){ 
				for(int i = 0; i < neighborhoods.size(); ++i){ 
					Neighborhoods.at(i)->accept(new AddBonus());  
				}
			}
			//if the value is Skip Turn
			if(value_two == 50){
				player_one->setStrategyFunction(new SkipTurn()); //player_one or two??
				player_one->editGameState();
						 
			}
			//if the value is AutoWin
			if(value_two == 60){
                                player_one->setStrategyFunction(new AutoWin());
                                player_one->editGameState();
                        }
			
			playerOneWindow->draw(); 
		     }

	//player two's turn 
		   if(player_two->getAttempts() > 0){
			int value_one = player_one.retrieveCoordinate(x,y); //gets the value at those coordinates from palyer two
                        
			 if(value_one == -1){
                                player_one->miss(x, y); // needs to update the grid of player_two
                                attemptsBoardTwo->update(player_one->getGrid());
                        }

			if(value_one <= 30){
                                player_two->addPoints(value_one); //check with AJ
                                player_one->hit(x, y); // needs to update the grid of player_two
                                attemptsBoardTwo->update(player_two.getGrid());
                                pointsGraphicTwo->update(player_two.getPoints());
                        }


			if(value_one == 40){
                                for(int i = 0; i < neighborhoods.size(); ++i){
                                        Neighborhoods.at(i)->accept(new AddBonus());
                                }
                        }

			if(value_one == 50){
                                player_two->setStrategyFunction(new SkipTurn()); //player_one or two??
                                player_two->editGameState();
				player_two->setAttempts(0); 
				attemptsGraphicTwo->update(); 			
                        }

			if(value_one == 60){
                                player_two->setStrategyFunction(new AutoWin());
                                player_two->editGameState();
                        }
			
			playerTwoWindow->draw(); 		
	           }
	}
}	
