/***********************************************************************
 * This program is designed to demonstrate:
 *      How to define, declare, and pass a structure
 ************************************************************************/

#include <iostream>
using namespace std;

/***********************************
 * POSITION
 * The position on the globe
 **********************************/
struct Scripture       
{
   string book[3];     
   int verse[3];
   int chapter[3];      
};

/***********************************************
 * DISPLAY
 * Display a position on the screen.  Note that
 * this is passing a constant struct by reference
 * so we avoid making a copy of the position and
 * we avoid changing the position by accident
 ***********************************************/
void display(const Scripture & pos)   
{
    for (int i = 0; i < 3; i++)
    {

     cout << pos.book[i] << " " << pos.chapter[i] << ":" 
      << pos.verse[i] << endl;
    }
}

/**********************************************
 * PROMPT
 * Ask the user for a position.  This is
 * pass-by-reference but is not a const because
 * we intend on changing the member variables
 **********************************************/
void promptScripture(Scripture & pos)              
{
   for(int i = 0; i < 3; i++)
   {
      
      cout << "Please enter the book: ";
      getline(cin, pos.book[i]);
      cout << "Please enter the chapter: ";
      cin  >> pos.chapter[i];
      cout << "Please enter the verse: ";
      cin  >> pos.verse[i];

	  cin.ignore();
   }
}



/**********************************************************************
 * This will be just a simple driver program 
 ***********************************************************************/
int main()
{
   Scripture pos1;
   promptScripture(pos1);
   display(pos1);
   return 0;
}

