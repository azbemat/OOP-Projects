// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <deque>

#include "Workstation.h"

namespace sdds {

	std::deque<CustomerOrder> pending = {};
	std::deque<CustomerOrder> completed = {};
	std::deque<CustomerOrder> incomplete = {};

	Workstation::Workstation(const std::string& str) : Station(str) {
		//m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os) {
		if (m_orders.size() > 0)
			m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder() {
		bool result = false;

		if (m_orders.empty())
			result = false;
		else {
			CustomerOrder& order = m_orders.front();
			if (order.isItemFilled(getItemName()) || this->getQuantity() == 0) {

				if (m_pNextStation) {
					*m_pNextStation += std::move(order);
				}
				else if (order.isFilled()) {
					completed.push_back(std::move(order));
				}
				else {
					incomplete.push_back(std::move(order));
				}
				m_orders.pop_front();
				result = true;
			}
			else {
				result = false;
			}
		}

		return result;
	}

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> " << ((m_pNextStation) ? m_pNextStation->getItemName() : "End of Line") << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

}

