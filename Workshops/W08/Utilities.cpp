// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-28

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {
					Product* p{ new Product(desc[i].desc, price[j].price) };

					try {
						p->validate();
					}
					catch (const std::string & mes) {
						Product::Trace = false;
						delete p;
						Product::Trace = true;

						throw;
					}

					priceList += p;
					delete p;
				}

			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {

					std::unique_ptr<Product> prod(new Product(desc[i].desc, price[j].price));

					prod->validate();

					priceList += prod;
				}

			}
		}

		return priceList;
	}
}