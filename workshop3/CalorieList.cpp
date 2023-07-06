/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 6/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
	//set bill to an empty state
	void CalorieList::setEmpty() {
		*m_title = '\0';
		m_items = nullptr;
	}

	bool CalorieList::isValid()const {
		bool result = true;
		int flag = 1;
		//check m_title and m_items are valid
		if (*m_title != '\0' && m_items != nullptr) {
			for (int i = 0; i < m_noOfItems && flag; i++) {
				if (!m_items[i].isValid()) {
					result = false;
					/*break;*/
					flag = 0;
				}
			}
		}
		return result;

	}

	//double CalorieList::totalTax()const {
	//	double totalTax = 0.0;
	//	// calculate total tax 
	//	for (int i = 0; i < m_noOfItems; i++) {
	//		totalTax += m_items[i].tax();
	//	}
	//	return totalTax;
	//}

	int CalorieList::totalCalorie()const {
		int totalPrice = 0;
		// calculate total price
		for (int i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].calorie();
		}
		return totalPrice;
	}
	// display the title of the bill
	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout<<  "|  Daily Calorie Consumption                         |"<< endl; 

		}
		else {
			cout << "| Invalid Bill                                       |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

	}
	// display the total bill
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			//display total tax
			cout << "|    Total Calories for today: ";
			cout.width(8);
			
			cout << totalCalorie() << " |";
			cout.width(13);
			cout << "|"<<endl;

			////display total price			
			//cout << "|              Total Price: ";
			//cout.width(10);
			//cout.setf(ios::fixed);
			//cout.precision(2);
			//cout << totalPrice() << " |" << endl;
			//cout.unsetf(ios::fixed);

			////display total after tax
			//cout << "|          Total After Tax: ";
			//cout.width(10);
			//cout.setf(ios::fixed);
			//cout.precision(2);
			//cout << (totalTax() + totalPrice()) << " |" << endl;
			//cout.unsetf(ios::fixed);
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;

		}
		cout << "+----------------------------------------------------+" << endl;

	}
	void CalorieList::init( int noOfItems) {
		if (noOfItems <= 0) {
			setEmpty();
		}
		else
		{
			// set the number of items
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems]; // allocate memory 
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when) {
		bool result = false;
		//set the next available subject to the incoming argument values
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
			result = true;
		}
		else {
			result = false;
		}
		return result;

	}
	void CalorieList::display() const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();

		}
		footer();

	}
	void CalorieList::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}


}