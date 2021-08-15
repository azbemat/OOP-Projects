// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RACECAR_H__
#define SDDS_RACECAR_H__

#include <iostream>
#include <sstream>

#include "Car.h"

namespace sdds {

	class Racecar : public Car {

		double m_booster = 0;

	public:

		Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;

	};
}
#endif // !SDDS_RACECAR_H__
