/***********************************************************************
 * This program is designed to demonstrate:
 *      display the contents of a file
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main(int argc, char ** argv)
{
   string filenameInput;
   if (argc == 1)
   {
      cout << "What is the filename: ";
      cin  >> filenameInput;
   }
   else
      filenameInput = argv[1];
   
   // open the file
   ifstream fin(filenameInput.c_str());
   if (fin.fail())
   {
      cout << "you are a LOOOSER! Tried to open file "
           << filenameInput
           << endl;
      return 1;
   }

   string text;

   // if there is only 1 or 2 paramaters, write to the screen
   if (argc < 3)
      while (getline(fin, text))
         cout << text << endl;
   // else, if there are three, write to a file
   else
   {
      ofstream fout(argv[2]);
      if (fout.fail())
      {
         cout << "Error, unable to open output file "
              << argv[2]
              << endl;
         fin.close();
         return 1;
      }

      while (getline(fin, text))
         fout << text << endl;
      
      fout.close();
   }

   fin.close();
   
   return 0;
}


