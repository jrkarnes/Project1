#include "Term.h"
#include <string> 
#include "String_Tokenizer.h"
#include <list>
using namespace std;
//this function reads a polynomial from a string and return the polynomial as a list
list<Term> readPolynomial(string& Polynomial)
{
	int expo = 0;
	int coef = 0;
	string coefSt;
	string expoSt;
	list<Term> MyPolynomial;
	//replace - with +-
	size_t position = Polynomial.find("-");
	Polynomial.replace(position, std::string("-").length(), "+-");
	//split input by + to get separated terms
	String_Tokenizer st1(Polynomial, "+");
	// as long as there is a term to parse
	while (st1.has_more_tokens())
	{
		string currentTerm = st1.next_token();
		//split currentTerm by x^
		String_Tokenizer st2(currentTerm, "x^");
		coefSt = st2.next_token();
		expoSt = st2.next_token();
		if (expoSt == "") expoSt = "0"; // if there is no exponent
		//convert to int
		coef= stoi(coefSt);
		expo=stoi(expoSt);
		//create the term and add to the list
		MyPolynomial.push_back(Term(coef,expo));
	}
	return MyPolynomial;
}
