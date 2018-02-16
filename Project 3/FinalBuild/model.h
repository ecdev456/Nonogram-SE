#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

using namespace std;
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
     int NumData, choice1; //This will keep the count of number of Reminders
public:
     Model()
     {
         tData = "";
         dData = "";
         tmData ="";
         deData ="";
         NumData = 0;
     }
   void CreateReminder(){
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
   void SetNumData(int x) //this temp solution for other objects
   {
       NumData = x;
   }

   void EditTitle(int x, string data)
   {
       TitleArray[x] = data;
   }
   void EditDate(int x, string data)
   {
       DateArray[x] = data;
   }
    void EditTime(int x, string data)
    {
        TimeArray[x] = data;
    }
    void EditDesc(int x, string data)
    {
        DescArray[x] = data;
    }
   void EditReminder(int choice){ // step 1 clear data fields for choice
       choice1 = choice;
         DescArray[choice-1].clear();
         DateArray[choice-1].clear();
         TimeArray[choice-1].clear();
          DateArray [choice-1] = dData; //dData holds new Date Data
          DescArray[choice-1] = deData;
          TimeArray[choice-1] = tmData;
 }

 string GetTitle(int x)
 { return TitleArray[x];}
 string GetDate(int x)
 { return DateArray[x];}
 string GetDesc(int x)
 { return DescArray[x]; }
string GetTime(int x)
{ return TimeArray[x];}
int GetNumData()
{return NumData;}

int GetChoice()
{
    return choice1;
}

void SetChoice(int x)
{
    choice1 = x;
}
 void DeleteReminder(int choice){           //User selects to Remove a reminder and we shift accordingly
       //DescArray[choice].clear();
       // If you want you can add extra to delete the slot.
       // use below
       // delete [] remindername <--- object to be deleted
     for(int i = choice;i < NumData; i++ )
     { // This is where the shifting happens
       TitleArray[i-1] = TitleArray[i];
       DescArray[i-1] = DescArray [i];
       DateArray[i-1] = DateArray[i];
       TimeArray[i-1] = TimeArray[i];
     }
     NumData--; //the number of reminders is then shortened
 }
};
extern Model DataCollection;
#endif // MODEL_H#ifndef MODEL_H
