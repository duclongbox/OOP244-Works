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
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
	//set bill to an empty state
	void Bill::setEmpty(){
		*m_title = '\0';
		m_items = nullptr;
	}
	
	bool Bill::isValid()const {
		bool result=true;
		int flag = 1;
		//check m_title and m_items are valid
		if (*m_title != '\0' && m_items != nullptr) {
			for (int i = 0; i < m_noOfItems&& flag; i++) {
				if (!m_items[i].isValid()) {
					result= false;
					/*break;*/
					flag = 0;
				}

			}
		}
		return result;
		
	}

	double Bill::totalTax()const {
		double totalTax = 0.0;
		// calculate total tax 
		for (int i = 0; i < m_noOfItems; i++) {
			totalTax += m_items[i].tax();
		}
		return totalTax;
	}

	double Bill::totalPrice()const {
		double totalPrice = 0;
		// calculate total price
		for (int i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].price();
		}
		return totalPrice;
	}
	// display the title of the bill
	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title << " |" << endl;
			cout.unsetf(ios::left);
			
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;

	}
	// display the total bill
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			//display total tax
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() << " |" << endl;
			cout.unsetf(ios::fixed);
			
			
			//display total price			
			cout << "|              Total Price: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice() << " |" << endl;
			cout.unsetf(ios::fixed);

			//display total after tax
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << (totalTax() + totalPrice())<< " |" << endl;
			cout.unsetf(ios::fixed);
		}
		else {
			cout << "| Invalid Bill                         |" << endl;

		}
		cout << "+--------------------------------------+" << endl;

	}
	void Bill::init(const char* title, int noOfItems) {
		if (strLen(title)==0||noOfItems<=0) {
			setEmpty();
		}
		else
		{
			// set the number of items
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title,title , 36); 
			m_items = new Item[m_noOfItems]; // allocate memory 
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool result = false;
		//set the next available subject to the incoming argument values
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			result=true;
		}
		else {
			result= false;
		}
		return result;

	}
	void Bill::display() const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();

		}
		footer();

	}
	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}


}