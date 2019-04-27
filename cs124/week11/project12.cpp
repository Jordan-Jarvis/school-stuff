/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program will allow you to play sudoku, given a board file.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The hardest part was getting the formatting to display correctly.
************************************************************************/

#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

/********************************************************************
 * This will get the filename and return it.
 ********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
}

/********************************************************************
 * This function will read the file into an array called board
 ********************************************************************/
int readFile(char fileName[], char board[][9])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file. ";
      return -1;
   }
    
   int row = 0;
   int col = 0;
   
   while (row < 9)  // read in the file to the array
   {
      col = 0;
      while (col < 9)
      {
         fin >> board[row][col];
         col++;
      }
      row++;
   }
   fin.close();
}

/********************************************************************
 * This will show the options available
 ********************************************************************/
void showOptions()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";
}

/********************************************************************
 * This will show the board that is in memory
 ********************************************************************/
void showBoard(char board[][9])
{
   cout << "   A B C D E F G H I\n";
   int col = 0;
   int row = 0;
   while (row < 9)
   {
      if (row == 3 || row == 6)
      {
         cout << "   -----+-----+-----\n";
      }       
      cout << row + 1 << " ";
      col = 0;       // double loops to display the whole  2d array
      while (col < 9)
      {
         if (col == 3 || col == 6)
            cout << "";
         else
            cout << " ";
       
         if (col == 3 || col == 6)
            cout << "|";
          
         if (board[row][col] == '0')
            cout << " ";
         else
            cout << board[row][col];
       
         col++;
      }
      cout << endl;
      row++;
   }
}

/********************************************************************
 * This will edit the board in memory
 ********************************************************************/
void editBoard(char board[][9])
{
   char coords[2];
   cout << "What are the coordinates of the square: ";
   cin >> coords;
   int row = -1;
   int col = -1;

   switch (coords[0])
   {
      case 'A':      // convert from alphanumeric to numbers of 
         col = 0;       // the array
         break;
     
      case 'B':
         col = 1;
         break;
       
      case 'C':
         col = 2;
         break;
       
      case 'D':
         col = 3;
         break;
       
      case 'E':
         col = 4;
         break;
       
      case 'F':
         col = 5;
         break;
       
      case 'G':
         col = 6;
         break;
       
      case 'H':
         col = 7;
         break;
       
      case 'I':
         col = 8;
         break;
       
      default:
         cout << "Invalid Coordinates";
         return;
   }
   char *temp = &coords[1];
   row = atof(temp);  // create a temp const to convert the 
   row = row - 1;     // number in char to float
   temp = NULL;
   delete temp;  // memory management
   if (board[row][col] != '0')
   {
      cout << "ERROR: Square '" << coords << "' is filled\n";
      return;
   }
   char newVal;
   cout << "What is the value at '" << coords << "': ";
   cin >> newVal;
   board[row][col] = newVal; 
}

/********************************************************************
 * This is a dummy functon for now.
 ********************************************************************/
void possibleValues(char board[][9])
{
   cout << "You chose Possible Values! \n";
}

/********************************************************************
 * This will dump the board in memory to a file of the users choice
 ********************************************************************/
void saveAndQuit(char board[][9])
{
   char saveFile[32];
   cout << "What file would you like to write your board to: ";
   cin >> saveFile;
   int row = 0;
   int col = 0;
   
   ofstream fout(saveFile);
   if (fout.fail())
      return;
   while (row < 9 )
   {
      col = 0;
      while (col < 9 )   // write out the array to a file
      {
         fout << board[row][col];
         col++;
      }
      row++;
   }
   fout.close();
   cout << "Board written successfully\n"; 
}

/**********************************************************************
 * MAIN will call all the functions, an loop where needed.
 ***********************************************************************/
int main()
{
   bool exit = 0;
   char fileName[32];
   char board [9][9];
   char response[1];
   getFileName(fileName);
   readFile(fileName, board);
   showOptions();
   showBoard(board);
   while (exit == 0)
   {
      cout << "\n> ";
      cin >> response;
      switch (response[0])  // loop until save and quit selected.
      {
         case '?':
            showOptions();
            break;
         case 'D':
            showBoard(board);
            break;
         case 'E':
            editBoard(board);
            break;
         case 'S':
            possibleValues(board);
            break;
         case 'Q':
            saveAndQuit(board);
            exit = 1;
            break;
         default:
            cout << "invalid response!";
            break;
      }
   }
   return 0;
}
