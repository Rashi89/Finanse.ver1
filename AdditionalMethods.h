#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

//#include "IncomeMenager.h"

using namespace std;

class AdditionalMethods{

public:
   static string loadLines();
   static float swapStringForFloat(string number);
   static int swapStringForInt(string number);
   static string swapCommaToDot(string number);
   static char loadSign();
   static string swapIntForString(int number);

};
#endif
