// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTOSHOP_H__
#define SDDS_AUTOSHOP_H__

#include <vector>
#include <list>

#include "Vehicle.h"

namespace sdds {

	class Autoshop {

		std::vector<Vehicle*> m_vehicles{};

	public:
		Autoshop();
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	};

	template<typename T>
	void Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			if (test(*i) == true)
				vehicles.push_back(*i);
		}
	}
}
#endif // !SDDS_AUTOSHOP_H__
