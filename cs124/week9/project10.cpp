#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char *file);
int readFile(char *file, char story[][256]);
char getInfo(char story[][256], int numWords);
void display(char story[][256], int numWords);
void askQuestions(char story[][256], int i);
void playAgain(char file[256]);
int main();
/**********************************************************************
 * This main funtion will call all other functions and run the entire program.
 ***********************************************************************/

/**********************************
This will bring everything together and display the story
**********************************/



int main()
{
   char story[256][256];
   char file[256];
   int numWords = 0;


   getFileName(file);
   numWords = readFile(file, story);
   getInfo(story,numWords);
   display(story,numWords);
   playAgain(file);

   return 0;
}
/*************************
This will get the file name
*************************/


void getFileName(char *file)
{
   // gets the name of the file
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(file, 256);

}

/**************************
This will read the file and check for errors and make sure the
story is the correct size
***********************/



int readFile(char *file, char story[][256])
{
   ifstream fin(file);
   int numWords = 0;

// error checking

   if (fin.fail())
   {
      cout << "Error reading file. ";

      return -1;
   }

// size checking

   while(numWords <= 256 && !fin.eof())
      fin >> story[numWords++];

   fin.close();

   return numWords;

}

/*************************
This will get the words that the user wants to put into the story
************************/

char getInfo(char story[][256], int numWords)
{

   char wordChange[256];

   // this will go through the letters of the words and find the
   // symbols and remove them or add in something else
   for (int i = 0; i < numWords; i++)
 {
      if(story[i][0] == '<')
      {
         if (isalpha(story[i][1]))
         {
            cout << "\t";
            for(int j = 1; story[i][j]!= '>' ; j++)
            {
               if (j == 1)
                  cout << (char)toupper(story[i][1]);
               else if (story[i][j] == '_')
                  cout << ' ';
               else
                  cout << story[i][j];
            }

            cout << ": ";
            askQuestions(story, i);

         }
      }
   }
   cout << endl;
}

/**********************
This will display the story
*********************/
void askQuestions(char story[256][256], int i)
{
   cin.getline(story[i], 256);

}

/**********************
This will display the story
*********************/
void display(char story[][256], int numWords)
{
// goes word for word and displays the story

   // this will go through the letters of the words and find the
   // symbols and remove them or add in something else
   for (int i = 0; i < numWords; i++)
   {
      if(story[i][0] == '<')
      {
          switch (story[i][1])
         {
            case '#':
               cout << '\n';
               story[i][0] = '\n';
               story[i][0] = '\0';

               break;
            case '{':
               cout << '"';
               //story[i][0] = ' ';
               //story[i][0] = '"';
               break;
            case '}':
               cout <<  '"';
               cout << ' ';
               //           story[i][0] = '"';
               //story[i][0] = ' ';
               break;
            case '[':
               cout <<  '\'';
               // story[i][0] = ' ';
               // story[i][0] = '\'';
               break;
            case ']':
               cout << '\'';
               cout <<  ' ';
               break;
            case '.':
               cout << endl;
               break;
            case '?':
               cout << endl;
               break;
            case '"':
               break;
            case '!':
               break;
         }
      }
  else if(story[i + 1][0] == '<' || ispunct(story[i + 1][0]))
      {
         cout << story[i];
         switch (story[i + 1][1])
         {
            case '{':
            case '[':
               cout << ' ';
            break;
            case '#':
            case '}':
            case ']':
            case '.':
            case '?':
            case '!':
               break;
         }
      }

      else
         cout << story[i] << " ";
   }
}


void playAgain(char file[256])
{
  char choice;
  char newFile;

  cout << endl;
  cout << "Do you want to play again (y/n)? " ;
  cin >> choice;

  if (choice == 'y')
  {






  }
  else
     cout << "Thank you for playing." << endl;


}