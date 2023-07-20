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
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual ~Shape() {}; // empty virtual destructor
		virtual void draw(std::ostream& ostr)const =0;
		virtual void getSpecs(std::istream& istr)=0;
	};
	ostream& operator << (ostream& os, const Shape& shape);
	istream& operator >> (istream& is, Shape& shape);
}


#endif // !SHAPE_H
