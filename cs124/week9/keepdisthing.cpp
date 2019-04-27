/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

int readFile(char fileName[],float mileage[])
{
    int numData = 0;
    ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file: " << fileName << endl;
      return 0; 
   }
   while (fin >> mileage[numData] && numData < 100)
       numData++;
   fin.close();
    return numData;
}

float getThreshold()
{
    float threshold;
    cout << "what is the threshold";
    cin >> threshold;
    return threshold;
}

void display(float mileage[], float threshold, int numData)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "The following items are below the threshold: \n";
    for (int i = numData - 1; i < numData; i++)
    {
        if(mileage[i] < threshold)
           cout << "\t" << mileage[i] << endl;
    }
    return;
}

int main()
{
    char fileName[256];
    float threshold;
    float mileage[100];
    getFileName(fileName);
    int numData = readFile(fileName, mileage);
       if (numData = 0)
       {
           cout << "i went kapoot" << endl;
           return 1;
       }
    threshold = getThreshold();
    display(mileage, threshold, numData);

    return 0;
}
