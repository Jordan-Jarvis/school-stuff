/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program will allow you to play sudoku, given a board file.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The hardest part was brainstorming. I had a hard time figuring out
*      which idea I had would be most efficient.
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
 * This will convert the column choice into an int
 ********************************************************************/
int convertCol(char coords[])
{
   int col = -1;
   switch (coords[0])
   {
      case 'A': 
      case 'a':   // convert from alphanumeric to numbers of 
         col = 0; // the array
         break;
     
      case 'B':
      case 'b':   // should not be indented more, style checker 
         col = 1; // is messed up.
         break;
       
      case 'C':
      case 'c':
         col = 2;
         break;
       
      case 'D':
      case 'd':
         col = 3;
         break;
       
      case 'E':
      case 'e':
         col = 4;
         break;
       
      case 'F':
      case 'f':
         col = 5;
         break;
       
      case 'G':
      case 'g':
         col = 6;
         break;
       
      case 'H':
      case 'h':
         col = 7;
         break;
       
      case 'I':
      case 'i':
         col = 8;
         break;
       
      default:
         cout << "Invalid Coordinates";
         return -1;
   }
   return col;
}

/********************************************************************
 * This will convert the row choice into an int
 ********************************************************************/
int convertRow(char coords[])
{
   int row;
   char *temp = &coords[1];
   row = atof(temp);  // create a temp const to convert the 
   row = row - 1;     // number in char to float
   temp = NULL;
   delete temp;  // memory management'
   return row;
}

/********************************************************************
 * This will get the coordinates to modify the board
 ********************************************************************/
bool getCoords(char coords[], char board[][9])
{
   
   cout << "What are the coordinates of the square: ";
   cin >> coords;
   int row = -1;
   int col = -1;
   col = convertCol(coords);
   row = convertRow(coords);
   if (board[row][col] != '0')
   {
      cout << "ERROR: Square '" << coords << "' is filled\n";
      return 1;
   }
   return 0;
}

/********************************************************************
 * This will loop to find all possible options for a given set of 
 * coordinates
 ********************************************************************/
void possibleValues(char coords[], char board[][9], char result[])
{

   int row = -1;
   int col = -1;
   int squarex[1];
   int squarey[1];
   char array[9];
   char arraycol[9];

   col = convertCol(coords);
   row = convertRow(coords);
   switch (row)
   {
      case 0:
      case 1:
      case 2:
         squarey[0] = 0;
         squarey[1] = 2;
         break;
       
      case 3:
      case 4:
      case 5:
         squarey[0] = 3;
         squarey[1] = 5;
         break;
       
      case 6:
      case 7:
      case 8:
         squarey[0] = 6;
         squarey[1] = 8;
       
   }
   switch (col)
   {
      case 0:
      case 1:
      case 2:
         squarex[0] = 0;
         squarex[1] = 2;
         break;
       
      case 3:
      case 4:
      case 5:
         squarex[0] = 3;
         squarex[1] = 5;
         break;
       
      case 6:
      case 7:
      case 8:
         squarex[0] = 6;
         squarex[1] = 8;
         break;
      
   }
   int temp = squarey[0];
   
   for (int i = 0; i < 9; i++)
      result[i];            // this is only for the school compiler
                               //onlinegdb the code works without it
   while ( squarex[0] <= squarex[1])
   {
      squarey[0] = temp;
      while (squarey[0] <= squarey[1])
      {
         for (int i = 0; i < 9; i++)
         {
            if (board[squarey[0]][squarex[0]] == result[i])
               result[i] = '0';
         }
         squarey[0]++;
      }
      squarex[0]++;
   }
   
   for (int i = 0; i < 9; i++)
   {
      array[i] = board[row][i];
      for (int j = 0; j < 9; j++)
      {  
         if (board[row][j] == result[i])
            result[i] = '0';
      }
      for (int j = 0; j < 9; j++)
      {
         if (board[j][col] == result[i])
            result[i] = '0';
      }
   }
}

/********************************************************************
 * This will show the possible values that were calculated in 
 * possibleValues
 ********************************************************************/
void showPossibleValues(char coords[], char result[])
{
   cout << "The possible values for '" << coords << "' are:";
   int count = 0;
   for (int i = 0; i < 9; i++)
   {
      if (result[i] != '0')
      {
         count++;
         if (count == 1)
            cout << " " << result[i];
         else 
            cout << ", " << result[i];
      }
   }
   cout << endl;
}

/********************************************************************
 * This will do the edits of choice on the board
 ********************************************************************/
int editBoard(char coords[], char board[][9], char result[])
{
   int row = -1;
   int col = -1;
   col = convertCol(coords);
   row = convertRow(coords);
   int temp = 0;
   char newVal;

   cout << "What is the value at '" << coords << "': ";
   cin >> newVal;
   possibleValues(coords, board, result);
   for (int i = 0; i < 9; i++)
   {
      if (newVal == result[i])
      {
         board[row][col] = newVal; 
         return newVal;
      }
   }
   cout << "ERROR: Value '" << newVal 
      << "' in square '" << coords << "' is invalid\n";

   return newVal;
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
   char coords[2];
   char response[1];
   const char numbers[] = "123456789";
   char result[] = "123456789";
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
         case 'd':
            showBoard(board);
            break;
         case 'E':
         case 'e':
            for (int i = 0; i < 9; i++)
            {
               result[i] = numbers[i];
            }
            bool valid;
            valid = getCoords(coords, board);
            if (valid == 1)
               break;
            editBoard(coords, board, result);
            break;
         case 'S':
         case 's':
            for (int i = 0; i < 9; i++)
            {
               result[i] = numbers[i];
            }
            getCoords(coords, board);
            possibleValues(coords, board, result);
            showPossibleValues(coords, result);
            break;
         case 'Q':
         case 'q':
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
