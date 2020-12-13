#pragma once
/* Citation and Sources...
OOP345 Final Project
Module: Workstation
Filename: Workstation.h
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
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

class Workstation :public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

public:
	Workstation();
	Workstation(const std::string& str);

	Workstation(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator=(Workstation&) = delete;
	Workstation& operator=(Workstation&&) = delete;

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&);
	Workstation& operator+=(CustomerOrder&& order);

};
