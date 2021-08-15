// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <vector>

#include "Autoshop.h"
#include "Vehicle.h"

namespace sdds {

	Autoshop::Autoshop() {}

	Autoshop::~Autoshop() {
		for (size_t i = 0; i < m_vehicles.size(); i++)
			delete m_vehicles[i];
	}

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
		
	void Autoshop::display(std::ostream& out) const {

		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;

		// without iterator
		/*for (size_t i = 0; i < m_vehicles.size(); i++) {
			m_vehicles[i]->display(out);
			out << std::endl;
		}*/

		// with iterator
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
			out << std::endl;
		}

		out << "--------------------------------" << std::endl;
	}

}
