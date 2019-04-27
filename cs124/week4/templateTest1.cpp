/**************************************************
* Program:
*    Test 1, Practice final
*    Sister Hansen, cs124
* Author:
*    Jordan Jarvis
* Summary: 
*    This is my test, it will ask user for a grade
*    and display a message based on if they should study
*    more or not.
************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************
* This function is the result if the grade for the practice
* test was above 85%
***********************************************************/
void passed()
{
   cout << "\tYou are ready to take the test!" << endl;
}

/***********************************************************
* This function is the result if the grade for the practice 
* test was below 85%
***********************************************************/
void failed()
{
   cout << "\tMore studying is required." << endl;
}

/***********************************************************
* This function will get the grade of the user for the  
* practice test and pass it on as a variable.
***********************************************************/
int getGrade()
{
   double grade = 0; // set variables
   cout << "What was your score on the practice "
      << "final in percentage points? ";
   cin >> grade; //set variable to user input
   return grade;
}

/***********************************************************
* main does it's typical thing, calling functions, but 
* it also includes an if/then statement that will 
* direct the program dependent on the grade entered.
***********************************************************/
int main()
{
   int grade = getGrade();
   
   if (grade >= 85)
   {
      passed();
   }
   else failed();
   
   return 0;
}