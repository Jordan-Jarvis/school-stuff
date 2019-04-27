/***********************************************************************
* Program:
*    Assignment 35, gradeLetter
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program asks for a grade and gives you an letter grade
*    strings.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      It was really not bad. It made sense.
************************************************************************/

#include <iostream>
using namespace std;


/*****************************************************
 * This function gets the grade and sets it as an int
 *****************************************************/
int getNumGrade()
{
   int numGrade = 0;
   cout << "Enter number grade: ";
   cin >> numGrade;
   return numGrade;
}

/*****************************************************
 * This function computes the letter grade
 *****************************************************/
void computeLetterGrade(int numGrade, char &gradeLetter)
{
   switch (numGrade / 10)
   {
      case 10:
      case 9:
         gradeLetter = 'A';
         break;
      case 8:
         gradeLetter = 'B';
         break;
      case 7:
         gradeLetter = 'C';
         break;
      case 6:
         gradeLetter = 'D';
         break;
      default:
         gradeLetter = 'F';
   }
}

/*****************************************************
 * This function computes if you have a + 
 * or minus on the grade.
 *****************************************************/
void computeGradeSign(int numGrade, char &gradeSign)
{
   if (numGrade == 100)
   {
      return;
   }
   if (numGrade <= 60 || numGrade >= 97)
      return;
   int  calcGrade = numGrade % 10;

   switch (calcGrade)
   {
      case 0:
      case 1:
      case 2:
         gradeSign = '-';
         break;
      default:
         break;
      case 7:
      case 8:
      case 9:
         gradeSign = '+';
         break;
   }
}

/*****************************************************
 * This function calls all others and displays 
 * information needed.
 *****************************************************/
int main()
{
   char gradeLetter;
   char gradeSign = '0';
   int numGrade = getNumGrade();
   computeLetterGrade(numGrade, gradeLetter);
   computeGradeSign(numGrade, gradeSign);
   cout << numGrade << "% is " << gradeLetter;
   if (gradeSign == '0')
   {
      cout  << endl;
      return 0;
   }
   cout << gradeSign << endl;
   return 0;
}





