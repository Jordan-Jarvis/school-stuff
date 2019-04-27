/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Jordan Jarvis
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
    cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";
   
   Set <Card> hand;
   Card *fish;
   Card guess;
   int matches = 0; 
   Card card;

   // reads the file
   ifstream fin("/home/cs235e/week05/hand.txt");
   if (fin.fail())
   {
      cout << "FAIL";
   }
   //inserts the items of the file, one at a time
   while(!fin.eof())
   {
      fin >> card;
      hand.insert(card);
   }
   // Play a round
   for (int i = 1; i <= 5; i++)
   {
      cout << "round " << i << ": ";
      cin >> guess;
      
      if (hand.find(guess) > 0)
      {
         matches++;
         hand.erase(hand.find(guess));
         cout << "\tYou got a match!\n";
      }
      
      else 
         cout << "\tGo Fish!\n";
   }

   // Display the matches
   cout << "You have " << matches << " matches!\n"
        << "The remaining cards: ";

   //bool to check for a need for a comma
   bool notFirst = false;
   for (SetIterator <Card> it = hand.begin(); it != hand.end(); it++)
   {
      //dont display if card is invalid
      if (*it == "-INVALID-")
      {
         //do nothing
      }
      else
      {
         if (notFirst)
            cout << ", ";
         else
            notFirst = true;
         cout << *it;
      }
   }
   cout << endl;
   return ;
}

