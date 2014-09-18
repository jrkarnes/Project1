/*
Justin Karnes
Term Class declarations
*/
#pragma once
#include <exception>
#include <stdexcept>
#include "Term.h"

// Default Constructor
Term::Term()
{}

//Argument Constructor
Term::Term(int new_coefficient, int new_exponent){
	coefficient = new_coefficient;
	exponent_negative = (new_exponent<0);
	exponent = new_exponent;
}

// Destructor
Term::~Term()
{}

// Get and Set functions
int Term::get_coefficient(void) const{
	return this->coefficient;}

int Term::get_exponent(void) const{
	if (exponent_negative)
		return exponent*-1;
	else
		return exponent;
}

bool Term::is_exponent_negative(void) const{
	return exponent_negative;
}

void Term::set_coefficient(int new_coefficient){
	coefficient = new_coefficient;
}

void Term::set_exponent(int new_exponent){
	if (new_exponent < 0)
	{
		exponent_negative = true;
		exponent = -1 * new_exponent;
	}
	else exponent = new_exponent;
}

void Term::set_negative_flag(bool new_status){
	exponent_negative = new_status;
}

const Term Term::operator+(const Term& L_term){
	if (this->exponent == L_term.exponent){
		return Term((this->coefficient + L_term.coefficient), this->exponent);
	}
	else throw std::logic_error("Exponents of Terms must match.");
}
