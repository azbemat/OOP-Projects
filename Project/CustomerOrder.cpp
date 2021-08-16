// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-04-01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include <vector>

#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {

	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string& str) {

		Utilities utility;
		size_t next_pos = 0;
		bool more = true;

		Item* item = nullptr;
		std::vector<Item*> itemList;

		m_name = utility.extractToken(str, next_pos, more);

		m_product = utility.extractToken(str, next_pos, more);

		do {
			item = new Item(utility.extractToken(str, next_pos, more));
			itemList.push_back(item);
			item = nullptr;
			m_cntItem++;
		} while (more);

		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < m_cntItem; i++)
			m_lstItem[i] = itemList[size_t(i)];

		//updates
		if (m_widthField < utility.getFieldWidth())
			m_widthField = utility.getFieldWidth();

	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++)
			delete m_lstItem[i];
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const CustomerOrder&) {
		std::string err = "----> ERROR: Cannot make copies";
		throw err;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
		*this = std::move(other);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
		if (this != &other) {

			//cleanup
			for (size_t i = 0; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[] m_lstItem;

			//copy
			this->m_name = other.m_name;
			this->m_product = other.m_product;
			this->m_cntItem = other.m_cntItem;
			this->m_lstItem = other.m_lstItem;

			//set
			other.m_name = "";
			other.m_product = {};
			other.m_cntItem = 0;
			other.m_lstItem = nullptr;
		}

		return *this;
	}

	bool CustomerOrder::isFilled() const {
		bool isFilled = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled)
				isFilled = false;
		}
		return isFilled;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool isItemFilled = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName)
				isItemFilled = m_lstItem[i]->m_isFilled;
		}
		return isItemFilled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {

			// inventory contains at least one item
			if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() >= 1) {

				//subtracts 1 
				station.updateQuantity();

				//updates 
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;

				//print
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			// inventory is empty
			else if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() == 0) {

				//print
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {

		os << m_name << " - " << m_product << std::endl;

		for (size_t i = 0; i < m_cntItem; i++) {

			os << std::right;
			os << "[" << std::setw(6) << std::setfill('0');
			os << m_lstItem[i]->m_serialNumber;
			os << "] ";

			os << std::left << std::setw(m_widthField) << std::setfill(' ');
			os << m_lstItem[i]->m_itemName;
			os << " - ";

			os << ((m_lstItem[i]->m_isFilled) ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}

}