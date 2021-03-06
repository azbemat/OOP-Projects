// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-02-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__

#include <iostream>
#include <string>

namespace sdds {

	template<class T>
	class Collection {
		std::string m_name = "";
		T* m_pItems = nullptr;
		size_t m_size = 0;
		void(*m_pFunction)(const Collection<T>&, const T&) = nullptr;

	public:

		Collection() {
			m_pItems = nullptr;
			m_pFunction = nullptr;
		}

		Collection(const std::string& name) {
			m_name = name;
			m_pFunction = nullptr;
			m_size = 0;
			m_pItems = nullptr;
		}

		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_pFunction = observer;
		}

		Collection<T>& operator+=(const T& item) {

			bool isTitleSame = false;

			for (size_t i = 0; i < m_size; i++)
				if (m_pItems[i].title() == item.title())
					isTitleSame = true;
			if (isTitleSame)
				return *this;

			T* temp = m_pItems; 

			m_pItems = new T[m_size + 1];  
			for (size_t i = 0; i < m_size; i++)  
				m_pItems[i] = temp[i];

			m_pItems[m_size++] = item;   

			if (m_pFunction != nullptr)
				m_pFunction(*this, item);

			delete[] temp;

			return *this;
		}

		T& operator[](size_t idx) const {

			if (idx >= m_size) {
				std::string msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(msg);
			}
			return m_pItems[idx];
		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++)
				if (m_pItems[i].title() == title)
					return  &m_pItems[i];
			return nullptr;
		}

		friend std::ostream& operator<< (std::ostream& os, const Collection& coll) {
			for (size_t i = 0; i < coll.size(); i++)
				os << coll[i];
			return os;
		};

		Collection(const Collection&) = delete;

		~Collection() {
			delete[] m_pItems;
			m_pItems = nullptr;
		}
	};
}
#endif // !SDDS_COLLECTION_H__
