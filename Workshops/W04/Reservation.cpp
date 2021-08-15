// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-14

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <iomanip>

#include "Reservation.h"

namespace sdds {

	Reservation::Reservation() {
		m_reservationId = {};
		m_name = {};
		m_email = {};
		m_noOfPeople = {};
		m_day = {};
		m_hour = {};
	}

	Reservation::Reservation(const std::string& res) {

		int startIndex = 0;
		int endIndex = 0;

		endIndex = res.find(":", startIndex);
		m_reservationId = trim(res.substr(startIndex, endIndex));

		startIndex = endIndex;
		endIndex = res.find(",", endIndex);
		m_name = trim(res.substr(startIndex + 1, endIndex - startIndex - 1));

		startIndex = endIndex;
		endIndex = res.find(",", endIndex + 1);
		m_email = trim(res.substr(startIndex + 1, endIndex - startIndex - 1));

		startIndex = endIndex;
		endIndex = res.find(",", endIndex + 1);
		m_noOfPeople = std::stoi(res.substr(startIndex + 1, endIndex - startIndex - 1));

		startIndex = endIndex;
		endIndex = res.find(",", endIndex + 1);
		m_day = std::stoi(res.substr(startIndex + 1, endIndex - startIndex - 1));

		startIndex = endIndex;
		m_hour = std::stoi(res.substr(startIndex + 1));

	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res) {

		os << "Reservation ";
		os << std::right << std::setw(10);
		os << res.m_reservationId << ": ";

		os << std::right << std::setw(20);
		os << res.m_name << "  ";

		os << std::left << std::setw(20);
		os << "<" + res.m_email + ">";

		if (res.m_hour >= 6 && res.m_hour <= 9) 
			os << "    Breakfast on day ";
		else if (res.m_hour >= 11 && res.m_hour <= 15)
			os << "    Lunch on day ";
		else if (res.m_hour >= 17 && res.m_hour <= 21)
			os << "    Dinner on day ";
		else 
			os << "    Drinks on day ";
		
		os << res.m_day << " @ " << res.m_hour << ":00 for ";

		os << res.m_noOfPeople;
		if (res.m_noOfPeople == 1)
			os << " person.";
		else
			os << " people.";
		os << std::endl;
		os << std::left;

		return os;
	}

	std::string Reservation::trim(const std::string& s) {
		auto begin = s.begin();
		while (begin != s.end() && std::isspace(*begin))
			begin++;
		auto end = s.end();
		do {
			end--;
		} while (std::distance(begin, end) > 0 && std::isspace(*end));

		return std::string(begin, end + 1);
	}
}