#include "finallibrary.h"
#include <iostream>
#include <string>
#include <QDebug>
#include "model.h"
using namespace std;

 Model DataCollection;

FinalLibrary::FinalLibrary()
{
}
void FinalLibrary::MakeReminder(string desc, string tile, string tim, string dte)
{
    //Setting the Data first so we can make Reminder.
    DataCollection.SetDesc(desc);
    DataCollection.SetTitle(tile);
    DataCollection.SetTime(tim);
    DataCollection.SetDate(dte);
    DataCollection.CreateReminder();	//Here all the set should be Done we make 1 reminder.
}
void FinalLibrary::CheckIN(int x)
{
    //Delete the Reminder
    DataCollection.DeleteReminder(x);
    cout <<"Removed Reminder" << endl;
    cout <<"NumDATA: " << DataCollection.GetNumData() << endl;
}
