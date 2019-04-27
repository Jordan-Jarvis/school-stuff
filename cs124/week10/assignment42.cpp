#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
   int offset = 3;
   int daysMonth = 30;
   for (int i = 0; i < daysMonth + offset; i++)
      if (i <= 0)
      {
         cout << " ";
      }
      else 
      {
         cout << i - offset;
      }
      if (i % 7)
         cout << endl; 
}