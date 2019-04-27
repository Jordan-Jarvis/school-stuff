/********************************************************
* Program: week10.cpp
* Author: Jordan Jarvis
* Description: this impliments the map STD type to count
* the number of words used in a file and displays the top
* 100 words used
*********************************************************/

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

//typedefs, to avoid classes
typedef map<string, int> Map;
typedef multimap<int, string> megaMap;
typedef map<string, int>::reverse_iterator MapIterator;
typedef multimap<int, string>::reverse_iterator MultiMapIterator;

//PROTOTYPES!!!!!
void readfile(string & fileName, string & words, int & numWord, Map & basicMap);
void organze(Map & basicMap, megaMap & bigMap);
void display(megaMap bigMap);

int main() 
{    
    //data types
    string fileName;
    int numWord = 0;
    Map basicMap;
    string words;
    megaMap bigMap;
    
    //functions
    readfile(fileName, words, numWord, basicMap);
    organze(basicMap, bigMap);
    //displays things
    cout << endl;
    cout << "Number of words processed: " << numWord << endl;
    cout << "100 most common words found and their frequencies:" << endl;
    //the big display
    display(bigMap);
  
    return 0;
}

/********************************************************
* readFile
* reads the file and arranges it while counting 
* the words it reads
*********************************************************/
void readfile(string & fileName, string & words, int & numWord, Map & basicMap)
{
   cout << "Enter filename: ";
    cin >> fileName;
    
    ifstream fin;
    fin.open(fileName.c_str());
    
    if (fin.fail()) 
    {
        cout << "Error: not an availible file" << endl;
        readfile(fileName, words, numWord, basicMap);
    }
    
    
    while (fin >> words) 
    {       
        //make this like John Snow, it knows nothing
        string tempWord = "";
        
        for (int i = 0; i < words.length(); i++) 
        {
            if (!ispunct(words[i]) || words[i] == '-')
                tempWord += words[i];
        }
       //counts things up and structures 
        transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower);
        //adds the word in and counts the number of instances its used
        basicMap[tempWord]++;
        numWord++; //hopefully this is a given
    }
    fin.close();
}

/********************************************************
* organize
* organizes everything into the multimap
*********************************************************/
void organze(Map & basicMap, megaMap & bigMap)
{
  for (MapIterator it = basicMap.rbegin(); it != basicMap.rend(); it++) 
        bigMap.insert({it->second, it->first});
}

/********************************************************
* display
* displays all the words and their uses
*********************************************************/
void display(megaMap bigMap)
{
   int i =  0;
   
   for (MultiMapIterator it = bigMap.rbegin(); i < 100 && it != bigMap.rend(); it++) 
   {
       cout << setw(23) << it->second << " - " << it->first << endl;
       i++;
   }
}