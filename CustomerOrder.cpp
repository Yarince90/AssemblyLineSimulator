#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP345 Final Project
Module: CustomerOrder
Filename: CustomerOrder.cpp
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 11/22/2020
Preliminary release: 11/22/2020
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <vector>
#include "Utilities.h"
#include "Station.h"
#include "CustomerOrder.h"
using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	setEmpty();
}
CustomerOrder::CustomerOrder(string& str) {
	try {
		Utilities utils;
		vector<string>tokenList;
		bool more;
		size_t pos;
		size_t i;
		more = false;
		pos = 0;

		m_name = utils.extractToken(str, pos, more);
		m_product = utils.extractToken(str, pos, more);

		if (more) {

			do {
				tokenList.push_back(utils.extractToken(str, pos, more));
			} while (more);

			m_cntItem = tokenList.size();
			m_lstItem = new Item * [m_cntItem];

			for (i = 0; i < m_cntItem; i++) {
				m_lstItem[i] = new Item(tokenList[i]);
			}

			if (m_widthField < utils.getFieldWidth()) {
				m_widthField = utils.getFieldWidth();
			}
		}
	}
	catch (...) {
		throw "Error getting customer order";
	}
}
CustomerOrder::CustomerOrder(CustomerOrder& order) {
	throw "Copy operations are not allowed!";
}
CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
	*this = move(order);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
	if (this != &order) {
		size_t i;

		if (m_lstItem) {
			for (i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;
		}

		m_name = order.m_name;
		m_product = order.m_product;
		m_cntItem = order.m_cntItem;
		m_lstItem = order.m_lstItem;
		order.m_cntItem = 0;
		order.m_lstItem = nullptr;
	}
	return *this;
}
void CustomerOrder::setEmpty() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;

	if (m_lstItem) {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
		delete[] m_lstItem;
	}

	m_lstItem = nullptr;
}
bool CustomerOrder::isOrderFilled() const {
	size_t i;
	bool filled;

	filled = true;

	for (i = 0; i < m_cntItem; i++) {
		filled = filled && m_lstItem[i]->m_isFilled;
	}

	return filled;
}
bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	size_t i;
	bool filled;

	filled = true;

	for (i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
			filled = false;
		}
	}

	return filled;
}
void CustomerOrder::fillItem(Station& station, ostream& os) {
	size_t i;
	uInt itemNumb;

	for (i = 0; i < m_cntItem; i++) {

		if (m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0) {

			itemNumb = station.getQuantity();

			if (itemNumb > 1) {
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();
				os << "    Filled ";
			}
			else {
				os << "    Unable to fill ";
			}
			os << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
		}
	}
}
void CustomerOrder::display(ostream& os) const {
	string orderStatus;
	size_t i;

	os << m_name << " - " << m_product << endl;

	for (i = 0; i < m_cntItem; i++) {

		m_lstItem[i]->m_isFilled ? orderStatus = "FILLED" : orderStatus = "MISSING";

		os << "[" << right << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << "] "
			<< left << setfill(' ') << setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << orderStatus << endl;
	}
}
CustomerOrder::~CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;

	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}

	delete[] m_lstItem;
	m_lstItem = nullptr;
}