/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Book
{
   private:
   public:
   string title;
   string author;
   int publicationYear;
   void promptBookInfo();
   void displayBookInfo();
};

void Book::promptBookInfo()
{
   
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);
   cout << "Publication Year: ";
   cin >> publicationYear;
   cin.ignore();
}

void Book::displayBookInfo()
{
   cout << title << " (" << publicationYear << ") by " << author << endl;
}


class TextBook : public Book
{
   private:
   public:
   string subject;
   void promptSubject();
   void displaySubject();
   
};

void TextBook::promptSubject()
{
   cout << "Subject: ";
   getline(cin, subject);
}

void TextBook::displaySubject()
{
   displayBookInfo();
   cout << "Subject: " << subject << endl;
}

class PictureBook : public Book
{
   private:
   public:
   string illustrator;
   void promptIllustrator();
   void displayIllustrator();
};

void PictureBook::promptIllustrator()
{
   cout << "Illustrator: ";
   getline(cin, illustrator);
}

void PictureBook::displayIllustrator()
{
   cout << "Illustrated by " << illustrator << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book book;
   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();
   cout << endl;

   TextBook textBook;
   textBook.promptBookInfo();
   textBook.promptSubject();
   cout << endl;
   textBook.displaySubject();
   cout << endl;
   
   PictureBook pictureBook;
   pictureBook.promptBookInfo();
   pictureBook.promptIllustrator();
   cout << endl;
   pictureBook.displayBookInfo();
   pictureBook.displayIllustrator();

   return 0;
}


