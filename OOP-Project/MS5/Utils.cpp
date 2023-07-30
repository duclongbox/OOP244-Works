/*/////////////////////////////////////////////////////////////////////////
						  Milestone-4
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 7/25/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include "Utils.h"

namespace sdds {
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';


	}
	int strLen(const char* s) {
		int i,count=0;
		for (i = 0; s[i] != '\0'; i++) {
			count++;
		}
		return count;
	}
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;

		if (strLen(src) >= len) {
			while (i < len) {
				des[i] = src[i];
				i++;
			}
		}
		else
		{
			while (i < strLen(src)) {
				des[i] = src[i];
				i++;
			}
		}
		// Set the last index to be NULL value
		des[i] = '\0';
	}
	unsigned int  read(int number) {
		unsigned int selection = 0;
		bool result = true;
		while (result) {
			cin >> selection;
			if (cin.fail() || selection > (unsigned int)number) {
				cin.clear(); //clear the error state
				while (cin.get() != '\n') {}; // clear the  buffer
				cout << "Invalid Selection, try again: ";

			}
			else {

				result = false;
			}
		}
		return selection;
	}
}
