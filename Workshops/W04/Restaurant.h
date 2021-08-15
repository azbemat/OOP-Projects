// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-14

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* m_pReservations{ 0 };
		size_t m_noOfReservations;

	public:
		Restaurant();
		~Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;

		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);

		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif // !SDDS_RESTAURANT_H__
