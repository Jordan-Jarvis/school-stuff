
#include <iostream>
using namespace std;

int strlen(char * text);

int main()
{
    char myText[] = "I love cs124!";
    int length = strlen(myText);
    cout << "length: " << length << endl;
    return 0;
}

int strlen(char * text)
{
   char * p = text;

   while (*(p++))
        cout << "p in loop: " << p << endl;
    cout << "p address: " << &p << endl
         << "   p value: " << p << endl;
    cout << "text address: " << &text << endl
         << "   text: " << text << endl;
    

   return p - text - 1;    // when we use a ptr name in a math expression
                           // it uses the address location
}



