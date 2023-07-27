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
#ifndef STREAMABLE_H
#define STREAMABLE_H
#include <iostream>
using namespace std;
namespace sdds {
	class Streamable {
	public:
		virtual ostream& write(ostream& os)const = 0;


		virtual istream& read(istream& is) = 0;

		/*This method is not capable of modifying the Streamable object.conIo receives
		a reference of an ios object and returns a Boolean.
		Functions overriding this function will determine if the incoming ios object is a console IO object or not.*/
		virtual bool conIO(ios& io) const = 0;

		/*Boolean conversion overloads of this method will return if the
		Streamable object is in a valid state or not.*/
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};
	ostream& operator <<(ostream& os, const Streamable& stream);
	istream& operator >>(istream& is, Streamable& stream);
}


#endif // !STREAMABLE_H

