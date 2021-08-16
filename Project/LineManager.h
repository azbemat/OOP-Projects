// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H__
#define SDDS_LINEMANAGER_H__

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <deque>

namespace sdds {

	class Workstation;
	class LineManager {

		std::vector<Workstation*> activeLine{};
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation{ nullptr };

	public:

		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;

	};
}
#endif // !SDDS_LINEMANAGER_H__
