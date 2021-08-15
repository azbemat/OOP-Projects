// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-01-30

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <fstream>
#include <utility>

#include "StringSet.h"

namespace sdds {

	StringSet::StringSet() {
		m_pstring = nullptr;
		m_noOfStrings = 0;
	}

	StringSet::StringSet(const char* file) {

		m_pstring = nullptr;
		m_noOfStrings = 0;
		std::string temp;
		unsigned count = 0;

		std::ifstream fin(file);

		// Confirming a File Connection and count the number of strings
		if (!fin.is_open())
			std::cerr << "File is not open" << std::endl;
		else 
			while (getline(fin, temp, ' ')) m_noOfStrings++;
		fin.close();

		// allocates memory for that number of strings in the array
		m_pstring = new std::string[m_noOfStrings];

		// re-reads the file and loads the strings into the array
		std::ifstream in(file);
		if (in.is_open()) {
			while (getline(in, temp, ' '))
				m_pstring[count++] = temp;
		}
		in.close();
	}

	size_t StringSet::size() {
		return m_noOfStrings;
	}

	std::string StringSet::operator[](size_t index) {
		return (m_pstring != nullptr && index <= m_noOfStrings) ? std::string(m_pstring[index]) : "";
	}

	StringSet::StringSet(const StringSet& src) {
		m_pstring = nullptr;
		*this = src;
	}

	StringSet& StringSet::operator=(const StringSet& src) {
		if (this != &src) {

			m_noOfStrings = src.m_noOfStrings;

			// clean-up
			delete[] m_pstring;

			// allocate memory
			m_pstring = new std::string[m_noOfStrings];

			// copy
			for (size_t i = 0; i < m_noOfStrings; i++)
				m_pstring[i] = src.m_pstring[i];

			/*copy(src.m_pstring, src.m_pstring + m_noOfStrings, m_pstring);*/

		}
		return *this;
	}

	StringSet::StringSet(StringSet&& src) {
		m_pstring = nullptr;
		*this = std::move(src);
	}

	StringSet& StringSet::operator=(StringSet&& src) {
		
		if (this != &src) {

			//deallocate current
			delete[] m_pstring;

			// copy from source
			m_pstring = src.m_pstring;
			m_noOfStrings = src.m_noOfStrings;

			// initialize source
			src.m_pstring = nullptr;
			src.m_noOfStrings = 0;

		}
		return *this;
	}

	StringSet::~StringSet() {
		delete[] m_pstring;
		m_pstring = nullptr;
	}

}