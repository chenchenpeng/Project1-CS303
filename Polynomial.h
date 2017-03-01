#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class Polynomial {
private:
	//A list of class term which contains expon and coeff ints, defaults to empty list
	std::list<Term> T;

public:
	//Insert new node into list in order decending by expn
	void OrderedInsert(const int expn, const int coef) {
		Term newNode;
		//int compareExpn, coeffecient;
		newNode = Term(coef, expn);
		//Check for empty list and push node to front if empty
		if (T.empty()) {
			T.push_front(newNode);
		}
		else {
			//Traverse list using an iterator to find ordered insert placement
			std::list<Term>::iterator& itr = T.begin();
			while (itr != T.end()) {
				//Get value of current nodes expn for comparison, if they are equal, add coef to the nodes coef
				if (itr->getExpn() == expn) {
					itr->setCoef(itr->getCoef() + coef);
					//If the new coef = 0, erase the node
					if (itr->getCoef() == 0) {
						itr = T.erase(itr);
					}
					return;
				}
				//If nodes expn is greater than expn, iterator to the next node
				else if (itr->getExpn() > expn) {
					++itr;
					//If at the end of the list, expn is less than all expn in the list, 
					//Push a new node to the end of the list
					if (itr == T.end()) {
						T.push_back(newNode);
						return;
					}
				}
				else if (itr->getCoef() == 0) //Avoid keeping track of terms with zero coefficient
				{
					++itr;
				}
				//defualt
				else {
					itr = T.insert(itr, newNode);
					return;
				}
			}
		}
	}
	//Read expression into a dll list of term type with int coeff and int expon
	void ReadFromString(std::string exprInput) {
		std::string term, searchForSecondStr;
		int index2ndSign, i, j, expnLocation, expnOffset;
		int expn, coef;
		expn = 0;
		coef = 0;
		//Convert str it upper for X comparison ref:cpluplus.com
		std::transform(exprInput.begin(), exprInput.end(), exprInput.begin(), ::toupper);
		while (!exprInput.empty()) {
			i = 0;
			j = 0;
			//Ignore leading + or -
			i = exprInput.find_first_of("+-");
			//If leading + or minus truncate off str for second + or - search
			if (i == 0) {
				i = 1;
				searchForSecondStr = exprInput.substr(1);
			}
			else {
				i = 0;
				searchForSecondStr = exprInput;
			}
			if (!searchForSecondStr.empty()) {
				//find next + or -
				j = searchForSecondStr.find_first_of("+-");
				if (j >= 0) {
					/**Split string into everything before the + or minus (term)
					and everything from the + or minus on for next iteration
					*/
					index2ndSign = j + i;
					term = exprInput.substr(0, index2ndSign);
					exprInput = exprInput.substr(index2ndSign);
				}
				/**Case for when only one term is in the string, also empties
				string to exit while loop
				*/
				else {
					term = exprInput;
					exprInput = "";
				}
			}
			//search for X in the term string. If X is not found, convert the whole term to int
			i = term.find_first_of('X');
			expnOffset = 0;
			expnLocation = term.find_first_of('^');
			//X found
			if (i >= 0) {
				//^ found skip two characters to find expn
				if (expnLocation >= 0) {
					expnOffset = i + 2;
					//Convert expn string to int ref:cplusplus.com
					expn = stoi(term.substr(expnOffset));
				}
				else {
					expn = 1;//^ not found, value of X is 1
				}
				//Check for term begins with -X the coef is -1
				if (term.substr(0, 1) == "-" && i == 1) {
					coef = -1;
				}
				else if (term.substr(0, 1) == "+" && i == 1) { // Check for term begins with +X the coef is 1
					coef = 1;
				}
				else if (i == 0) { //X is first char in term then coef is 1
					coef = 1;
				}
				else {
					coef = stoi(term.substr(0, i));//No special cases, convert everything before X to int ref:cplusplus.com
				}
			}
			else { //X not found, expn is 0, convert whole term to int ref:cplusplus.com
				expn = 0;
				coef = stoi(term);
			}
			//Send expn and coef to the list for ordered insert
			orderedInsert(expn, coef);
		}
	}

	//Add two polynomial lists into the list that calls add
	//Use references to two other polyniomial lists
	void Add(Polynomial& Poly1, Polynomial& Poly2) {
		std::list<Term>::iterator ptr1 = Poly1.T.begin(), ptr2 = Poly2.T.begin();
		//Insert 1st list a new list using ordered insert
		while (ptr1 != Poly1.T.end()) {
			orderedInsert(ptr1->getExpn(), ptr1->getCoef());
			++ptr1;
		}
		//Insert 2nd list into the new list using ordered insert
		while (ptr2 != Poly2.T.end()) {
			orderedInsert(ptr2->getExpn(), ptr2->getCoef());
			++ptr2;
		}
	}

	//Output the list as a stringed friendly polynomial
	void Output() {
		std::list<Term>::iterator ptr = T.begin();
		std::string output;
		int coef, expn, nextcoef;
		output = "";
		if (!T.empty()) {
			while (ptr != T.end()) {
				coef = ptr->getCoef();
				//Add Coefficient to the output string if coeff is not 1 or 0
				if (coef != 1 && coef != -1) {
					output = output + std::to_string(coef);
				}
				//Add - to the output string and ignore the digit of coef -1
				if (coef == -1) {
					output = output + "-";
				}
				//Add expn to the output string
				expn = ptr->getExpn();
				if (expn < 0 || expn > 1) { // Add X^ if the expn greater than 1 or less than 0
					output = output + "X^" + std::to_string(expn);
				}
				else if (expn == 1) { //Add X if the expn = 1
					output = output + "X";
				}
				ptr++; //Advance ptr, check to see if there is another term, if so add + to output for positive coeffs
				if (ptr != T.end()) {
					nextcoef = ptr->getCoef();
					if (nextcoef > 0) {
						output = output + "+";
					}
				}
			}
			//Verify that output has no leading +
			if (output.substr(0, 1) == "+") {
				output = output.substr(1);
			}
		}
		else { // Ouput is empty, set to 0
			output = "0";
		}
		std::cout << output << std::endl; //Send output to cout 
	}

	//Check for empty list
	bool emptyPoly() {
		return T.empty();
	}

	//Clean up a linked list
	void removeAll()
	{
		T.clear();
	}

};

#endif
