#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
void getFileName(char fileName[])
{
    cout << "Enter filename of list: ";
    cin >> fileName;
    
}

int readFile(char fileName[], int array[])
{
    ifstream fin(fileName);
    if (fin.fail())
    {
        cout << "Error reading file. ";
        return -1;
    }
    int i = 0;
    while(i <= 30 && !fin.eof())
    {
       fin >> array[i];
       i++;
    }
}


float linear(int array[])
{
    for (int i = 0; )
}

float binary(int array[])
{
    
}

int main()
{
   int size = 0;
   char fileName[32];
   int array[30];
   getFileName(fileName);
   readFile(fileName, array);
}