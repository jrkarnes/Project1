/* This is the test bracket that I am using to test terms. It makes the following assumption:
	1) The variable used in the terms is always "x"
*/
#include "Term.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
//declare functions
list<Term> readPolynomial(string& Polynomial);

int main()
{
	string input="4x^3-12x^2+3";
	list<Term> firstPoly= readPolynomial(input);
	//print out terms
	for (list<Term>::iterator i = firstPoly.begin(); i!=firstPoly.end();++i)
	{
		cout << " Term: " << *i ;
	}
	system("pause");
	return(0);
}
