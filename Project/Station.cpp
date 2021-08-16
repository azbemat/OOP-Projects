// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-03-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Station.h"
#include "Utilities.h"

namespace sdds {

	// Class Variables
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	// Functions
	Station::Station(const std::string& str) {
		m_id = ++id_generator;
		Utilities utility;
		size_t next_pos = 0;
		bool more = false;

		if (str.empty()) {
			m_name = "";
			m_serialNumber = 0;
			m_noOfItems = 0;
		}
		else {
			m_name = utility.extractToken(str, next_pos, more);

			if (more) {
				std::string temp = utility.extractToken(str, next_pos, more);
				m_serialNumber = atoi(temp.c_str());
			}

			if (more) {
				std::string temp = utility.extractToken(str, next_pos, more);
				m_noOfItems = atoi(temp.c_str());
			}

			if (m_widthField < utility.getFieldWidth()) {
				m_widthField = utility.getFieldWidth();
			}

			if (more) {
				m_description = utility.extractToken(str, next_pos, more);
			}

		}
	}

	const std::string& Station::getItemName() const {
		return m_name;
	}

	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const {
		return m_noOfItems;
	}

	void Station::updateQuantity() {
		if (m_noOfItems > 0)
			m_noOfItems--;
	}

	void Station::display(std::ostream& os, bool full) const {

		if (full) {
			std::ios init(NULL);
			init.copyfmt(std::cout);

			os << std::right << "[" << std::setw(3) << std::setfill('0');
			os << m_id;
			os << "]" << std::left;

			os << " Item: ";
			os << std::setw(m_widthField) << std::setfill(' ');
			os << m_name;

			os << std::right;
			os << " [" << std::setw(6) << std::setfill('0');
			os << m_serialNumber;
			os << "]" << std::left;

			os << " Quantity: ";
			os << std::setw(m_widthField) << std::setfill(' ');
			os << m_noOfItems;

			os << " Description: ";
			os.copyfmt(init);
			os << m_description;

			os << std::endl;
		}
		else {
			std::ios init(NULL);
			init.copyfmt(std::cout);

			os << std::right << "[" << std::setw(3) << std::setfill('0');
			os << m_id;
			os << "]" << std::left;

			os << " Item: ";
			os << std::setw(m_widthField) << std::setfill(' ');
			os << m_name;

			os << std::right << " [" << std::setw(6) << std::setfill('0');
			os << m_serialNumber;
			os << "]" << std::left;

			os << std::endl;
		}

	}

}