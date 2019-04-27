#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int countSpaces(const char * text);
/**********************************************************************
* This will be just a simple driver program 
***********************************************************************/
int main(int argc, char ** argv)
{
   int numSpaces = 0;

   string input; 
   if (argc == 1)  //if there's nothing but a.out on command line 
   {
      cout << "Please input some text: ";
      getline(cin, input);
      numSpaces = countSpaces(input.c_str());
   }
   else
   {
       numSpaces = argc - 2;
   }
   cout << "numSpaces = " << numSpaces << endl;
   return 0;
}

int countSpaces(const char * text)
{
    int num = 0;
    // loop through the string
    for (const char * p = text; *p; p++)
       num += (isspace(*p) ? 1 : 0);
       
    return num;   
}





