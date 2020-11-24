#pragma once
/*
Name: Yarince Vigil
Email: yvigilteves@myseneca.ca
Student ID: yvigilteves
Student Number: 016261125
Date Completed: 11/17/2020

I have done all the coding by myself
and only copied the code that my professor
provided to complete my workshops and assignments.
*/
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