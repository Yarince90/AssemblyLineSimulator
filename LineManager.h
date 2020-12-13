#pragma once
/* Citation and Sources...
OOP345 Final Project
Module: LineManager
Filename: LineManager.h
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
#include <vector>
#include <deque>
#include <string>
#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager {
	std::vector<Workstation*> AssemblyLine{};
	std::deque<CustomerOrder> ToBeFilled{};
	std::deque<CustomerOrder> Completed{};
	unsigned int m_cntCustomerOrder{ 0 };
	std::vector<Workstation*> m_Station{};
public:
	LineManager(const std::string& fileName, std::vector<Workstation*>& stations, std::vector<CustomerOrder>& orders);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations();
	void displayStationsSorted() const;

};