// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>

#include "Book.h"

namespace sdds {

	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0.0;
		m_description = "";
	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}

	Book::Book(const std::string& strBook) {

		int beginIndex = 0;
		int endIndex = 0;

		const std::string WHITESPACE = " \n\r\t\f\v";

		endIndex = strBook.find(",", beginIndex);
		m_author = strBook.substr(beginIndex, endIndex);

		size_t start = m_author.find_first_not_of(WHITESPACE);
		m_author = (start == std::string::npos) ? "" : m_author.substr(start);
		size_t end = m_author.find_last_not_of(WHITESPACE);
		m_author = (end == std::string::npos) ? "" : m_author.substr(0, end + 1);

		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		m_title = strBook.substr(beginIndex + 1, endIndex - beginIndex - 1);
		start = m_title.find_first_not_of(WHITESPACE);
		m_title = (start == std::string::npos) ? "" : m_title.substr(start);
		end = m_title.find_last_not_of(WHITESPACE);
		m_title = (end == std::string::npos) ? "" : m_title.substr(0, end + 1);

		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		m_country = strBook.substr(beginIndex + 1, endIndex - beginIndex - 1);
		start = m_country.find_first_not_of(WHITESPACE);
		m_country = (start == std::string::npos) ? "" : m_country.substr(start);
		end = m_country.find_last_not_of(WHITESPACE);
		m_country = (end == std::string::npos) ? "" : m_country.substr(0, end + 1);

		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		m_price = std::stod(strBook.substr(beginIndex + 1, endIndex - beginIndex - 1));

		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		m_year = std::stoi(strBook.substr(beginIndex + 1, endIndex - beginIndex - 1));

		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		m_description = strBook.substr(beginIndex + 1);

		start = m_description.find_first_not_of(WHITESPACE);
		m_description = (start == std::string::npos) ? "" : m_description.substr(start);
		end = m_description.find_last_not_of(WHITESPACE);
		m_description = (end == std::string::npos) ? "" : m_description.substr(0, end + 1);

	}

	void Book::setPrice(double price) {
		m_price = price;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {

		os << std::right << std::setw(20);
		os << book.m_author;
		os << " | ";

		os << std::right << std::setw(22);
		os << book.m_title;
		os << " | ";

		os << std::right << std::setw(5);
		os << book.m_country;
		os << " | ";

		os << std::right << std::setw(4);
		os << book.m_year;
		os << " | ";

		os.width(6);
		os << std::fixed;
		os << std::setprecision(2);
		os << std::right;
		os << book.m_price;
		os << " | ";

		os << std::left;
		os << book.m_description;
		os << std::endl;

		return os;

	}

}