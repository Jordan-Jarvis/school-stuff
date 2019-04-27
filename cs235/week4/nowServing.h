/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jordan Jarvis
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H
using namespace std; 
#include <string>

#include "deque.h"     

void nowServing();

class Stud {
   public:
      string clas;
      string name;
      int min;
      bool emergency;
};
#endif 

