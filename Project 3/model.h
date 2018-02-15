#ifndef MODEL_H
#define MODEL_H

//#include "mainwindow.h"
//#include "createwindow.h"
#include <iostream>
#include <string>
using namespace std;
//sizeof(x)     //

class Model{
    friend class RemoveWindow;
    friend class CreateWindow;
private:
    bool checkBool = 0;     //This will configure if "Create" a reminder is set to true.
    string TitleArray[20];  //Title Array data
    string DateArray[20];   //Date Array  data
    string TimeArray[20];   //Time Array data
    string DescArray[20];   //Description data
    string tData, dData, tmData, deData; // These will store data and add to array when ready.
    int NumData= 0; //This will keep the count of number of Reminders
public:
   void CreateReminder(){
       cout <<"In here" << endl;
       //User has selected to add a Reminder
       //check if their is data. if not data then set default data.

       if(tData.length() == 0)
       { tData = "Default Title";}
       if(dData.length() == 0)
       {dData = "2/14/18";}
       if(tmData.length() == 0)
       {tmData = "8:00 AM";}
       if(deData.length() == 0)
       { deData = "Description Here";}

       //If we reached here, all the necessary data has been updated.
       //Default data plaeced if needed
       TitleArray[NumData] = tData;
       DateArray[NumData] = dData;
       TimeArray[NumData] = tmData;
       DescArray[NumData] = deData;
       //Now it's placed and we increase the count of Reminders
       NumData++;
       //Now need to set back to NULL. Reason: if they are set, then they are replaced with the new data
       tData ="";
       dData ="";
       tmData ="";
       deData ="";
    }
   void SetTitle(string title)  //Retrieve the title from the UserInput and place into StringArray
   {
      tData = title;
   }
   void SetDate(string date)  //Retrieve the date from the UserInput and place into DateArray
   {
      dData = date;
   }
   void SetTime(string time)     //Retrieve the time from the UserInput and place intro TimeArray
   {
       tmData = time;
   }
   void SetDesc(string desc)  //Retrieve the desc from the UserInput and place into DescArray
   {
       deData = desc;
   }
   void SetButton(bool doneButton)  //Retrieve the desc from the UserInput and place into
   {
       checkBool = doneButton;
   }
    //Part of a test
 /*string getTitleArray(sting t[20]) // for updatewindow to gain access into this array
 {
    TitleArray[20] = t[20];
 }


  string getDateArray(sting d[20]) // for updatewindow to gain access into Date array
 {
    DateArray[20] = d[20];
 }


string getTimeArray(sting tm[20]) // for updatewindow to gain access into this array
 {
    TimeArray[20] = tm[20];
 }

 string getDescArray(sting desc[20]) // for updatewindow to gain access into this array
 {
    DescArray[20] = desc[20];
 }

 */



 void EditReminder(string desc, int choice)
 {
       DescArray[choice].clear();
       DescArray[choice] = desc;
      cout << "Success" << endl;
   };

 void DeleteReminder(int choice){           //User selects to Remove a reminder and we shift accordingly
       //DescArray[choice].clear();
       // If you want you can add extra to delete the slot.
       // use below
       // delete [] remindername <--- object to be deleted
     for(int i = choice;i < NumData; i++ ){ // This is where the shifting happens
       DescArray[i-1] = DescArray [i];
       DateArray[i-1] = DateArray[i];
       TimeArray[i-1] = TimeArray[i];
     }
     NumData--; //the number of reminders is then shortened
 };
};

#endif // MODEL_H#ifndef MODEL_H

