// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-14

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__

#include "Reservation.h"

namespace sdds {

	class ConfirmationSender {
		const sdds::Reservation** m_ppReservation;
		size_t m_size;

	public:

		ConfirmationSender();
		~ConfirmationSender();
		size_t size() const;

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);

		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res);
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H__
