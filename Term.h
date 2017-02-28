#ifndef TERM_H
#define TERM_H

#include <iostream>

class Term {
private:
	double coefficient;
	double exponent;

public:
	//Construct a default Term consist of exponent and coefficient
	Term() {
		coefficient = 0;
		exponent = 0;
	}

	/**Construct a new Term 
	@param c
	@param e
	*/
	Term(double c, double e) {
		coefficient = c;
		exponent = e;
	}

	//Overload the + operator too add the terms with the same exponents
	const Term& operator + (const Term& other) {
		if (this->exponent != other.exponent) {
			throw std::exception("Cannot add two terms with different exponents!");
		}
		else {
			this->coefficient += other.coefficient;
		}
		return *this;
	}

	/**Overload the < operator to compare the exponents of the Terms
	   See whether the left Term's exponent is smaller than the right 
	   Term's exponent
	*/
	bool operator < (const Term& other) {
		return this->exponent < other.exponent;
	}

	/**Overload the > operator to compare the exponents of the Terms
	   See whether the left Term's exponent is bigger than the right 
	   Term's exponent
	*/
	bool operator > (const Term& other) {
		return this->exponent > other.exponent;
	}

	/**Overload the >= operator to compare the exponents of the Terms
	   See whether the left Term's exponent is bigger than or equal to the 
	   right Term's exponent
	*/
	bool operator >= (const Term& other) {
		return this->exponent >= other.exponent;
	}
	
	/**Overload the <= operator to compare the exponents of the Terms
	   See whether the left Term's exponent is less than or equal to the
	   right Term's exponent
	*/
	bool operator <= (const Term& other) {
		return this->exponent <= other.exponent;
	}

	/**Overload the == operator to compare the exponents of the Terms
	   See whether the left Term's exponent is equal to the right Term's 
	   exponent
	*/
	bool operator == (const Term& other) {
		return this->exponent == other.exponent;
	}

	/**Overload the != operator to compare the exponents of the Terms
	See whether the left Term's exponent is not equal to the right 
	Term's exponent
	*/
	bool operator != (const Term& other) {
		return this->exponent != other.exponent;
	}
	//returns the value in coefficient
	int getCoef() {
		return this->coefficient;
	}
	//updates the value in coefficient
	void setCoef(int coef) {
		this->coefficient = coef;
	}
	//updates the value in exponent
	void setExpn(int expn) {
		this->exponent = expn;
	}
	//returns the value in exponent
	int getExpn() {
		return this->exponent;
	}
};

#endif
