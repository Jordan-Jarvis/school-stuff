/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Ercanbrack, CS 235
 * Author:
 *    Jordan Jarvis
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include "huffman.h"       // for HUFFMAN() prototype
#include "pair.h"
#include "bnode.h"
#include <iostream>
#include <fstream>
// cplusplus.com said to use it.
#include <algorithm>

using namespace std;

/************************************************************
* types to be used to shorten the declaration of things
* in the huffman coding and removes classes
************************************************************/

typedef Pair <string, string> STRINGP;
typedef vector <STRINGP> STRINGV;
typedef Pair <string, float> PAIR;
typedef BinaryNode <PAIR> BNODE;
typedef vector <BNODE*> BNV;

void getFile(string & filename);
void readFile(string & filename, PAIR & temp, BNODE * node, BNV & data);
void makeTree(BNV & data);
bool compareNode(BNODE * left, BNODE * right);
void codeIt(BNODE * newNode, string empty, STRINGV & code);
bool compareString(STRINGP left, STRINGP right);
void display(const STRINGV code);

/*******************************************
 * huffman
 * runs everything
 *******************************************/
void huffman(string filename)
{
   BNV data;
   STRINGV code;
   PAIR temp;
   BNODE * node;
   readFile(filename, temp, node, data);

   sort(data.begin(), data.end(), compareNode);

   makeTree(data);

   codeIt(data[0], "", code);

   sort(code.begin(), code.end(), compareString);

   display(code);
   return;
}

/*******************************************************************
 * readFile
 * Reads the file, sets to nodes
 *******************************************************************/
void readFile(string & filename, PAIR & temp, BNODE * node, BNV & data)
{
   ifstream things(filename.c_str());

   while (things >> temp)
   {
      node = new BNODE(temp);
      data.push_back(node);
   }
   things.close();
}

/*********************************************************************
 * makeTree
 * makes the huffman tree
 ********************************************************************/
void makeTree(BNV & data)
{
   while (data.size() > 1)
   {
      //so we know where to start
      int size = data.size();

      //create the new node
      BNODE * parent = new BNODE
      (*(new PAIR(data[size-1]->data.first +data[size-2]->data.first,
       data[size-1]->data.second + data[size-2]->data.second)));

      //assign the left and right children
      parent->addLeft(data[size-1]);
      parent->addRight(data[size-2]);
      data.pop_back();
      data.pop_back();
      data.push_back(parent);

      // keep things organized
      sort(data.begin(), data.end(), compareNode);
   }
}

/********************************************************************
 * compareNode
 * compares nodes and finds the greatest
 ********************************************************************/
bool compareNode(BNODE * left, BNODE * right)
{
   if (left->data.second == right->data.second)
      return (left->data >= right->data);

   return (left->data.second >= right->data.second);
}

/*********************************************************************
 * codeIt
 * sets the actual code for decryption
 *********************************************************************/
void codeIt(BNODE * newNode, string newString, STRINGV & code)
{
   if(newNode == NULL)
      return;

    codeIt(newNode->pLeft, newString + "0", code);
    codeIt(newNode->pRight, newString + "1", code);

    if(newNode->pLeft == NULL && newNode->pRight == NULL)
       code.push_back(STRINGP(newNode->data.first, newString));

}

/**********************************************************************
 * compareString
 * says if the left is greater than the right
 **********************************************************************/
bool compareString(STRINGP left, STRINGP right)
{
   return (left < right);
}

/**********************************************************************
 * display
 * shows the code and what it means
 **********************************************************************/
void display(const STRINGV code)
{
    for(int i = 0; i < code.size(); i++)
       cout << code[i].first << " = " << code[i].second << endl;

}