// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-01-30

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STRINGSET_H__
#define SDDS_STRINGSET_H__

#include <iostream>

namespace sdds {

	class StringSet {
		std::string* m_pstring;
		size_t m_noOfStrings{ 0 };

	public:
		StringSet();
		StringSet(const char* file);
		~StringSet();

		size_t size();
		std::string operator[](size_t);

		StringSet(const StringSet&);
		StringSet& operator=(const StringSet&);

		StringSet(StringSet&&);
		StringSet& operator=(StringSet&&);

	};

}
#endif // !SDDS_STRINGSET_H__
