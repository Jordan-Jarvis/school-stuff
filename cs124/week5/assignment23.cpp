/****************************************************************
 * This program is designed to determine the speed in which 
 * the string class append performs its operation.  In the process
 * we hope to gain some insight into how the string class works
 ****************************************************************/

#include <iostream>
#include <string.h>
#include <cmath>
#include <cstdlib>

using namespace std;


/********************************************
 * Test the speed in which various string functions work.
 ********************************************/
int main(int argc, char **argv)
{
cout.setf(ios::fixed);
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);     
   for (int count = 1; count < argc; count++)
   {
       
       int num = atof(argv[count]);
       if (num < 0)
          num = -num;
          float conversion = num * 0.3048;
    cout << num << " feet is " << conversion << " meters\n";
   }
  

   return 0;
}


