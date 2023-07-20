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
#include "Shape.h"

using namespace std;
namespace sdds {
	// write shape object 
	ostream& operator << (ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	// read shape object
	istream& operator >> (istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}

}
