// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "SpellChecker.h"

namespace sdds {

	unsigned SpellChecker::m_replaceCount[] = { 0 };

	SpellChecker::SpellChecker(const char* filename) {

		std::ifstream fileName(filename);
		std::string str;
		size_t check = 0;

		if (!fileName)
			throw "Bad file name!";

		do {
			std::getline(fileName, str);
			if (fileName) {

				std::istringstream temp(str);
				std::string words;
				temp >> words;

				m_badWords[check] = words;
				temp >> words;
				m_goodWords[check] = words;

				check++;
			}
		} while (fileName);

		fileName.close();
	}

	void SpellChecker::operator()(std::string& text) {

		size_t count = 0;
		for (size_t i = 0; i < 6; i++) {

			while ((count = text.find(m_badWords[i])) != std::string::npos) {
				text.replace(count, m_badWords[i].length(), m_goodWords[i]);
				m_replaceCount[i]++;
			}			
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {

		out << "Spellchecker Statistics" << std::endl;
		
		for (size_t i = 0; i < 6; i++) {
			out << std::right << std::setw(15);
			out << m_badWords[i];

			out << ": ";

			out << m_replaceCount[i];

			out << " replacements" << std::endl;
		}
			
	}

}