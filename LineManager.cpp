#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP345 Final Project
Module: LineManager
Filename: LineManager.cpp
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 11/25/2020
Preliminary release: 11/25/2020
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include "Utilities.h"
#include "CustomerOrder.h"
#include "Station.h"
#include "Workstation.h"
#include "LineManager.h"
using namespace std;

LineManager::LineManager(const string& fileName, vector<Workstation*>& stations, vector<CustomerOrder>& orders) {
	try {
		ifstream file(fileName);

		if (file.is_open()) {
			Utilities utils;
			string record;
			string CurrentStation;
			string NextStation;
			size_t pos;
			size_t i;
			size_t x;
			bool more;

			do {
				pos = 0;
				getline(file, record);

				CurrentStation = utils.extractToken(record, pos, more);

				more ? NextStation = utils.extractToken(record, pos, more) : NextStation = "";

				for (i = 0; i < stations.size(); i++) {
					if (stations[i]->getItemName() == CurrentStation) {
						for (x = 0; x < stations.size(); x++) {
							if (stations[x]->getItemName() == NextStation) {
								stations[i]->setNextStation(*stations[x]);
								break;
							}
						}
						m_Station.push_back(stations[i]);
					}
				}
			} while (!file.eof());

			file.close();

			for (i = 0; i < orders.size(); i++) {
				ToBeFilled.push_back(move(orders[i]));
			}

			m_cntCustomerOrder = ToBeFilled.size();
			AssemblyLine = stations;
		}
		else {
			throw ("ERROR:  Failed to open the file [") + fileName + "].";
		}
	}
	catch (...) {
		throw ("ERROR:  Failed to open the file [") + fileName + "].";
	}
}

bool LineManager::run(ostream& os) {

	static size_t count = 1;

	if (!ToBeFilled.empty()) {
		*(m_Station[0]) += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	os << "Line Manager Iteration: " << count << endl;

	for (auto i : AssemblyLine) {
		i->runProcess(os);
	}

	for (auto i : m_Station) {
		i->moveOrder();
	}

	CustomerOrder temp;
	for (auto i : AssemblyLine) {
		if (i->getIfCompleted(temp)) {
			Completed.push_back(move(temp));
		}
	}
	count++;

	return Completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(ostream& os) const {
	for (auto order = Completed.begin(); order != Completed.end(); order++) {
		(*order).display(os);
	}
}

void LineManager::displayStations() {
	for (auto station : AssemblyLine) {
		station->display(cout);
	}
}

void LineManager::displayStationsSorted() const {
	for (auto station : m_Station) {
		station->display(cout);
	}
}