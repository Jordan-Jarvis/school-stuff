/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"


void SmartPhone::prompt()
   {
      Phone::promptNumber();
      cout << "Email: ";
      cin >> email;
   }
void SmartPhone::display()
   {
      Phone::display();
      cout << email << endl;
   }
      
