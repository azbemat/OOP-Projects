// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include <string>

namespace sdds {

	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year = 0;
		double m_price;
		std::string m_description;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		void setPrice(double);

		friend std::ostream& operator<<(std::ostream&, const Book&);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}
	};
}
#endif // !SDDS_BOOK_H__
