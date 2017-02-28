#ifndef TERM_H
#define TERM_H

#include <iostream>

class Term {
private:
	int coefficient;
	int exponent;

public:
	//Construct a default Term consist of exponent and coefficient
	Term() {
		coefficient = 0;
		exponent = 0;
	}

	/**Construct a new Term
	@param c (coefficient)
	@param e (exponent)
	*/
	Term(int c, int e) {
		coefficient = c;
		exponent = e;
	}

	//Overload the + operator to add the Terms with the same exponents
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

	//Return the value in coefficient
	int getCoef() {
		return this->coefficient;
	}

	//Update the value in coefficient
	void setCoef(int coef) {
		this->coefficient = coef;
	}

	//Update the value in exponent
	void setExpn(int expn) {
		this->exponent = expn;
	}

	//Return the value in exponent
	int getExpn() {
		return this->exponent;
	}
};

#endif
