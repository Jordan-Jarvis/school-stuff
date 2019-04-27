/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Jordan Jarvis
 **********************************************************************/

#include <iostream>     
#include <string>     
#include <cassert>    
#include "nowServing.h" 
#include "deque.h"    
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests 
 ***********************************************/
void nowServing()
{
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   Deque <Stud> list(10);
   string command;
   Stud stud;
   Stud help;
   help.min = 0;
   int seq = 0;
   
   while (command != "finished")
   {
      cout << "<" << seq++ << "> ";
      cin >> command;
      if (command != "finished")
      {
         if (command == "!!")
         {
            cin >> stud.clas >> stud.name >> stud.min;
            stud.emergency = true;
            list.push_front(stud);
         }
         else if (command == "none")
         {
          //do nothing
         }
         else
         {
            stud.clas = command;
            cin >> stud.name >> stud.min;
            stud.emergency = false;
            list.push_back(stud);
         }
         
         if (help.min == 0&& list.size()>0)
         {
           help = list.front();
           
           list.pop_front();
         }
         if (help.min > 0)
         {
            if (help.emergency)
            {
               cout << "\tEmergency for " << help.name << " for class "
                    << help.clas << ". Time left: " 
                    << help.min--
                    << endl;
            }
            else
            {
               cout << "\tCurrently serving " << help.name 
                    << " for class "
                    << help.clas << ". Time left: " 
                    << help.min-- << endl;
            }
         }
      }
   }
   cout << "End of simulation\n";
}


