/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how to fetch the fileName from either a prompt or
 *      from a command line parameter
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***************************************
 * GET FILENAME
 * Prompt the user for the filename
 **************************************/
string getFilename()
{
   string fileName;
   cout << "Please enter the filename: ";
   cin  >> fileName;
   return fileName;
}

/**********************************************************************
 * MAIN
 * Parse the command line and call functions to do the hard work...
 ***********************************************************************/
int main(int argc, char **argv)
{
   // ensure the correct number of parameters was specified
   if (argc > 2)   // one for the name of the program, one for the filename
   {
      cout << "Unexpected number of parameters.\nUsage:\n";
      cout << "\t" << argv[0] << " [filename]\n";
      return 1;
   }
   
   // parse the command line
   string fileName;
   if (argc == 1) // only the program name was specified
      fileName = getFilename();
   else
      fileName = argv[1];
   
   // display the results
   cout << "The filename is \"" << fileName << "\"\n";


   return 0;
}



