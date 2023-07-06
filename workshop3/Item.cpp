/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P1)
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
#include "Item.h"

#define RATE 0.13
using namespace std;
namespace sdds {
	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
	}
	// set Item to safe empty state
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}
	void Item::set(const char* name, double price, bool taxed) {
		if ( name != nullptr && price > 0.0) {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		
	}

	double Item::price() const {
		return m_price;
	}

	double Item::tax() const {
		double tax = 0.0;
		// if taxed is false return 0.0
		if (!m_taxed) {
			return 0.0;
		}
		else {
			return (m_price * RATE);
		}
		return tax;
	}
	// check item set to empty state
	bool Item::isValid()const {
		bool result = true;
		if (m_price == 0.0 && m_itemName[0] == '\0') {
			result=false;
		}
	
		return result;
	}
	void Item::display()const {
		if (isValid()) {

		// display name
			cout << "| ";
			cout.width(20);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_itemName;
			cout.unsetf(ios::left);

			
		// display price
			cout << " | ";
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout << m_price;
			cout.unsetf(ios::fixed);

		// display taxed
			cout << " | ";
			if (m_taxed == 1) {
				cout << "Yes";
			}
			else cout << "No ";
			cout << " |"<<endl;
		}
		else {
			cout<< "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

}
