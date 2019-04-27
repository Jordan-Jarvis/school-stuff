/***********************************************************************
* Program:
*    Checkpoint 02a, Complex Numbers
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/***********************************
 * Student
 * struct for student information
 **********************************/
struct Student       
{
   string firstName;     
   string lastName;
   int studentId;      
};

/**********************************************
 * PROMPT
 * Will ask user for name and ID number
 **********************************************/
void prompt(Student& pos)              
{
   cout << "Please enter your first name: ";
   cin  >> pos.firstName;
   cout << "Please enter your last name: ";
   cin  >> pos.lastName;
   cout << "Please enter your id number: ";
   cin  >> pos.studentId;
}


/***********************************************
 * DISPLAY
 * will show the student information requested earlier
 ***********************************************/
void display(const Student& pos)   
{
   cout << "\nYour information:\n"  
      << pos.studentId << " - " << pos.firstName 
      << " " << pos.lastName << endl;    
}

/**********************************************************************
 * This will be just a simple driver program 
 ***********************************************************************/
int main()
{
   Student pos1;
   prompt(pos1);
   display(pos1);
   return 0;
}

