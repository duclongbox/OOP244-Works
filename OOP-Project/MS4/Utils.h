/*/////////////////////////////////////////////////////////////////////////
						  MS4
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 27/7/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef UTILS_H
#define UTILS_H
#include <iostream>
using namespace std;
namespace sdds {
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src);
	// returns the lenght of the C-string in characters
	int strLen(const char* s);
	void strnCpy(char* des, const char* src, int len);
}


#endif // !UTILS_H
