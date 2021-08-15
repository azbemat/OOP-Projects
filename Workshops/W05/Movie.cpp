// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <iomanip>

#include "Movie.h"

namespace sdds {

	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_description = "";
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {

		int beginIndex = 0;
		int endIndex = 0;

		const std::string WHITESPACE = " \n\r\t\f\v";

		endIndex = strMovie.find(",", beginIndex);
		m_title = strMovie.substr(beginIndex, endIndex);
		size_t start = m_title.find_first_not_of(WHITESPACE);
		m_title = (start == std::string::npos) ? "" : m_title.substr(start);
		size_t end = m_title.find_last_not_of(WHITESPACE);
		m_title = (end == std::string::npos) ? "" : m_title.substr(0, end + 1);

		beginIndex = endIndex;
		endIndex = strMovie.find(",", endIndex + 1);
		m_year = std::stoi(strMovie.substr(beginIndex + 1, endIndex - beginIndex - 1));

		beginIndex = endIndex;
		endIndex = strMovie.find(",", endIndex + 1);
		m_description = strMovie.substr(beginIndex + 1);
		start = m_description.find_first_not_of(WHITESPACE);
		m_description = (start == std::string::npos) ? "" : m_description.substr(start);
		end = m_description.find_last_not_of(WHITESPACE);
		m_description = (end == std::string::npos) ? "" : m_description.substr(0, end + 1);

	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {

		os << std::right << std::setw(40);
		os << movie.m_title;
		os << " | ";

		os << std::right << std::setw(4);
		os << movie.m_year;
		os << " | ";

		os << std::left;
		os << movie.m_description;
		os << std::endl;

		return os;
	}
}