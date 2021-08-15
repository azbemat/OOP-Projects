// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-14

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

#include <string>

namespace sdds {

	class Reservation {
		std::string m_reservationId;
		std::string m_name;
		std::string m_email;
		int m_noOfPeople;
		int m_day;
		int m_hour;

	public:
		Reservation();
		Reservation(const std::string& res);

		std::string trim(const std::string& s);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);

	};
}
#endif // !SDDS_RESERVATION_H__
