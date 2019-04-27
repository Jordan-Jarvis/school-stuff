/*********************
 * phone.cpp
 *********************/
#include "phone.h"
#include <iostream>
#include <string>

   void Phone::promptNumber()
   {
      cout << "Area Code: ";
      cin >> areaCode;
      cout << "Prefix: ";
      cin >> prefix;
      cout << "Suffix: ";
      cin >> suffix;
   }
   void Phone::display()
   {
   cout << "(" << areaCode << ")";
   cout << prefix << "-" << suffix << endl;
   }
   
