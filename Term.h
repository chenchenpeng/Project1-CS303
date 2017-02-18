#ifndef TERM_H
#define TERM_H

#include <iostream>

class Term {
private:
	double coefficient;
	double exponent;

public:
	Term() {
		coefficient = 0;
		exponent = 0;
	}
	Term(double c, double e) {
		coefficient = c;
		exponent = e;
	}

	const Term& operator + (const Term& other) {
		if (this->exponent != other.exponent) {
			throw std::exception("Cannot add two terms with different exponents!");
		}
		else {
			this->coefficient += other.coefficient;
		}
		return *this;
	}

	bool operator < (const Term& other) {
		return this->exponent < other.exponent;
	}

	bool operator > (const Term& other) {
		return this->exponent > other.exponent;
	}

	bool operator >= (const Term& other) {
		return this->exponent >= other.exponent;
	}
	
	bool operator <= (const Term& other) {
		return this->exponent <= other.exponent;
	}

	bool operator == (const Term& other) {
		return this->exponent == other.exponent;
	}

	bool operator != (const Term& other) {
		return this->exponent != other.exponent;
	}
};

#endif