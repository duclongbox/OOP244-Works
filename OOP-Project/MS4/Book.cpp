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
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	//overide funciton return B
	char Book::type() const {
		return 'B';
	}
	//write method
	ostream& Book::write(ostream& os) const {
		Publication::write(os);
		if (Publication::conIO(os)) {
			/*char authorname[1000];
			strnCpy(authorname, m_authorName, SDDS_AUTHOR_WIDTH);*/
			os.width(SDDS_AUTHOR_WIDTH);
			os.fill(' ');
			//substract the string
			os << string(m_authorName).substr(0, SDDS_AUTHOR_WIDTH )<< " |";
		}
		else {
			os << '\t' << m_authorName;
		}
		return os;
	}
	// read method
	istream& Book::read(istream& istr) {
		Publication::read(istr);
		delete[] m_authorName;
		m_authorName = nullptr;
		char name[1000];
		if (Publication::conIO(istr)) {
			istr.ignore(); // ignore one character
			cout << "Author: ";
			istr.getline(name, 1000);
		}
		else {
			
			istr.ignore(); // ignore the tab
			istr.get(name,1000); 
			
		}
		if (!istr.fail()) {
			m_authorName = new char[strLen(name) + 1];
			strCpy(m_authorName, name);
		
		}
		return istr;
	}
	// reset the date
	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}
	// check author exist 
	Book::operator bool() const {
		return (m_authorName != nullptr && Publication::operator bool());
	}
	// constructor
	Book::Book() {
		m_authorName = nullptr;
	}
	// copy constructor
	Book::Book(const Book& other):Publication(other) {
		if (other.m_authorName != nullptr) {
			m_authorName = new char[strlen(other.m_authorName) + 1];
			strCpy(m_authorName, other.m_authorName);
		}
	}
	// copy assignment
	Book& Book::operator=(const Book& other) {
		if (this != &other) {
			delete[] m_authorName;
			m_authorName = nullptr;
			if (other.m_authorName != nullptr) {
				m_authorName = new char[strLen(other.m_authorName) + 1];
				strCpy(m_authorName, other.m_authorName);
			}
			Publication::operator=(other);
		}
		return *this;
	}
	//destructor
	Book::~Book() {
		delete[] m_authorName;
		m_authorName = nullptr;
	}
}