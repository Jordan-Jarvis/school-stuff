/***********************************************************************
* Program:
*    Checkpoint 04a, classes   (e.g. Checkpoint 01a, review)           
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>

using namespace std;

/**********************************************************************
 * class book
 * Purpose: to declare a new class to store a book and author
 ***********************************************************************/
class Book
{
   private: 
      string title;
      string author;
   public:
      void prompt (Book &book);
      void display(Book &book);
};

/**********************************************************************
 * Function: prompt
 * Purpose: ask user for title and author, then store it.
 ***********************************************************************/
void Book :: prompt(Book &book)
{
   cout << "Title: ";
   getline(cin, book.title);
   cout << "Author: ";
   getline(cin, book.author);
}

/**********************************************************************
 * Function: display
 * Purpose: shows the author and title eneterd earlier
 ***********************************************************************/
void Book :: display(Book &book)
{
   cout << "\"" << book.title << "\" by " << book.author << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: call other functions to do all the work.
 ***********************************************************************/
int main()
{
   Book book;
   book.prompt(book);
   book.display(book);
   return 0;
}
