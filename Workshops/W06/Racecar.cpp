// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <sstream>
#include <string>

#include "Racecar.h"

namespace sdds {

	Racecar::Racecar() {
		m_booster = 0;
	}

	Racecar::Racecar(std::istream& in) : Car(in){
		std::string tempBooster;
		std::getline(in, tempBooster);
		m_booster = std::stod(tempBooster);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}