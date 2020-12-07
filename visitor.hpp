#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <iostream> 
#include "Neighborhood.h"
//#include "Nightmare.h"

using namespace std; 

class Neighborhood; 

class Visitor{

public: 
      Visitor(){};  

//	Neighborhood* player1 = new Nightmare();
	
       virtual void visitWonderland(Neighborhood* n) = 0; 
       virtual void visitNightmare(Neighborhood* n) = 0;

}; 


#endif  
