/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date		7/11/2023
// Author  	Long Duc Hoang
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