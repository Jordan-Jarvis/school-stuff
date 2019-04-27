#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int countSpaces(const char * text);
int countChars(const char * text);
/**********************************************************************
* 
***********************************************************************/
int main(int argc, char ** argv)
{
   int numSpaces = 0;
   int numChars = 0; 
//   string text; 
   char text[256];
   
   if (argc == 1)  //if there's nothing but a.out on command line 
   {
      cout << "Please input some text: ";
   //   getline(cin, text);
       cin.getline(text, 256);
      //numSpaces = countSpaces(text.c_str());
       numSpaces = countSpaces(text);
      // for fun, let's count the number of chars in the input
       numChars = countChars(text);
   }
   else
   {
       numSpaces = argc - 2;
       numChars = countChars(text);
   }
   cout << "numSpaces = " << numSpaces << endl;
   cout << "numChars = " << numChars << endl;
   return 0;
}

/**********************************************************************
* 
***********************************************************************/
int countChars(const char * text)
{
    int numC = 0;
    for (const char * pT = text; *pT; pT++)
        numC++;
        
    return numC;
}

/**********************************************************************
* 
***********************************************************************/
int countSpaces(const char * text)
{
    int num = 0;
    // loop through the string
    for (const char * p = text; *p; p++)
       num += (isspace(*p) ? 1 : 0);
       
    return num;   
}








