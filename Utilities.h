#pragma once
/* Citation and Sources...
OOP345 Final Project
Module: Utilities
Filename: Utilities.h
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 11/17/2020
Preliminary release: 11/17/2020
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <string>

class Utilities {
	size_t m_widthField{ 1 };
	static char m_delimiter;
public:
	Utilities();
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
	~Utilities();
};
