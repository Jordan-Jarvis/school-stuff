/***********************************************************************
* Program:
*    Checkpoint 00, test1          (e.g. Assignment 01, Hello World)  
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>

using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int encode(char message[])
{
	for (int i = 0; i < 30; i++)
	{
		if (message[i] == 'e')
		{
			message[i] = 'X';
		}
		if (message[i] == 'i')
			message[i] = 'X';
		
	}
}		

int main()
{
   char message[30];
   cout << "Please enter a message: ";
   cin >> message;
   encode(message);
   cout << message << endl;;
   return 0;
}
