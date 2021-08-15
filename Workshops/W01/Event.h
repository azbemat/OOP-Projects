// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-01-18

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__

#include <iostream>

extern unsigned int g_sysClock;

namespace sdds {

	class Event {
		char* m_description;
		unsigned int m_eventStart;

	public:
		Event();
		~Event();
		void display() const;
		void set(const char* desc = nullptr);

		void setEmpty();
		Event(const Event& event);
		Event& operator=(const Event& event);

	};

}

#endif // !SDDS_EVENT_H__

