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
#ifndef LINE_H
#define LINE_H
#include "LblShape.h"

using namespace std;
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}


#endif // !LINE_H
