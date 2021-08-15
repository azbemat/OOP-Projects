// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__

#include <iostream>

namespace sdds {

	template<typename V, typename K>
	class Pair {
		V m_value;
		K m_key;

	public:

		Pair() {}

		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		}

		const V& value() const {
			return m_value;
		}

		const K& key() const {
			return m_key;
		}

		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}

	protected:

		void setValue(V value) {
			m_value = value;
		}

	};

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

}
#endif // !SDDS_PAIR_H__
