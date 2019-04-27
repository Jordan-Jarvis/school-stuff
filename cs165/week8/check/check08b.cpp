/*****************
 * check08b.cpp
 *****************/

#include "phone.h"
#include "smartphone.h"

#include <iostream>
#include <string>
using namespace std;

/***************************************************
 * Function: main
 * Purpose: Tests a phone and a smart phone object.
 ***************************************************/
int main()
{
   cout << "Phone:\n";

   Phone phone;
   phone.promptNumber();


   cout << "\nPhone info:\n";
   phone.display();



   cout << "\nSmart phone:\n";
   SmartPhone smartPhone;
   smartPhone.prompt();
  
   

   cout << "\nPhone info:\n";
   smartPhone.display();



   return 0;
}
