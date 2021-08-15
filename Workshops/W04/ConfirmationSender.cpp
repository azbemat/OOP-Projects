// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-14

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>

#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::ConfirmationSender() {
		m_ppReservation = nullptr;
		m_size = 0;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_ppReservation;
		m_ppReservation = nullptr;
	}

	size_t ConfirmationSender::size() const {
		return m_size;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {

		bool check = true;
		const Reservation** temp;

		if (m_ppReservation != nullptr) {

			// check if already exist
			for (size_t i = 0; i < size() && check; i++)
				if (&res == m_ppReservation[i])
					check = false;

			// resize the array to make room for res
			if (check) {
				temp = new const Reservation * [m_size + 1];
				for (size_t i = 0; i < size(); i++)
					temp[i] = m_ppReservation[i];

				delete[] m_ppReservation;

				temp[m_size++] = &res;
				m_ppReservation = temp;
			}
		}
		else {
			m_ppReservation = new const Reservation * [1];
			m_size = 1;
			m_ppReservation[0] = &res;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {

		for (size_t i = 0; i < size() && true; i++)
			if (&res == m_ppReservation[i])
				m_ppReservation[i] = nullptr;
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& res) {
		*this = res;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res) {

		if (this != &res) {
			m_ppReservation = new const Reservation * [res.size()];

			for (size_t i = 0; i < res.size(); i++)
				this->m_ppReservation[i] = res.m_ppReservation[i];
			this->m_size = res.m_size;
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& res) {
		*this = std::move(res);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res) {
		if (this != &res) {
			m_ppReservation = res.m_ppReservation;
			m_size = res.m_size;

			res.m_ppReservation = nullptr;
			res.m_size = 0;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res) {

		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (res.m_ppReservation == nullptr)
			os << "There are no confirmations to send!" << std::endl;
		else
			for (size_t i = 0; i < res.size(); i++)
				if (res.m_ppReservation[i] != nullptr)
					os << *res.m_ppReservation[i];

		os << "--------------------------" << std::endl;

		return os;
	}
}