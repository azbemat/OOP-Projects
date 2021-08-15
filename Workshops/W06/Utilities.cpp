// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {

		std::string str;
		getline(in, str);

		// remove empty spaces
		while (str[0] == ' ') 
			str.erase(std::find(str.begin(), str.end(), ' '));
		
		if (str[0] == 'C' || str[0] == 'c') {
			str.erase(0, str.find(',') + 1);
			std::stringstream ss(str);
			Vehicle* car = new Car(ss);
			return car;
		}
		else if (str[0] == 'r' || str[0] == 'R') {
			str.erase(0, str.find(',') + 1);
			std::stringstream sss(str);
			Vehicle* car = new Racecar(sss);
			return car;
		}
		else if (str.length() > 0) {
			throw str[0];
		}
		else {
			return nullptr;
		}
	}

}