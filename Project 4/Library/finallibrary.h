#ifndef FINALLIBRARY_H
#define FINALLIBRARY_H

#include "finallibrary_global.h"
#include <iostream>
using namespace std;

class FINALLIBRARYSHARED_EXPORT FinalLibrary
{

public:
    FinalLibrary();
    void MakeReminder(string desc, string tile, string tim, string dte);
    void CheckIN(int x);
};

#endif // FINALLIBRARY_H
