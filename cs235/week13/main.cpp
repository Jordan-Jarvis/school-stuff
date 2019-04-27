/***********************************************************************
 * Module:
 *    Week 13, Genealogy
 *    Brother Helfrich, CS 235
 * Author:
 *    Jordan Jarvis
 * Summary:
 *    This program will sort .ged files and parse them
 ************************************************************************/

#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

void parseFile(ifstream &inFile, Person* &headPointer);
void showList(ofstream &outFile, Person* &headPointer);
void level(Person* &headPointer);
void printGen(int generation);

int main(int argc, char* argv[])
{

   
   if (argc != 2)
   {
      cout << "please enter an argument including the file you want to parse" << endl;
      return 1;
   }
   ifstream fin(argv[1]);
   if (fin.fail())
   {
      cout << "\nError opening file!!\n";
      return 1;
   }
   Person* treeNode = NULL;
   ofstream fout("sorted.dat");
   parseFile(fin, treeNode); // read in file and parse
   showList(fout, treeNode); // show list of people
   level(treeNode); // level order traversal
   
   while (treeNode != NULL) // clear memory
   {
      treeNode = treeNode->getNext();
      delete treeNode;
   }  
   fin.close(); // close input  file 
   fout.close(); // close output file
}

/**********************************************************************
 * Takes the info from the file and parses it out into a Person 
 * node.
 ***********************************************************************/
void parseFile(ifstream &inFile, Person* &headPointer)
{
   Person* pointer = NULL;
   string father; 
   string mother;
   string child;   
   int count = 0;
   string tmp;
   string tmp1; 
   int i = 0;
   while (true)
   {
      getline (inFile, tmp);
      if (tmp == "0 @F1@ FAM")
         break;

      string test = tmp.substr(0,4);
      if(test == "0 @I")
      {
         sortedPersonInsert(headPointer, pointer);
         tmp1.clear();
         tmp.erase(0, 3);
         while (tmp[0] != '@')
         {
            tmp1 += tmp[0];
            tmp.erase(0,1);
         }
         pointer = new Person;
         pointer->setINDI(tmp1);
      }
      else if(test == "1 BI")
      {
         getline(inFile, tmp);
         if (tmp.find("DATE") != std::string::npos)
         {
            tmp.erase(0,7);
            tmp1.clear();
            if (tmp.length() != 0) 
            {
               for (int i = 0; i < tmp.length(); i++)
               {
                  if (isalpha(tmp[i]))
                  {
                     tmp1 += tmp[i];
                     tmp.erase(i, 1);
                     i--;
                  }
               }
               pointer->setMonth(tmp1);
               tmp1.erase();
               if (tmp[0] == ' ')
               {
                  tmp.erase(0, 1);
               }

               while (tmp.length() != 0 && (isdigit(tmp[0])
                      || tmp[0] == '/'))
               {
                  tmp1 += tmp[0];
                  tmp.erase(0, 1);
               }
               if (tmp1.length() > 2) 
               {
                  pointer->setYear(tmp1); 
               }
               else
               {
                  pointer->setDay(tmp1);
               }
               if (tmp.length() != 0) 
               {
                  tmp.erase(0, 2); 
                  tmp1.clear();
               
                  while (tmp.length() != 0) 
                  {
                     tmp1 += tmp[0];
                     tmp.erase(0, 1);  
                  }
                  pointer->setYear(tmp1);
               }
            }   
         } 
      }
      else if (test == "2 GI")
      {
         tmp.erase(0,7);
         pointer->setFName(tmp);
      }
      else if(test == "2 SU")
      {
         tmp.erase(0, 7);
         pointer->setLName(tmp);
      }
   }
   sortedPersonInsert(headPointer, pointer); 
   pointer = headPointer; 
   Person* altPointer = pointer; 
   while (true)
   {
      getline(inFile, tmp);
      string test = tmp.substr(0,4);
      if (tmp == "0 @S1@ SOUR")
         break;
      
      if (test == "1 HU")
      {
         tmp.erase(0,8);
         tmp1.clear();
         while (tmp[0] != '@')
         {
            tmp1 += tmp[0];
            tmp.erase(0,1);
         }
         father = tmp1;
      }
      else if (test == "1 CH")
      {
         tmp.erase(0,8);
         tmp1.clear();
         while (tmp[0] != '@')
         {
            tmp1 += tmp[0];
            tmp.erase(0,1);
         }
         child = tmp1;

         pointer = headPointer;
         altPointer = headPointer;
         while (child != pointer->getINDI())
            pointer = pointer->getNext();
  
         while (father != "" 
         && father != altPointer->getINDI())
            altPointer = altPointer->getNext();
      
         if (father != "")
            pointer->setFather(altPointer);
         
         altPointer = headPointer;
         while (mother != "" 
         && mother != altPointer->getINDI())
            altPointer = altPointer->getNext();
         
         if (mother != "")
            pointer->setMother(altPointer);
         father.clear();
         mother.clear();
      }
      else if (test == "1 WI") 
      {
         tmp.erase(0,8);
         tmp1.clear();
         while (tmp[0] != '@')
         {
            tmp1 += tmp[0];
            tmp.erase(0,1);
         }
         mother = tmp1;
      }
      
   }  
}

/**********************************************************************
 * Shows list in order needed to match the 1st test
 ***********************************************************************/
void showList(ofstream &outFile, Person* &headPointer)
{
   Person* pointer = headPointer;
   
   while (pointer != NULL)
   {
      if (pointer->getFirstName() != "")
      {
         outFile << pointer->getFirstName();
      }
      if (pointer->getLastName() != "" && pointer->getFirstName() != "")
      {
         outFile << " " << pointer->getLastName();
      }
      else
      {
         outFile << pointer->getLastName();
      }
      if (pointer->getDay() != "" || pointer->getMonth() != "" 
      || pointer->getYear() != "")
      {
         outFile << ", b. ";
      }
      if (pointer->getDay() != "")
      {
         outFile << pointer->getDay() << " ";
      }
      if (pointer->getMonth() != "")
      {
         outFile << pointer->getMonth() << " ";
      }
      if (pointer->getYear() != "")
      {
         outFile << pointer->getYear();
      }
      outFile << endl;
      pointer = pointer->getNext();
   }     
}

/**********************************************************************
 * level order traversal and display of the tree, This was partially provided
 * in the assignment file level.cpp.
 ***********************************************************************/
void level(Person* &headPointer)
{
   const int MAX = 300;
   Person* queue[MAX];
   Person* temp = headPointer;
   int front = 0;
   int back = 0;
   int saveBack = 1;
   int generation = 0;
 
   while (temp->getINDI() != "I1")
      temp = temp->getNext();
   
   queue[back++] = temp;
   cout << "The Ancestors of " << temp->getFirstName() << " " << temp->getLastName()
        << ":" << endl;
   while (front != back)
   {
      temp = queue[front];
      if (front == saveBack)
      {
         generation++;
         printGen(generation);
         saveBack = back;
         
      }
             
      front = (front + 1) % MAX;
      
      if (temp != NULL)
      {
         if (front != 1)
         {
            cout << "        ";
            if (temp->getFirstName() != "")
               cout << temp->getFirstName();
            if (temp->getLastName() != "" && temp->getFirstName() != "")
               cout << " " << temp->getLastName();
            else
               cout << temp->getLastName();
      
            if (temp->getDay() != "" || temp->getMonth() != ""
                || temp->getYear() != "")
               cout<< ", b. ";
            if (temp->getDay() != "")
               cout << temp->getDay() << " ";
            if (temp->getMonth() != "")
               cout << temp->getMonth() << " ";
            if (temp->getYear() != "")
               cout << temp->getYear();
            cout << endl;
         }         
         queue[back] = temp->getFather();
         back = (back + 1) % MAX;
         queue[back] = temp->getMother();
         back = (back + 1) % MAX;
      }
   }
}

/**********************************************************************
 * displays the generation that is being read.
 ***********************************************************************/
void printGen(int generation)
{
   switch ((generation))
   {
      case 1: std::cout << "Parents:\n";
         break;
      case 2: std::cout << "Grandparents:\n";
         break;
      case 3: std::cout << "Great Grandparents:\n";
         break;
      case 4: std::cout << "2nd Great Grandparents:\n";
         break;
      case 5: std::cout << "3rd Great Grandparents:\n";
         break;
      case 6: std::cout << "4th Great Grandparents:\n";
         break;
      case 7: std::cout << "5th Great Grandparents:\n";
         break;
      default: 
         return;
   }
}
