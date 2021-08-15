// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__

namespace sdds {

	class Movie {
		std::string m_title;
		int m_year = 0;
		std::string m_description;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		friend std::ostream& operator<<(std::ostream&, const Movie&);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}
#endif // !SDDS_MOVIE_H__
