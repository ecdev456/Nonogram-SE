//
//  main.cpp
//  hw1SE
//
//  Created by faraz ismail on 1/10/18.
//  Copyright © 2018 acad3mics. All rights reserved.
//

#include <iostream>
#include "picross.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "hello player weclome to picross game!\n";
    cout << "Create the Letter M on the grid to win the game!";
    picross game;
     game.createGrid();
     game.printGrid();
    bool win = false;
    while (win != true){
    // THis is where tristans Menu would go
        
    // If user chooses Pick move call game.pickmove()
        
    // If user chooses Delete move call game.deletemove()
        
    // There should be a count for trys and if trys = 14 because that is the minimum number of tries needed to win the game picking all correct squares
    // Then call win = game.win() to see if player has won the game
        
    // Print Grid should be called after every choice to print grid for player
    }
        return 0;
}
