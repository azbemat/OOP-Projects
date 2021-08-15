// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-01-30

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <chrono>
#include <iomanip>

#include "TimedEvents.h"

namespace sdds {

	TimedEvents::TimedEvents() {
		m_noOfRecords = 0;
	}

	void TimedEvents::startClock(){
		m_startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name){
		m_events[m_noOfRecords].eventName = name;
		m_events[m_noOfRecords].unitsOfTime = "nanoseconds";
		m_events[m_noOfRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_noOfRecords++;
	}

	std::ostream& operator<<(std::ostream& os, TimedEvents te) {

		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;

		for (int i = 0; i < te.m_noOfRecords; i++) {

			os << std::left << std::setw(21);
			os << te.m_events[i].eventName;

			os << " ";

			os << std::right << std::setw(13);
			os << te.m_events[i].duration.count();

			os << " ";

			os << te.m_events[i].unitsOfTime << std::endl;
		}

		os << "--------------------------" << std::endl;
		return os;
	}

}