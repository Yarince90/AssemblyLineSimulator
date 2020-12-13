#pragma once
/* Citation and Sources...
OOP345 Final Project
Module: CustomerOrder
Filename: CustomerOrder.h
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
#include <string>
#include "Station.h"

struct Item;

class CustomerOrder {
	std::string m_name{ "" };
	std::string m_product{ "" };
	uInt m_cntItem{ 0 };
	Item** m_lstItem{ nullptr };
	static size_t m_widthField;
	void setEmpty();
public:
	CustomerOrder();
	CustomerOrder(std::string& str);
	CustomerOrder(CustomerOrder&);
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&& order) noexcept;
	CustomerOrder& operator=(CustomerOrder&& order) noexcept;
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
	~CustomerOrder();
};

struct Item {
	std::string m_itemName;
	uInt m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};