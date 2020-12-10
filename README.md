 # Santa's Delivery
 > Authors: \<[Alina Krishcko](https://github.com/Aika87)\> \<[Pukhraj Falak](https://github.com/psfalak)\> \<[Jesse James Ordona](https://github.com/jessejamesss)\>

## Project Description
 > ## Phase I
 > * Why is it important or interesting to you?
 >   * Santa's Delivery is a spin off the game Battleship. We find it interesting because we are taking an original game and putting our own twist to it since Christmas is around the corner.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * We will be using C++. 
 > * What will be the input/output of your project?
 >   * The input of our project will be a mouse click on a coordinate box. The output will be a sign of whether the coordinate clicked was correct or not.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Composite - The composite design pattern will be useful in our project because we want to output to the console a drawing of an updated version of the grid. This grid will act as the board for the game. As the game progresses, players will be asked to enter coordinates and some of those coordinates will contain a house. If a coordinate with a house is called, then the composite design pattern will allow us to update and draw the player’s board to indicate that the coordinate that they have chosen was correct and contained a house. If the coordinate did not contain a house, the composite design pattern will also allow us to update and draw the board to indicate that no house was in that coordinate.
 >   * Visitor - The visitor pattern will fit our project because we want to have a base class which has three subclasses. However, instead of redefining the same functions in all three subclasses we will have a concrete visitor class which will take in one of the three subclasses and perform the operation on that subclass. This will simplify our design and help prevent us from writing redundant code. 
 >   * Strategy: The strategy pattern will be useful for our project because it will allow us to use virtual and pure virtual functions. We plan on using these functions in our neighborhood classes, as they all need to be implemented differently. This fits perfectly with the strategy design pattern, as it allows us to make objects interchangeable inside the original context object. This will allow us to simplify our base class and made our code cleaner. 

 > ## Phase II
Our Main file will be able to call the Graphics Class, the Neighborhood Class and the Visitor Class. The Neighborhood Class will be the only one to have access to the Strategy Class. The Neighborhood Class is an abstract class which has all pure virtual functions which will be overwritten by the two Subclasses WinterWonderland Class and NightmareBeforeChristmas Class. The Visitor Class will be able to visit the two Neighborhood Subclasses and update something different in both of them. There will be a vector of Neighborhoods in Main which will be used to set the specific function of the Visitor Class that needs to be used at that time. Sometimes the AddBonus class will need to be called on both of the subclasses and sometimes the RemoveBonus Class will need to be called and that will be decided in Main at run-time. The Neighborhood Class will have an instance of the Visitor class which will be set by Main. Anytime one of the functions is called it will perform something different in both subclasses. The Graphics class will be the Component of the Composite design pattern. The Graphics class will include a class called GraphicsComposite which will serve as the Composite of the Composite design pattern. The MainBoard, AttemptsBoard, Text, Points, and Attempts classes will serve as the primitives. The purpose of this whole class is to draw the board, so that the players will continue to see updated versions as they make their moves. For example, if a player guesses the coordinate of a house correctly, then the HitHouse class will be able to update the board with an image indicating that a house has been hit, and then draw it. Our strategy class is an aggregation of the neighborhood class. This pattern will make the game more interesting by adding fun twists to the gameplay. One player will have a coordinate that allows them to automatically win the game, while the other player will have multiple coordinates that allows them to gain an extra attempt on the next turn. Each player is restricted to one of these benefits, meaning a single player cannot automatically win the game and have coordinates that give them extra turns. 

## Class Diagram
 https://github.com/cs100/final-project-jordo018-akris023-pfala001/blob/master/OMT%20Diagram.pdf

 > ## Final deliverable
 ## Screenshots
 ![test image](https://github.com/cs100/final-project-jordo018-akris023-pfala001/blob/master/CS100%20Project%20SS1.png)
 ![test image2](https://github.com/cs100/final-project-jordo018-akris023-pfala001/blob/master/CS100%20Project%20SS2.png)
 ![test image3](https://github.com/cs100/final-project-jordo018-akris023-pfala001/blob/master/CS100%20Project%20SS3.png)
 ![test image4](https://github.com/cs100/final-project-jordo018-akris023-pfala001/blob/master/CS100%20Project%20SS4.png)
 ![test image5](https://github.com/cs100/final-project-jordo018-akris023-pfala001/blob/master/CS100%20Project%20SS5.png)
 ## Installation/Usage
 > Instructions on installing and running your application
 > * To install our project, you would have to clone our project's repository and run it in terminal.
 > * To compile our project first run the command "cmake3 .". After, run the command "make". Finally, run the project using "./main".
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 > * To test our project, we used Google's Unit Test Framework for C++. We utilized the Google Unit Test Framework to create unit tests for each of our classes that implemented our respective features.
 
