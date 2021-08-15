// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__

namespace sdds {

	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
		static unsigned m_replaceCount[6];
	};
}
#endif // !SDDS_SPELLCHECKER_H__
