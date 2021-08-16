// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-03-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return size_t(m_widthField);
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

		std::string line;

		if (next_pos <= str.length()) {

			size_t token = str.find_first_of(m_delimiter, next_pos);

			if (token != std::string::npos) {

				line = str.substr(next_pos, token - next_pos);
				next_pos = token + 1;
				
			}
			else {
				line = str.substr(next_pos);
				next_pos = str.length() + 1;
			}

			if ((line.empty()) && (next_pos != str.length() + 1)) {
				more = false;
				throw str + "No Delimiter";
			}

			if (m_widthField < line.length())
				m_widthField = line.length();

			more = next_pos <= str.length();
		}

		return line;
	}

	// Class Members
	char Utilities::m_delimiter;

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

}


	