// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include<iostream>
#include <string>

#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {

		std::string m_maker{};
		std::string m_condition{};
		double m_speed = 0;

	public:

		Car();
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		~Car();

	};
}
#endif // !SDDS_CAR_H__
