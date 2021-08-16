// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H__
#define SDDS_WORKSTATION_H__

#include <string>
#include <deque>

#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {

	extern std::deque<CustomerOrder> pending, completed, incomplete;

	class Workstation : public Station {

		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{ nullptr };

	public:

		Workstation(const std::string&);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

	};

}
#endif // !SDDS_WORKSTATION_H__
