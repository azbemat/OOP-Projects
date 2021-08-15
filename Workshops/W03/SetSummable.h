// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-07

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__

#include "Set.h"

namespace sdds {

	template<size_t N, typename T>
	class SetSummable : public Set<N, T>{

	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);

			for (size_t i = 0; i < this->size(); i++) {
				if (accumulator.isCompatibleWith(this->get(i)))
					accumulator += this->get(i);
			}

			return accumulator;
		}
	};
}

#endif // !SDDS_SETSUMMABLE_H__
