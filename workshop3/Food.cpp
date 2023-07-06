/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca..ca
Section    : ZAA
Date	   : 6/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;
namespace sdds {
	void Food::setName(const char* name) {
		strnCpy(m_foodName, name, 30);
	}
	// set Item to safe empty state
	void Food::setEmpty() {
		m_calorie = 0;
		m_foodName[0] = '\0';
	}
	void Food::set(const char* name, int calorie, int when) {
		if (name != nullptr && (calorie > 0 && calorie <=3000)) {
			setName(name);
			m_calorie = calorie;
			m_timeConsumption = when;
		}

	}

	int Food::calorie() const {
		return m_calorie;
	}

	//double Item::timeConsumption() const {
	//	double tax = 0.0;
	//	// if taxed is false return 0.0
	//	if (!m_taxed) {
	//		return 0.0;
	//	}
	//	else {
	//		return (m_price * RATE);
	//	}
	//	return tax;
	//}
	// check item set to empty state
	bool Food::isValid()const {
		bool result = true;
		if ((m_calorie <= 0.0||m_calorie>3000) && m_foodName[0] == '\0') {
			result = false;
		}

		return result;
	}
	void Food::display()const {
		if (isValid()) {

			// display name
			cout << "| ";
			cout.width(30);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_foodName;
			cout.unsetf(ios::left);


			// display calorie
			cout << " | ";
			cout.width(4);
			cout.fill(' ');
			cout << m_calorie;

			// display time
			cout << " | ";
			if (m_timeConsumption == 1) {
				cout << "Breakfast  ";
			}
			else if (m_timeConsumption == 2) {
				cout << "Lunch      ";
			}
			else if (m_timeConsumption == 3) {
				cout << "Snack      ";
			}
			else { cout << "Dinner     "; }
			cout << "|" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

}