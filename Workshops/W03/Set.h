// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H__
#define SDDS_SET_H__

namespace sdds {

	template<size_t N, typename T>
	class Set {
		T m_type[N]{};
		size_t m_noOfElements{ 0 };

	public:

		size_t size() const {
			return m_noOfElements;
		}

		const T& get(size_t idx) const {
			return m_type[idx];
		}

		void operator+=(const T& item) {
			if (N > m_noOfElements)
				m_type[m_noOfElements++] = item;
		}

	};
}
#endif // !SDDS_SET_H__
