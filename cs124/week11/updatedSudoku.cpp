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


int convertCol(char coords[])
{
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
         return -1;
   }
   return col;
}

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

void getCoords(char coords[], char board[][9])
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
      return;
   }
}


/********************************************************************
 * This will edit the board in memory
 ********************************************************************/
void editBoard(char coords[], char board[][9])
{
   int row = -1;
   int col = -1;
   col = convertCol(coords);
   row = convertRow(coords);
   char newVal;

   cout << "What is the value at '" << coords << "': ";
   cin >> newVal;
   board[row][col] = newVal; 
}

/********************************************************************
 * This is a dummy functon for now.
 ********************************************************************/
void possibleValues(char coords[], char board[][9])
{
   int row = -1;
   int col = -1;
         int squarex = 0;
      int squarey = 0;
   char array[9];
   char arraycol[9];
   char result[] = "123456789";
   col = convertCol(coords);
   row = convertRow(coords);
    switch(row)
    {

       case 1:
       case 2:
       case 3:
       squarey = 1;
       break;
       
       case 4:
       case 5:
       case 6:
       squarey = 2;
       break;
       
      case 7:
      case 8:
      case 9:
       squarey = 3;
       
   }
    switch(col)
      {

       case 1:
       case 2:
       case 3:
       squarex = 1;
       break;
       
       case 4:
       case 5:
       case 6:
       squarex = 2;
       break;
       
      case 7:
      case 8:
      case 9:
       squarex = 3;
       break;
   }
   for (int i = 0; i < 9; i++)
   {
      array[i] = board[row][i];
      for (int j = 0; j < 9; j++)
      {
          
          if (squarex == 1)
             
          if (board[row][j] == result[i])
          {
              result[i] = '0';
          }
      }
      for (int j = 0; j < 9; j++)
      {
          if (board[j][col] == result[i])
          {
              result[i] = '0';
          }
      }



      
   }
   for (int i = 0; i < 9; i++)
   {
       cout << result[i];
   }
      cout <<endl << squarey<< endl;
   cout << squarex << endl;
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
   char coords[2];
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
            getCoords(coords, board);
            editBoard(coords, board);
            break;
         case 'S':
            getCoords(coords, board);
            possibleValues(coords, board);
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
