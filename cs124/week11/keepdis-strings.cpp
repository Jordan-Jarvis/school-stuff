/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how to walk through a string class object using
 *      various methods.
 ************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * MAIN
 * Simple demo program demonstrating how to use the string class
 ***********************************************************************/
int main()
{
   // fetch text from the user
   cout << "Please enter some text: ";
   string text;  // no buffer size is specified here!
   getline(cin,text);   // different syntax than cin.getline(text, 256);

   // find the number of characters
   cout << "\tNumber of characters: "
        << text.length()
        << endl;

   // find the number of spaces
   int numSpaces = 0;
   for (const char * p = text.c_str(); *p; p++)
      if (*p == ' ')
         numSpaces++;
   cout << "\tNumber of spaces: "
        << numSpaces
        << endl;
   
   // display the string backwards.
   cout << "\tText backwards: ";
   for (int i = text.length() - 1; i >= 0; i--)
      cout << text[i];
   cout << endl;
   
   return 0;
}

