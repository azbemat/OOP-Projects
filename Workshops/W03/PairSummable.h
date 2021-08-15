// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__

#include <iostream>
#include <iomanip>

#include "Pair.h"

namespace sdds {

	template<typename V, typename K>
	class PairSummable : public Pair<V, K>{

		static V initial;
		static size_t m_fieldWidth;

	public:

		PairSummable() {};

		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value){
			if (key.size() > m_fieldWidth)
				m_fieldWidth = key.size();
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return (b.key() == this->key()) ? true : false;
		}

		PairSummable& operator+=(const PairSummable& add) {
			PairSummable& result = *this;

			if (this != &add && this->key() == add.key()) {
				V added = this->value() + add.value();
				this->setValue(added);
				result = *this;
			}

			return result;
		}

		void display(std::ostream& os) const {

			os << std::left;
			os << std::setw(m_fieldWidth);
			Pair<V, K>::display(os);
			os << std::right;
		}
	};

	template <typename V, typename K>
	size_t PairSummable<V, K>::m_fieldWidth = 0;

	template <typename V, typename K>
	V PairSummable<V, K>::initial = {};

	template<>
	std::string sdds::PairSummable<std::string, std::string>::initial = "";

	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& add) {

		PairSummable& result = *this;

		if (this != &add && this->key() == add.key()) {

			std::string _value;
			_value = ((this->value() == "") ? add.value() : this->value() + ", " + add.value());
			setValue(_value);

			result = *this;
		}

		return result;
	}
}

#endif // SDDS_PAIRSUMMABLE_H__
