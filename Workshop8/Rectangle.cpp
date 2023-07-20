/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 7/12/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
using namespace std;
namespace sdds {
	// default constructor
	Rectangle::Rectangle() :LblShape::LblShape(){
		m_height = 0;
		m_width = 0;
	}
	// three argument constr
	Rectangle::Rectangle(const char* label, int width, int height):LblShape(label) {
		if (width < (strlen(LblShape::label()) + 2) && height<3) {
			m_height = 0;
			m_width = 0;
		}
		else {
			m_height = height;
			m_width = width;
		}
	}
	// read two seperated comma value from istream
	void Rectangle::getSpecs(std::istream& istr) {
		bool flagged = false;
		int width;
		int height;
		char ch;
		LblShape::getSpecs(istr);
		while (!flagged) {
			istr >> width;
			if (istr.fail()) {
				// clear errors
				istr.clear();
			}
			else {
				if (istr.get() == ',') {
					istr >> height;
					if (!istr.fail()) {
						
						m_height = height;
						m_width = width;
						//clear input buffer
						while (istr.get(ch)&& ch != '\n') {}
						flagged = true;

					}
					else {
						// clear errors
						istr.clear();
						// clear input buffer
						while (istr.get(ch) && ch != '\n') {}
					}
				}
				
			}
		}
	}
	//
	void Rectangle::draw(std::ostream& ostr)const {
		if (m_height != 0 && m_width != 0) {
			//first line 
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+" << endl;
			// second line 
			ostr << "|";
			ostr.setf(ios::left);
			ostr.width(m_width - 2);
			ostr.fill(' ');
			ostr << LblShape::label();
			ostr << "|" << endl;
			// nexline
			for (int i = 2; i < (m_height-1) ; i++) {
				ostr << "|";
				for (int j = 0; j < m_width - 2; j++) {
					ostr << " ";
				}
				ostr << "|" << endl;
			}
			// last line 
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}
}