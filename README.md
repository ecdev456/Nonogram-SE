Software Engineering Project 4 <br />

Using reminder application as a library for our new project (library reserves checkout system).<br />

Adding a library requires a lot of steps, but there is this great video on youtube that shows you the steps to take. <br /> https://www.youtube.com/watch?v=9JTooLxhmC0 <br />

Start buy installing the project and then adding the .dll file to the build folder of the project. From there make sure you add the path in the .pro file. LIBS += "path"


//=====================================================================<br />
Software Engineer Project 3 <br />

Reminder Application. <br />

The user is presented with an Application to Create, Update, Remove a Reminder. When the time comes, the application will notify the user with the reminder.<br />

Note:<br />
1. When the Reminder time is reached, the Update and Remove lists will be updated. <br />
2. If the Reminder is removed, the reminder will not trigger. <br />
3. If the reminder, then it will trigger to the updated time. <br />
4. Checks time every 4 seconds. (becuase of allowing systems to deal with load) <br />

Reminder uses Military Time (24h).

Under Project 3 -> FinalBuild folder you will have access to all the necessary files that are needed. <br />
NOTE: have the Current.pro match your .pro file <br />
DISCLAIMER: Closing the application will result in not saving the reminders! Just minimize the window.

//=====================================================================<br />
# Nonogram-SE
Software Engineer Project 2

Rullo Assignment <br />
Files you need for Running Game: <br />
VeronicaLopez: <br />
view.h  //Functionality to show the grid and all<br />

acad3mics: <br />
model.h // ecdev456 and acad#mics worked on this to make sure CheckMath and CheckWin happens accordingly <br />

tandrews:<br />
main.cpp  // Need this for the menu etc.<br />

IF you need a Driver for direct testing:<br />
ecdev456: <br />
ecdevDriver.cpp   // You need model.h and view.h in your Project for this too work.<br />

VeronicaLopez:<br />
viewTest.h and viewTest.cpp // you need model.h in acad3mics folder in order for it to work<br />

//=====================================================================<br />
Project 1: <br />
Recreation of Nonogram <br />
People on the project will be uploading their own header file in order to keep track of work.<br />
You can find the work people contributed in their own folder.<br />

The code you need from each persons folder is:<br />

tandrews4:<br />
NonoGram.cpp  //This is the main.cpp needed to get the game running.
<br />
acad3mics:<br />
picross.h   //This helps in the introduction to the game.<br />

VeronicaLopez:<br />
VeronicaLopezNanoGram.h   //Creates the board and references to other header files.<br />

ecdev456:<br />
ecdev456.h  //Load and Save functionality<br />
Special File.txt    //Required in order to be able to Save and Load properly.<br />

