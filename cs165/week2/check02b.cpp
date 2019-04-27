/***********************************************************************
* Program:
*    Checkpoint 02b, Structs
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/***********************************
 * Complex
 * this structure defines a set of doubles
 **********************************/
struct Complex
{
	double realNumber;
	double imaginaryNumber;
};

/***********************************
 * promptNumbers
 * Asks user for numbers and saves responses
 **********************************/
Complex promptNumbers()
{
	Complex complex;
	cout << "Real: ";
	cin >> complex.realNumber;
	cout << "Imaginary: ";
	cin >> complex.imaginaryNumber;
	return complex;
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   Complex sum;
   sum.realNumber = x.realNumber + y.realNumber;
   sum.imaginaryNumber = x.imaginaryNumber + y.imaginaryNumber;
   return sum;
}

/***********************************
 * display
 * shows the sum of numbers
 **********************************/
void display(Complex sum)
{
	cout << sum.realNumber << " + " << sum.imaginaryNumber << "i";
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Complex c1;
   Complex c2;
   c1 = promptNumbers();
   c2 = promptNumbers();
   Complex sum;
   sum = addComplex(c1, c2);   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
   return 0;
}


