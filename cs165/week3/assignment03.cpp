/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    This program gets timestamp information from a file and filters
*    through the timestamps based on time and shows relevant data
*    this version also has error correction included
*
*    Estimated:  2.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part had to be using the struct. 
*      I needed to learn how to make a struct array.
* ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

/***********************************
 * Record
 * this structure defines a set of data for a timestamp
 **********************************/
struct Record
{
   string file;
   string user;
   long timestamp;
};

/***********************************
 * getFileName
 * Asks user for a file to pull information from
 **********************************/
void getFileName(char fileName[])
{
   cout << "Enter the access record file: ";
   cin >> fileName;
}

/***********************************
 * getStartEndTimes
 * Prompts the user for a start and end time and returns it
 * to main for use in the future
 **********************************/
void getStartEndTimes(long startEndTimes[])
{
   cout << "Enter the start time: ";
   cin >> startEndTimes[0];
   cout << "Enter the end time: ";
   cin >> startEndTimes[1];
   cout << endl;
   return;
}

/***********************************
 * parseLine
 * checks for parameters to parse lines into a struct
 **********************************/
void parseLine(string line, Record record[], int count)
{
   stringstream ss;
   ss.str(line);
   ss >> record[count].file >> record[count].user
      >> record[count].timestamp;

   if (ss.fail())
   {
      if (line == "\0")
      {
         cout << endl;
         return;
      }
      cout << "Error parsing line: " << line << endl;
      return;
   }
   if (record[count].timestamp < 1000000000 ||
         record[count].timestamp > 10000000000)
   {
      cout << "Error parsing line: " << line << endl;
   }
}

/***********************************
 * parseFile
 * this function reads in lines from the file
 **********************************/
void parseFile(char fileName[], Record record[], int &count)
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file. ";
   }
   while (!fin.eof())
   {
      string line;
      getline(fin, line);      
      count++;
      parseLine(line, record, count);
   }
   fin.close();
}

/***********************************
 * display
 * shows the timestamps within the parameters
 *  set in the getStartEndTimes function
 **********************************/
void display(Record record[], int count, long startEndTimes[])
{
   cout << "The following records match your criteria:\n";
   cout << "\n      Timestamp                File                User\n";
   cout << "--------------- ------------------- -------------------\n";

   for (int i = 0; i < count; i++)
   {
      if (record[i].timestamp >= startEndTimes[0] 
         && record[i].timestamp <= startEndTimes[1])
      {
         cout << setw(15) << record[i].timestamp
            << setw(20) << record[i].file 
            << setw(20) << record[i].user 
            << endl;
      }
   }
   cout << "End of records";
}

/**********************************************************************
 * Main
 * Drives the other functions and holds data for them.
 ***********************************************************************/
int main()
{
   int count = 0;
   char fileName[40];
   Record record[500];
   long startEndTimes[2];
   getFileName(fileName);

   parseFile(fileName, record, count);
   getStartEndTimes(startEndTimes);
   display(record, count, startEndTimes);
   
   cout << endl;
   return 0;
}


