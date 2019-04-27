/***********************************************************************
* Program:
*    Assignment 40, Tic-Tac-Toe
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program displays a tic-tac-toe board and saves it as a file
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      It was not too bad, I had to re-write some of it because of the
*      need to be able to save the file.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;

/**********************************************************************
 * this function gets the file name.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;
}

/**********************************************************************
 * This function will read the file into a 2d array
 ***********************************************************************/
int readFile(char fileName[], char board[][3])
{
   ifstream fin(fileName);
   int x = 0;
   int y = 0;

// error checking

   if (fin.fail())
   {
      cout << "Error reading file. ";
      return -1;
   }
   // take in information
   while (x < 3 )
   {
      y = 0;
      while (y < 3 )
      {
         fin >> board[x][y];
         y++;
      }
      x++;
   }
   fin.close();
   return y;
}

/**********************************************************************
 * display will add needed formatting and characters to the board and 
 * show it on screen.
 ***********************************************************************/
void display(char board[][3])
{
   int x = 0;
   int y = 0;  // i and j are for error correction
   while (x < 3)
   {
      if (x == 1 || x == 2)
      {
         cout << endl << "---+---+---" << endl;
      }
      cout << " ";
      y = 0;
      while (y < 3)
      {
         int period = 0;
         if (board[x][y] == '.')
            period = 1;
         
         if (y == 1)
         {
            if (period == 1)
               cout << " |  ";
            else
               cout << " | " << board[x][y];
         }
         else if (y == 2)
         {
            if (period == 1)
               cout << " |   ";
            else 
               cout << " | " << board[x][y] << " ";
         }
         else
         {
            if (period == 1)
               cout << " ";
            else
               cout << board[x][y];
         }
         y++;
      }
      x++;
   }
   cout << endl;
}
  
/**********************************************************************
 * this function will write the array to a file
 ***********************************************************************/  
void writeFile(char board[][3])
{
   char save[30];
   cout << "Enter destination filename: ";
   cin >> save;
   
   int x = 0;
   int y = 0;
   
   ofstream fout(save);
   if (fout.fail())
      return;
   while (x < 3 )
   {
      y = 0;
      while (y < 3 )
      {
         fout << board[x][y];
         y++;
      }
      x++;
   }
   fout.close();
   cout << "File written\n";
}

/**********************************************************************
 * main will call other functions and initialize variables as needed.
 ***********************************************************************/
int main()
{
   char fileName[30];
   char board[3][3];
   
   getFileName(fileName);
   readFile(fileName, board);
   display(board);
   writeFile(board);
}
   