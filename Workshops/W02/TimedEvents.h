// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-01-30

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {

	const int MAX_EVENTS = 10;

	class TimedEvents {

		int m_noOfRecords{ 0 };
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;

		struct Event {
			std::string eventName{};
			std::string unitsOfTime{};
			std::chrono::steady_clock::duration duration;
		} m_events[MAX_EVENTS];

	public:

		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, TimedEvents);
	};



}
#endif // !SDDS_TIMEDEVENTS_H__
