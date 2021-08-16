// Name: Anas Zakariyah Bemat
// Seneca Student ID: 165239187
// Seneca email: azbemat@myseneca.ca
// Date of completion: 2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>

#include "LineManager.h"
#include "Workstation.h"
#include "Utilities.h"
 
namespace sdds {

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {

		Utilities utility;
		std::string line = "";
		std::string current = "";
		std::string next = "";

		size_t next_pos = 0;
		bool more = true;

		std::ifstream filename(file);

		if (!filename.is_open())
			throw std::string("Error - Cannot open file: ") + file;

		std::for_each(stations.begin(), stations.end(), [](Workstation* s) { s->setNextStation(); });

		while (!filename.eof()) {
			next_pos = 0;

			std::getline(filename, line);
			current = utility.extractToken(line, next_pos, more);

			auto cs = std::find_if(stations.begin(), stations.end(), [current](const Workstation* s) {
				return s->getItemName() == current;
			});

			if (cs == stations.end())
				throw std::string("Error: Current station name not found: " + current + "\n");

			activeLine.push_back(*cs);

			if (more) {

				next = utility.extractToken(line, next_pos, more);

				auto ns = std::find_if(stations.begin(), stations.end(), [next](const Workstation* s) {
					return s->getItemName() == next;
					});

				if(ns == stations.end())
					throw std::string("Error: Next station name not found: " + next + "\n");

				if (ns == cs)
					throw std::string("Error: Next station: " + next + " is the current station: " + current + ".\n");

				(*cs)->setNextStation(*ns);

			}
		}
		filename.close();

		std::for_each(activeLine.begin(), activeLine.end(), [this](Workstation* test) {
			auto fnd = std::find_if(activeLine.begin(), activeLine.end(), [&test](Workstation* s) {
				return s->getNextStation() == test;
				});
			if (fnd == activeLine.end()) {
				if (m_firstStation)
					throw std::string("Error\n");
				m_firstStation = test;
			}
			});

		if (!m_firstStation) {
			throw std::string("Error: not found\n");
		}

		m_cntCustomerOrder = pending.size();
	}

	void LineManager::linkStations() {
		std::vector<Workstation*> workStation;
		
		auto i = m_firstStation;
		while (i) {
			workStation.push_back(i);
			i = i->getNextStation();
		}

		activeLine = workStation;
	}

	bool LineManager::run(std::ostream& os) {

		static unsigned int count = 0;

		os << "Line Manager Iteration: " << ++count << std::endl;

		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}

		// for each station on the line, executes one fill operation
		for (auto& al : activeLine) {
			al->fill(os);
		}

		// attempts to move a CustomerOrder down the line
		for (auto& al : activeLine) {
			al->attemptToMoveOrder();
		}

		// true if all customer orders have been filled
		return completed.size() + incomplete.size() == m_cntCustomerOrder;
	}

	void LineManager::display(std::ostream& os) const {
		for (const auto& al : activeLine)
			al->display(os);
	}

}