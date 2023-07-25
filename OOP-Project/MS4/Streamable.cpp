/*/////////////////////////////////////////////////////////////////////////
						  Milestone-4
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
#include "Streamable.h"

using namespace std;
namespace sdds {
	//insert valid streamable object 
	ostream& operator <<(ostream& os, const Streamable& stream) {
		if (stream) {
			stream.write(os);
		}
		return os;
	}
	//extract streamable object from istream
	istream& operator >>(istream& is, Streamable& stream) {
		stream.read(is);
		return is;
	}

}