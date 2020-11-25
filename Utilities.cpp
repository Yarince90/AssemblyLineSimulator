#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP345 Final Project
Module: Utilities
Filename: Utilities.cpp
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
#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = ',';

Utilities::Utilities() {}
void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth()const {
	return m_widthField;
}

string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
	string extractedToken;
	size_t pos;
	
	extractedToken = "";
	pos = str.find_first_of(m_delimiter, next_pos);

	if (pos != string::npos) {
		extractedToken = str.substr(next_pos, pos - next_pos);
		next_pos = pos + 1;
		more = true;
	}
	else {
		extractedToken = str.substr(next_pos);
		next_pos = str.length() + 1;
	}
	if (m_widthField < extractedToken.length()) {
		m_widthField = extractedToken.length();
	}
	if (extractedToken.empty() && next_pos != str.length() + 1) {
		more = false;
		throw "Error: There are two delimiters with no token between them.";
	}
	if (str.length() >= next_pos) {
		more = true;
	}
	else {
		more = false;
	}

	return extractedToken;
}
void Utilities::setDelimiter(char newDelimeter) {
	m_delimiter = newDelimeter;
}
char Utilities::getDelimiter() {
	return m_delimiter;
}
Utilities::~Utilities() {}
