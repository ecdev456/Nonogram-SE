#ifndef MODEL_H
#define MODEL_H

#include "mainwindow.h"
#include "createwindow.h"
#include <iostream>
#include <string>
using namespace std;

class Model{
private:
    string TitleArray[20];  //Title Array data
    string DateArray[20];   //Date Array  data
    string TimeArray[20];   //Time Array data
    string DescArray[20];   //Description data
    int NumData= 0; //This will keep the count of number of Reminders
public:
   void CreateReminder(string desc){   //User has selected to add a Reminder
    //Adding the Description to the current placement
        DescArray[NumData] = desc;
        NumData++;
        cout << "Success" << endl;
    }
   void SetTitle(string title){cout << "Done: " << title << endl;} //Retrieve the title from the UserInput
   void SetDate(string date){cout << "Done: "<< date << endl;} //Retrieve the date from the UserInput
   void SetTime(string time){cout << "Done: "<< time << endl;} //Retrieve the time from the UserInput
   void SetDesc(string desc){cout << "Done: "<< desc << endl;} //Retrieve the desc from the UserInput
   void SetButton(bool doneButton){cout << "Button: " << doneButton << endl;}//Retrieve the done button information


 void EditReminder(string desc, int choice){
       DescArray[choice].clear();
       DescArray[choice] = desc;
      cout << "Success" << endl;
   };

 void DeleteReminder(int Delete){
       DescArray[Delete].clear();
       // If you want you can add extra to delete the slot.
       // use below
       // delete [] remindername <--- object to be deleted
 };

  void  PrintReminder() // Intent of this is to display Reminders in order
   {    // # of Reminder, Date, Time, Decription.
   /*   cout << "# " << " Title " << " Date " << " Time " << endl;
      for(int i = 0; i < NumData; i++)
      {
          cout << i+1 <<". : ";
          cout << TitleArray[i] << " " << DateArray[i] << " " << TimeArray[i] << endl;
          cout <<"Description: " << DescArray[i] << endl;
      }*/
        for(int i=0; i < NumData; i++)
        {
            cout << "Description: " << DescArray[i] << endl;
        }
    }



};

#endif // MODEL_H#ifndef MODEL_H

