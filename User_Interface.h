#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "Polynomial.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class User_Interface {
	public:
		void process_commands()
		{
			Polynomial P1, P2, result;
			string str1;
			string str2;
			char ch;
			ch = ' ';
			cout << "\n\n\n\t\tMAIN MENU";
			cout << "\n\n\tPress 1 to Enter Polynomial One ";
			cout << "\n\n\tPress 2 to Enter Polynomial Two ";
			cout << "\n\n\tPress 3 to Add the Polynomials ";
			cout << "\n\n\tPress 4 to exit";
			cout << "\n\n\Please enter the polynomial in a user-friendly fashion, such as 3X^3-X^2+1";

			//address when the use enter other inputs ignore continue to prompt for the right input
			do
			{
				cout << "\n\nPlease Select Your Option (1-4) ";
				cin >> ch;
				switch (ch)
				{
				case '1':
					cout << "\nPlease enter the first polynomial" << endl;
					cout << "\nFirst Polynomial is : ";
					cin >> str1;
					P1.ReadFromString(str1);
					cout << endl;
					break;
				case '2':
					cout << "\nPlease Enter the Second Polynomial" << endl;
					cout << "\nSecond Polynomial is : ";
					cin >> str2;
					P2.ReadFromString(str2);
					break;
					cout << endl;
				case '3':
					cout << "\nResult of the Polynomial is : ";
					result.Add(P1, P2);
					if (!result.emptyPoly()) {
						result.Output();
					}
					else {
						std::cout << "The result is 0." << std::endl;
					}
					P1.removeAll();
					P2.removeAll();
					result.removeAll();
					ch = ' ';
					cout << "\n\n\n\t\tMAIN MENU";
					cout << "\n\n\tPress 1 to Enter Polynomial One ";
					cout << "\n\n\tPress 2 to Enter Polynomial Two ";
					cout << "\n\n\tPress 3 to Add the Polynomials ";
					cout << "\n\n\tPress 4 to exit";
					break;

				case '4':
					exit(0);


				}
			} while (ch != 0);
	}
};

#endif
