/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include"Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	// read the selection from user
	unsigned int  read(int number) {
		unsigned selection;
		bool result = true;
		while (result) {
			cin >> selection;
			if (selection == '\0' || selection<0 || selection>number) {
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