 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Santa's Delivery
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Alina Krishcko](https://github.com/Aika87)\> \<[Pukhraj Falak](https://github.com/psfalak)\> \<[Jesse James Ordona](https://github.com/jessejamesss)\>
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 >   * Santa's Delivery is a spin off the game Battleship. We find it interesting because we are taking an original game and putting our own twist to it since Christmas is around the corner.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [SFML](https://www.sfml-dev.org/) - SFML is a C++ library whish allows graphic for c++
 >   * We will be using C++ 
 > * What will be the input/output of your project?
 >   * The input of our project will be a mouse click on a coordinate box. The output will be a sign of whether the coordinate clicked was correct or not.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Proxy- The proxy design pattern will be useful in our project because we want to check if the user’s input, the mouse click, is correct. The proxy will be able to determine whether the user input is correct or not and will relay this information to another class. When the information is relayed, the class will determine what to do based on if the coordinate the user clicked is right or not. For example, if the coordinate is correct, then a present will be delivered.
 >   * Visitor - The visitor pattern will fit our project because we want to have a base class which has three subclasses. However, instead of redefining the same functions in all three subclasses we will have a concrete visitor class which will take in one of the three subclasses and perform the operation on that subclass. This will simplify our design and help prevent us from writing redundant code. 
 >   * Strategy: The strategy pattern will be useful for our project because it will allow us to use virtual and pure virtual functions. We plan on using these functions in our neighborhood classes, as they all need to be implemented differently. This fits perfectly with the strategy design pattern, as it allows us to make objects interchangeable inside the original context object. This will allow us to simplify our base class and made our code cleaner.

 This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 

 > ## Phase II
Our Main file will be able to call the Graphics Class, the Neighborhood Class and the Visitor Class. The Neighborhood Class will be the only one to have access to the Strategy Class. The Neighborhood Class is an abstract class which has all pure virtual functions which will be overwritten by the two Subclasses WinterWonderland Class and NightmareBeforeChristmas Class. The Visitor Class will be able to visit the two Neighborhood Subclasses and update something different in both of them. There will be a vector of Neighborhoods in Main which will be used to set the specific function of the Visitor Class that needs to be used at that time. Sometimes the AddBonus class will need to be called on both of the subclasses and sometimes the RemoveBonus Class will need to be called and that will be decided in Main at run-time. The Neighborhood Class will have an instance of the Visitor class which will be set by Main. Anytime one of the functions is called it will perform something different in both subclasses. The Graphics class will be the Component of the Composite design pattern. The Graphics class will include a class called GraphicsComposite which will serve as the Composite of the Composite design pattern. The HitHouse, MissedHouse, GameText, and GridBorder classes will serve as the primitives. The purpose of this whole class is to draw the board, so that the players will continue to see updated versions as they make their moves. For example, if a player guesses the coordinate of a house correctly, then the HitHouse class will be able to update the board with an image indicating that a house has been hit, and then draw it. Our strategy class is an aggregation of the neighborhood class. This pattern will make the game more interesting by adding fun twists to the gameplay. One player will have a coordinate that allows them to automatically win the game, while the other player will have multiple coordinates that allows them to gain an extra attempt on the next turn. Each player is restricted to one of these benefits, meaning a single player cannot automatically win the game and have coordinates that give them extra turns. 

## Class Diagram
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
