#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP345 Final Project
Module: Station
Filename: Station.cpp
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/11/17
Preliminary release: 2020/11/17
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"
using namespace std;

uInt Station::m_widthField = 0;
uInt Station::id_generator = 1;

Station::Station() {
	setEmpty();
}
Station::Station(const string str) {
	Utilities utils;
	size_t pos;
	bool more;
	
	more = false;
	pos = 0;
	
	m_id = Station::id_generator++;
	m_name = utils.extractToken(str, pos, more);
	
	if (more) {
		m_serialNum = stoi(utils.extractToken(str, pos, more));
		m_items = stoi(utils.extractToken(str, pos, more));
	}
	if (m_widthField < utils.getFieldWidth()) {
		m_widthField = utils.getFieldWidth();
	}
	if (more) {
		m_desc = utils.extractToken(str, pos, more);
	}
}
void Station::setEmpty() {
	m_id = 0;
	m_name = "";
	m_desc = "";
	m_serialNum = 0;
	m_items = 0;
}
const string& Station::getItemName()const {
	return m_name;
}
uInt Station::getNextSerialNumber() {
	return m_serialNum++;
}
uInt Station::getQuantity()const {
	return m_items;
}
void Station::updateQuantity() {
	m_items > 0 ? m_items-- : m_items = 0;
}
void Station::display(ostream& os, bool full)const {
	os << "[" << right << setw(3) << setfill('0') << m_id
		<< "] Item: " << left << setw(Station::m_widthField) << setfill(' ') << m_name
		<< " [" << right << setw(6) << setfill('0') << m_serialNum << "]";

	if (full) {
		os << left << " Quantity: " << setw(Station::m_widthField) << setfill(' ') << m_items
			<< " Description: " << m_desc;
	}
	os << endl;
}
Station::~Station() {}
