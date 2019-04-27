/***********************************************************************
* Program:
*    Test 4, Count characters
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary:
*    This program counts various components of a user input, then 
*    displays it.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      The hardest part has to have been how to read in more than one 
*      option. It was only reading the first command line option.
*      I realize now there is a more efficient way to do this, but 
*      don't want to mess with it.
************************************************************************/

#include <iostream>
#include <cctype>

using namespace std;


/**********************************************************************
* This will count spaces
***********************************************************************/
int countSpaces(const char * text)
{
   int num = 0;
   // loop through the string
   for (const char * p = text; *p; p++)
      num += (isspace(*p) ? 1 : 0);
       
   return num;   
}

/**********************************************************************
* This will count letters
***********************************************************************/
int countLetters(const char * text)
{
   int letters = 0;
   // loop through the string
   for (const char * p = text; *p; p++)
      letters += (isalpha(*p) ? 1 : 0);
       
   return letters;
}

/**********************************************************************
* This will count digits
***********************************************************************/
int countDigits(const char * text)
{
   int digits = 0;
   // loop through the string
   for (const char * p = text; *p; p++)
      digits += (isdigit(*p) ? 1 : 0);
      
   return digits;
}

/**********************************************************************
* This will count symbols
***********************************************************************/
int countSymbols(const char * text)
{
   int symbols = 0;
   // loop through the string
   for (const char * p = text; *p; p++)
      symbols += (ispunct(*p) ? 1 : 0);
      
   return symbols;
}

/**********************************************************************
* This will show the results
***********************************************************************/
void display(int letters, int digits, int symbols, int numSpaces)
{
   cout << "\tLetters: " << letters << endl;
   cout << "\tDigits:  " << digits << endl;
   cout << "\tSymbols: " << symbols << endl;
   cout << "\tSpaces:  " << numSpaces << endl;
}

/**********************************************************************
* This will check for command line args and run accordingly.
***********************************************************************/
int main(int argc, char ** argv)
{
   int numSpaces = 0;
   int letters = 0;
   int digits = 0;
   int symbols = 0;
   char * input;
   char text[256];
   
   if (argc == 1)  //if there's nothing but a.out on command line 
   {
      cout << "Please enter some text: ";  // ask for text
      cin.getline(text, 256);
      numSpaces = countSpaces(text);
      letters = countLetters(text);
      digits = countDigits(text);
      symbols = countSymbols(text);
   }
   else
   {
       
      for (int i = 1; i < argc; i++)   // loop through command line args
      {
         input = argv[i];
         letters = letters + countLetters(input);  
         digits = digits + countDigits(input);
         symbols = symbols + countSymbols(input);
      }
      
      numSpaces = argc - 2;
   }
   
   display(letters, digits, symbols, numSpaces);
   return 0;
}


