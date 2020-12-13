#define _CRT_SECURE_NO_WARNINGS
// Name: Yarince Vigil
// Seneca Student ID: yvigilteves
// Seneca email: yvigilteves@myseneca.ca
// Date of completion: 11/25/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include "Station.h"
#include "Utilities.h"
#include "Workstation.h"
using namespace std;

Workstation::Workstation() : Station() {
	m_pNextStation = nullptr;
}
Workstation::Workstation(const string& str) : Station(str) {
	m_pNextStation = nullptr;
}
void Workstation::runProcess(ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}
bool Workstation::moveOrder() {
	bool moved;

	moved = !m_orders.empty() && m_orders.front().isItemFilled(getItemName())
		&& !m_orders.front().isOrderFilled() && m_pNextStation;

	if (moved) {
		*m_pNextStation += move(m_orders.front());
		m_orders.pop_front();
	}

	return moved;
}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = static_cast<Workstation*>(&station);
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool completed;
	
	completed = !m_orders.empty() && m_orders.front().isOrderFilled();

	if (completed) {
		order = move(m_orders.front());
		m_orders.pop_front();
	}

	return completed;
}

void Workstation::display(ostream& os) {
	string next = getNextStation() ? getNextStation()->getItemName() : "END OF LINE";
	os << getItemName() << " --> " << next << endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& order) {
	m_orders.push_back(move(order));
	return *this;
}