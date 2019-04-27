/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235e
 * Author:
 *    Jordan Jarvis
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

int getWeight(char test)
{
   switch (test)
   {
      case '#':
      return 5;
      case '+': 
      case '-': 
      {
         return 1;
      }
      case '*': case '//': case '%':
      {
         return 2;
      }
      case '^':
      {
      return 3;
      }
      case '(':
      {
         return 4;
      }
      default:
      break;
   }
   return 0;
}
/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix( string & infix)
{
  //std::cout << infix << std::endl;
   string postfix = " ";
   string space = " ";
   Stack <char> symb;
    bool tried = false;
    char saveLast;
    symb.push('#');
    for (int i = 0; i < infix.length(); i++)
    {
       
       switch (infix[i])
       {
          case '+': case '-': case '*': case '//': case '^': case '%': case '(':
         {
            saveLast = infix[i];

            if (symb.top() == '#' || getWeight(symb.top()) <= getWeight(infix[i]))
            {
               
               symb.push(infix[i]);
               
               break;
            }
            else
            {
               
               try {
                  while (!symb.empty())
                  {


                  postfix += symb.top();
                  
                  symb.pop();
                  }

               } catch(const std::exception& e) {
                  symb.push(infix[i]);
                  }
                  
               string s;
              
            }
            
         }
         break;
          
         
          

          case ' ':
          {
            //postfix += space;
             break;
          }
          default:
          {          
             
             postfix += infix[i];
             break;   
          }
          
      }

      if (infix[i] == ' ')
             {
                postfix += space;
             }
   }

   while (!symb.empty())
   {
      postfix += symb.top();
      
      //postfix += space;
      symb.pop();  
   }     
   if (tried == true){
      
      postfix += saveLast;
   }
   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
