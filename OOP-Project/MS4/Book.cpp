#include <iostream>
#include <string>
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
			os << " ";
			os.width(SDDS_AUTHOR_WIDTH);
			os.fill(' ');
			os << m_authorName << " |";
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
		string name;
		if (Publication::conIO(istr)) {
			istr.ignore(); // ignore one character
			cout << "Author: ";
			istr >> name;

		}
		else {
			char ch;
		

			istr.ignore(); // ignore the tab
			getline(istr, name);
			
		}
		if (!istr.fail()) {
			m_authorName = new char[strLen(name.c_str()) + 1];
			strCpy(m_authorName, name.c_str());
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
			if (other.m_authorName != nullptr) {
				m_authorName = new char[strlen(other.m_authorName) + 1];
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