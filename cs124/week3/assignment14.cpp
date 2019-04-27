/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary:
*    This program will address Peter's question to the Lord in
*    Matthew 18:21-22
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
*      The hardest part was the void questionPeter, I couldn't figure
*      out the cout output.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* responseLord
* The response Jesus has
***********************************************************************/
int responseLord()  
{
   return 70 * 7;
   //multiplies 70 times 7
}

/**********************************************************************
* questionPeter
* The question Peter asks
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, "
      "and I forgive him?" << endl;
   //This stuff is the
   cout << "Till seven times?\n";
   //output for questionPeter
   return;
};

/**********************************************************************
* Main will not do much here.  First it will display Peter's question,
* then it will display the Lord's answer
***********************************************************************/
int main()
{
   questionPeter();
   // the first part of the Lord's response

   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";

   cout << "times: but, Until " << responseLord() << ".\n";
   // Then comes the second part of the lords response.
   return 0;
}

