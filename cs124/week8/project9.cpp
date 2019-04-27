/***********************************************************************
* Program:
*    Project 10, Mad Lib
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program asks questions about information in a file, then
*    replaces specific parts with what the user specifies. It then
*    displays the contents on the screen. In other words, it is
*    a Mad Lib program.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      I had a hard time with some small things, mainly the spacing
*      before and after punctuation. eventually I figured it out.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;

/*****************************************************
 * This function gets the filename for madLib
 *****************************************************/
void getFileName (char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   
}

/*****************************************************
 * This function reads Mad Lib file and converts the
 * weird code into questions that are then asked 
 * to the user. They are then stored as strings.
 *****************************************************/
void askQuestions (char madLib[][36], int numWords)
{
   cin.ignore();
   for (int i = 0; i < numWords; i++)
   {
      if (madLib[i][0] == '<')
      {
         
         if (isalpha(madLib[i][1]))
         {
            cout << "\t";
            for (int j = 1; madLib[i][j] != '>' ; j++)
            {
               if (j == 1)
                  cout << (char)toupper(madLib[i][1]);
               else if (madLib[i][j] == '_')
                  cout << ' ';
               else
                  cout << madLib[i][j];
            }

            cout << ": ";
            cin.getline(madLib[i], 36);

         }
      }
   }
}

/*****************************************************
 * This function reads the MadLib file, and puts it 
 * into a 2d array.
 *****************************************************/
float readFile(char fileName[], char madLibStory[][36])
{

   ifstream fin(fileName);
             // reads the file in to an array of strings
   if (fin.fail())
   {
      cout << "Error reading file: " << fileName << endl;
      return -1; // error correction
   }

   int count = 0;
   int numWords = 0;
   while (numWords < 256 && fin >> madLibStory[numWords])
   {
      // read in file until it hits 256 char or end of file
      if (madLibStory[numWords][0] == '<'
         && isalpha(madLibStory[numWords][1]))
      {
         (madLibStory[numWords], count);
         count++;
      }
      // include words that need to be modified.
      else if (madLibStory[numWords][0] == '<' 
         && !isalpha(madLibStory[numWords][2]));
      numWords++;
   }
   
   fin.close();
   return numWords;
   
}

/*****************************************************
 * display will do the final conversion from strange
 * symbols to their respective punctuation marks, 
 * adding or removing spaces as needed.
 *****************************************************/
void display(char madLib[][36], int numWords)
{
   cout << endl;
   for (int i = 0; i < numWords; i++)
   {
      if (madLib[i][0] == '<')
      {
         switch (madLib[i][1])
         {
            // identify what needs to change, then change it
            case '#':
               cout << '\n';
               madLib[i][0] = '\n';
               madLib[i][0] = '\0';
               
               break;
            case '{':
               cout << '"';
               break;
            case '}':
            {       
                    // correct spacing for endline, end of string and quotes
               if (madLib[i + 2][0] == '.'
                  || madLib[i + 2][0] == '\0'
                  || madLib[i + 2][1] == '#'
                  || madLib[i + 2][2] == '\0')
                  cout <<  '"';
               else
                  cout << '"' << ' ';
               break;
            }
            case '[':
               cout <<  '\'';

               break;
            case ']':
               cout << '\'' <<  ' '; // for some reason couting '\' ' 
               break;             // puts out numbers, so they are separate
            case '.':
               cout << endl;
               break;
            case '"':
               break;
            case '!':
               break;
         }
      }
      else if (madLib[i + 1][0] == '<' || ispunct(madLib[i + 1][0]))
      {
                  // yet more correction for spacing. 
         cout << madLib[i];
         switch (madLib[i + 1][1])
         {
            case '{':
            case '[':
               cout << ' ';
               break;
            case '#':
            case '}':
            case ']':
            case '.':
               break;
         }
      }

      else
         cout << madLib[i] << " ";
   }

}

/*****************************************************
 * playAgain will ask the player if they want to play
 * again, and if so, restart the program.
 *****************************************************/
void playAgain(char &play)
{
   cout << endl;
   cout << "Do you want to play again (y/n)? ";
   cin >> play;
}

/*****************************************************
 * Main will call all other functions to do the work
 * and at the end, will say thank you for playing.
 *****************************************************/
int main ()
{
   char madLib[256][36];
   char fileName[256];   // initialize everything.
   char play = 'y';
   
   while (play == 'y')
   {
      // in a while loop to restart if 
      // the player wants to play again.
      getFileName(fileName);
      int numWords = readFile(fileName, madLib);
      askQuestions(madLib, numWords);
      display(madLib, numWords);
      playAgain(play);
   }
   cout << "Thank you for playing.\n";
   return 0;
}
