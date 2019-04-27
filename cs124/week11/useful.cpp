#include <iostream>
#include <string>
using namespace std;
bool isEqual(char * text1, char * text2);
main()
{
char string1[] = "CS";
char string2[] = "CS 124";
bool equal = isEqual(string1, string2);
cout << equal;
return 0;
}

bool isEqual(char * text1, char * text2)
{
   int i;

   for (i = 0;
        text1[i] == text2[i] &&
        text1[i] && text2[i];
        i++)
      ;

   return (text1[i] == text2[i]);
}




