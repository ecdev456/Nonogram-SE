//
//  picross.h
//  hw1SE
//
//  Created by faraz ismail on 1/10/18.
//  Copyright © 2018 acad3mics. All rights reserved.
//

#ifndef picross_h
#define picross_h
using namespace std;
int const size = 5; //global size
char myArray[5][5]; // global char array for user inputs
class picross
{

public:
    // set default empty board
    
        void createGrid(){
         
        for(int count = 0; count < 5; count++){
            for (int i = 0; 5 > i; i++){
                myArray[count][i] = '_';
            }
        }
        }
    // Print game board contents
            void printGrid(){
                    for(int count = 0; count < 5; count++){
                        for (int i = 0; 5 > i; i++){
                        cout <<myArray[count][i];
                        if (i == 4){
                            cout << endl;}
                        }
                    }
                
            }
    // User Pick grid point to fill in with X
            void PickMove() {
            cout << "Pick a row between 1-5 then press enter\n";
                char c1,c2;
                cin >> c1;
                int move1 = 0, move2 =0;
                // if user did not input a value between 1-5 then redo turn
                do{
                    cout << "\nIncorrect input. Please pick a value between 1-5 and press enter.\n";
                    cin.clear();
                    cin >> c1;
                }
                // this checks if c1 is NOT 1-5
                while(!(c1 == '1' || c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5'));
                // use char input to avoid breaking cin input and input corresponding int into array
                if((c1 == '1' || c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5')){
                    if(c1 == '1'){
                        move1 = 0;
                    }
                    if(c1 == '2'){
                        move1 = 1;
                    }
                    if(c1 == '3'){
                        move1 = 2;
                    }
                    if(c1 == '4'){
                        move1 = 3;
                    }
                    if(c1 == '5'){
                        move1 = 4;
                    }
                }
                
            cout << "Pick a column between 1-5 then press enter\n";
                cin >> c2;
                // if user did not input a value between 1-5 then redo turn
                do{
                    cout << "\nIncorrect input. Please pick a value between 1-5 and press enter.\n";
                    cin.clear();
                    cin >> c2;
                }
                // this checks if c1 is NOT 1-5
                while(!(c2 == '1' || c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5'));

                // use char input to avoid breaking cin input and input corresponding int into array
                if((c2 == '1' || c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5')){
                    if(c1 == '1'){
                        move2 = 0;
                    }
                    if(c1 == '2'){
                        move2 = 1;
                    }
                    if(c1 == '3'){
                        move2 = 2;
                    }
                    if(c1 == '4'){
                        move2 = 3;
                    }
                    if(c1 == '5'){
                        move2 = 4;
                    }

                }
                myArray[move1][move2] = 'X';
            }
    //this is essentially the same thing as Pick move except result will be '_' for chosen grid point
    void DeleteMove(){
        cout << "Pick a row between 1-5\n";
        char c1,c2;
        cin >> c1;
        int move1 = 0, move2 =0;
        // if user did not input a value between 1-5 then redo turn
        do{
            cout << "\nIncorrect input. Please pick a value between 1-5 and press enter.\n";
            cin.clear();
            cin >> c1;
        }
        // this checks if c1 is NOT 1-5
        while(!(c1 == '1' || c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5'));
        // use char input to avoid breaking cin input and input corresponding int into array
        if((c1 == '1' || c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5')){
            if(c1 == '1'){
                move1 = 0;
            }
            if(c1 == '2'){
                move1 = 1;
            }
            if(c1 == '3'){
                move1 = 2;
            }
            if(c1 == '4'){
                move1 = 3;
            }
            if(c1 == '5'){
                move1 = 4;
            }
        }

        cout << "Pick a column between 1-5\n";
        cin >> c2;
        // if user did not input a value between 1-5 then redo turn
        do{
            cout << "\nIncorrect input. Please pick a value between 1-5 and press enter.\n";
            cin.clear();
            cin >> c2;
        }
        // this checks if c1 is NOT 1-5
        while(!(c2 == '1' || c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5'));
        
        // use char input to avoid breaking cin input and input corresponding int into array
        if((c2 == '1' || c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5')){
            if(c1 == '1'){
                move2 = 0;
            }
            if(c1 == '2'){
                move2 = 1;
            }
            if(c1 == '3'){
                move2 = 2;
            }
            if(c1 == '4'){
                move2 = 3;
            }
            if(c1 == '5'){
                move2 = 4;
            }
            
        }

        
        myArray[move1][move2] = '_';
    }
    bool Win() {
        if ((myArray[0][0] == 'X' && myArray[1][0] == 'X' && myArray[2][0] == 'X' &&myArray[3][0] == 'X' &&myArray[4][0] == 'X' && myArray[1][1] == 'X' && myArray[2][2] == 'X' && myArray[3][1] == 'X' && myArray[4][0] == 'X' && myArray[4][1] == 'X' && myArray[4][2] == 'X' && myArray[4][3] == 'X' && myArray[4][4] == 'X')){
        }
        return true;
    }
    void Description() {
    cout << "Welcome to Picross\n";
    cout << "To win the game you must find the hidden letter that is printed in the grid with X's\n";
    cout << "Each input you pick will print an X to the square of your choice\n";
    cout << "For example if you want to put an X on the top right hand side you will put 0 for row, and 0 for column\n";
    }
    };

#endif /* picross_h */
