// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-03-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__

#include <string>

namespace sdds {

	class Station {

		size_t m_id = 0;
		std::string m_name = "";
		std::string m_description = "";
		size_t m_serialNumber = 0;
		size_t m_noOfItems = 0;

		// Class Variables
		static size_t m_widthField;
		static size_t id_generator;

	public:

		// Functions
		Station(const std::string&);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};
}
#endif // !SDDS_STATION_H__
