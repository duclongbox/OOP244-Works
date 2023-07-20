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
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"
#include <cstring>
using namespace std;
namespace sdds {
	class LblShape:public Shape{
		char* m_label{ nullptr };
	protected:
		const char* label() const;
	public:
		LblShape() {};
		LblShape(const char* m_label);
		~LblShape();
		LblShape(const LblShape& other)=delete;
		LblShape& operator=(const LblShape& other)=delete;
		void getSpecs(std::istream& istr);
	};

}

#endif // !LBLSHAPE_H
