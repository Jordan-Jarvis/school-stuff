
using namespace std;

class Person
{
   private:
      string month;
      string year;
      string INDI;
      Person* father;
      Person* mother;
      Person* next;
      string firstName;            
      string lastName;
      string day;
  
   public:
      Person()   {mother = NULL; father = NULL; next = NULL;}                
      string getFirstName()   {return firstName;}            
      string getLastName()   {return lastName;}
      string getDay()   {return day;}
      string getMonth()   {return month;}
      string getYear()   {return year;}
      string getINDI()   {return INDI;}
      Person* getFather()   {return father;}
      Person* getMother()   {return mother;}
      Person* getNext()   {return next;}
      void setFName(string First)   {firstName = First;} 
      void setLName(string Last)   {lastName = Last;}
      void setDay(string Day)   {day = Day;}
      void setMonth(string Month)   {month = Month;}
      void setYear(string Year)   {year = Year;}
      void setINDI(string INDI1)   {INDI = INDI1;}
      void setFather(Person* Father1)   {father = Father1;}
      void setMother(Person* Mother1)   {mother = Mother1;}
      void setNext(Person* aNext)   {next = aNext;}
};

/**********************************************************************
 * Inserts people into the tree
 ***********************************************************************/
void sortedPersonInsert(Person* &headPointer, Person* &pointer)
{
   if(pointer == NULL)
      return;
   if(headPointer == NULL)
   {
      headPointer = pointer;
      return;
   }
   string pointerLastName = pointer->getLastName();
   pointerLastName[0] = toupper(pointerLastName[0]);
  
   string headLastName = headPointer->getLastName();
   headLastName[0] = toupper(headLastName[0]);
  
   if (pointerLastName < headLastName)
   {
      pointer->setNext(headPointer);
      headPointer = pointer;
      return;
   }
   else if (pointerLastName == headLastName && pointer->getFirstName() < headPointer->getFirstName())
   {
      pointer->setNext(headPointer);
      headPointer = pointer;
      return;
   }

   Person* headCopy = headPointer;
   Person* nextPersonPointer = headPointer->getNext();
   string nextLastName;

   while (nextPersonPointer != NULL)
   {
      nextLastName = nextPersonPointer->getLastName();
      nextLastName[0] = toupper(nextLastName[0]);
   
      if (pointerLastName > nextLastName)
      {
         headCopy = nextPersonPointer;
         nextPersonPointer = nextPersonPointer->getNext();
      }
      else if (pointerLastName == nextLastName && pointer->getFirstName() > nextPersonPointer->getFirstName())
      {
         headCopy = nextPersonPointer;
         nextPersonPointer = nextPersonPointer->getNext();
      }
      else if (pointerLastName == nextLastName && pointer->getFirstName() == nextPersonPointer->getFirstName()
               && pointer->getYear() > nextPersonPointer->getYear())
      {
         headCopy = nextPersonPointer;
         nextPersonPointer = nextPersonPointer->getNext();
      }
      else
         break;    
   }
   headCopy->setNext(pointer);
   pointer->setNext(nextPersonPointer);
}