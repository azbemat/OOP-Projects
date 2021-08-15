// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-14

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>

#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {

	Restaurant::Restaurant() {
		m_pReservations = nullptr;
		m_noOfReservations = 0;
	}

	Restaurant::~Restaurant() {
		delete[] m_pReservations;
		m_pReservations = nullptr;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {

		m_pReservations = new Reservation[cnt];

		for (size_t i = 0; i < cnt; i++) {
			m_pReservations[i] = *reservations[i];
			m_noOfReservations = cnt;
		}
	}

	size_t Restaurant::size() const {
		return m_noOfReservations;
	}

	Restaurant::Restaurant(const Restaurant& res) {
		*this = res;
	}

	Restaurant& Restaurant::operator=(const Restaurant& res) {
		if (this != &res) {
			if (m_pReservations != nullptr)
				delete[] m_pReservations;

			m_pReservations = new Reservation[res.size() + 1];

			for (size_t i = 0; i < res.size(); i++) 
				m_pReservations[i] = res.m_pReservations[i];
			m_noOfReservations = res.m_noOfReservations;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& res) {
		*this = std::move(res);
	}

	Restaurant& Restaurant::operator=(Restaurant&& res) {

		if (this != &res) {
			if (m_pReservations != nullptr)
				delete[] m_pReservations;

			m_noOfReservations = res.m_noOfReservations;
			m_pReservations = res.m_pReservations;

			res.m_pReservations = nullptr;
			res.m_noOfReservations = 0;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res) {

		static size_t count = 0;

		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << ++count << ")" <<std::endl;
		os << "--------------------------" << std::endl;
		
		if (res.size() <= 0) 
			os << "This restaurant is empty!" << std::endl;
		else
			for (size_t i = 0; i < res.size(); i++)
				os << res.m_pReservations[i];

		os << "--------------------------" << std::endl;

		return os;
	}
}