/*/////////////////////////////////////////////////////////////////////////
						  Milestone-3
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
#include <iostream>
#include "Publication.h"
#include "Utils.h"
#include <string>
using namespace std;
namespace sdds {
	//constructor
	Publication::Publication(){
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}
	// Sets the membership attribute to either zero or a five-digit integer.
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	// Sets the **libRef** attribute value
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	// Sets the date to the current date of the system.
	void Publication::resetDate() {
		m_date = Date();
	}
	//Returns the character 'P' to identify this object as a "Publication object"
	char Publication::type()const {
		return 'P';
	}
	//Returns true is the publication is checkout
	bool Publication::onLoan()const {
		
		return (m_membership>0);
	}
	//Returns the date attribute
	Date Publication::checkoutDate()const {
		return m_date;
	}
	//check argument appeare in m_title
	bool Publication::operator==(const char* title)const {
		bool result = false;
		if (m_title)
			if (strstr(m_title, title)) {
				result = true;
			}
		return result;
	}
	//return m_title attribute
	Publication::operator const char* ()const {
		return m_title;
	}
	//return libref
	int Publication::getRef()const {
		return m_libRef;
	}
	//return true if io referring to cin or cout
	bool Publication::conIO(ios& io)const {
		return (&io == &cin || &io == &cout);
	}
	ostream& Publication::write(ostream& os) const {
		if (conIO(os)) {
			os << "| " << m_shelfId << " |";
			os.setf(ios::left);
			os.width(SDDS_TITLE_WIDTH);
			os.fill('.');
			os << m_title << "| " << (m_membership!=0 ? to_string(m_membership) : " N/A ") << " | " << m_date << " | ";
			
		}
		else {
			os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' <<m_title <<'\t' << m_membership << '\t' << m_date;
		}
		return os;
	}
	istream& Publication::read(istream& istr) {
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
		string shelfID;
		int membership=0;
		int libRef=0;
		string title;
		Date readDate;
		if (conIO(istr)) {
			// read the shelf number
			cout << "Shelf No: ";
			istr >> shelfID;
			if (strLen(shelfID.c_str()) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit); // set stream to fail state
			}
			istr.ignore(100, '\n'); // clear the '\n'
			//read the title
			cout << "Title: ";
			getline(istr, title);
			//read the date
			cout << "Date: ";
			istr >> readDate;
		}
		else{
			istr >> libRef;
			istr.ignore(); //skip the tab
			istr >> shelfID;
			istr.ignore(); //skip the tab
			getline(istr, title, '\t');
			istr >> membership;
			istr.ignore(); //skip the tab
			istr >> readDate;
		}
		if (!readDate) {
			istr.setstate(std::ios_base::failbit); // set stream to fail state
		}
		if (!istr.fail()) {
			strCpy(m_shelfId, shelfID.c_str());
			m_title = new char[title.length() + 1];
			strCpy(m_title, title.c_str());
			m_membership = membership;
			m_libRef = libRef;
			m_date = readDate;
		}
		return istr;
	}
	// return true if title and shelf id not null
	Publication::operator bool() const {
		return (m_title != nullptr || m_shelfId[0] != '\0');
	}
	// copy constructor
	Publication::Publication(const Publication& other):Streamable(other){
		m_membership = other.m_membership;
		m_libRef = other.m_libRef;
		m_date = other.m_date;
		strCpy(m_shelfId, other.m_shelfId);
		if (other.m_title != nullptr) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}
	}
	// copy assignment
	Publication& Publication::operator=(const Publication& other) {
		if (this != &other) {
			delete[] m_title;
			m_title = nullptr;
			m_membership = other.m_membership;
			m_libRef = other.m_libRef;
			m_date = other.m_date;
			strCpy(m_shelfId, other.m_shelfId);
			if (other.m_title != nullptr) {
				m_title = new char[strLen(other.m_title) + 1];
				strCpy(m_title, other.m_title);
			}
		}
		return *this;
	}
	// destructor
	Publication::~Publication() {
		delete[] m_title;
	}


}
