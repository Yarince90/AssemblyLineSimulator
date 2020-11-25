#pragma once
/* Citation and Sources...
OOP345 Final Project
Module: Station
Filename: Station.h
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/11/17
Preliminary release: 11/17/2020
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <string>

typedef unsigned int uInt;

class Station {
	uInt m_id;
	std::string m_name;
	std::string m_desc;
	uInt m_serialNum;
	uInt m_items;

	static uInt m_widthField;
	static uInt id_generator;

public:
	Station();
	Station(const std::string str);
	const std::string& getItemName() const;
	uInt getNextSerialNumber();
	uInt getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
	void setEmpty();
	~Station();
};
