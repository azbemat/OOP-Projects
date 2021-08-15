// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>

#include "Car.h"

namespace sdds {

	Car::Car() {
		m_maker = {};
		m_condition = {};
		m_speed = 0;
	}

	Car::Car(std::istream& is) {

		std::string tempCondition;
		std::string tempSpeed;

		std::getline(is, m_maker, ',');
		while (m_maker[0] == ' ') {
			m_maker.erase(std::find(m_maker.begin(), m_maker.end(), ' '));
		}
		while (m_maker[m_maker.size() - 1] == ' ') {
			m_maker.erase(m_maker.size() - 1);
		}

		std::getline(is, tempCondition, ',');
		while (tempCondition.size() > 0 && tempCondition[0] == ' ') {
			tempCondition.erase(std::find(tempCondition.begin(), tempCondition.end(), ' '));
		}
		while (tempCondition.size() > 0 && tempCondition[tempCondition.size() - 1] == ' ') {
			tempCondition.erase(tempCondition.size() - 1);
		}
		
		if (tempCondition == "" || tempCondition == "n") 
			m_condition = "new";
		else if (tempCondition == "u") 
			m_condition = "used";
		else if (tempCondition == "b") 
			m_condition = "broken";
		else 
			throw "Invalid record!";

		std::getline(is, tempSpeed, ',');
		m_speed = std::stod(tempSpeed);
		
	}

	std::string Car::condition() const {
		return m_condition;
	}

	double Car::topSpeed() const {
		return m_speed;
	}

	void Car::display(std::ostream& out) const {

		out << "| ";

		out << std::right << std::setw(10);
		out << m_maker;

		out << " | ";
		out << std::left << std::setw(6);
		out << condition();

		out << " | ";
		out << std::fixed << std::setw(6);
		out << std::setprecision(2);
		out << topSpeed();

		out << " |";
		
	}

	Car::~Car(){}
}