// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-01-18

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>   
#include <cstring>

#include "Event.h"

unsigned int g_sysClock = 0;

namespace sdds {

	void Event::setEmpty() {
		m_description = nullptr;
		m_eventStart = 0;
	}

	Event::Event() {
		setEmpty();
	}

	void Event::display() const {

		static int counter = 0;
		counter++;	// function call tracker

		std::cout << std::setw(2) << std::setfill(' ') << counter << ". ";

		if (m_description != nullptr) {
			int hrs, mins, sec;

			hrs = m_eventStart / 3600;
			mins = (m_eventStart % 3600) / 60;
			sec = m_eventStart % 60;

			std::cout << std::setw(2) << std::setfill('0') << hrs << ":";
			std::cout << std::setw(2) << std::setfill('0') << mins << ":";
			std::cout << std::setw(2) << std::setfill('0') << sec;

			std::cout << " => ";

			std::cout << m_description << std::endl;

		}
		else {
			std::cout << "| No Event |" << std::endl;
		}

	}

	void Event::set(const char* desc) {

		// Same code on both cases
		delete[] m_description;
		m_description = nullptr;

		if (desc != nullptr && desc[0] != '\0') {

			m_eventStart = g_sysClock;

			m_description = new char[strlen(desc) + 1];
			strcpy(m_description, desc);
		}
		
	}

	Event::Event(const Event& event) {

		m_description = nullptr;
		// call: copy assignment operator
		*this = event;

	}

	Event& Event::operator=(const Event& src) {
		if (this != &src && src.m_description != nullptr) {

			// clean up
			delete[] m_description;
			
			// allocate memory
			int length = strlen(src.m_description);
			m_description = new char[length + 1];

			// copy
			for (auto i = 0; i < length; i++)
				m_description[i] = src.m_description[i];
			m_description[length] = '\0';  // null byte

			m_eventStart = src.m_eventStart;
		}

		return *this;
	}

	Event::~Event() {
		delete[] m_description;
		m_description = nullptr;
	}

}