/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7
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
#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include <iostream>
#include "..\workshop2\cstring.h"
#define SIZEPLATE 9
#define ADDRESS 64
using namespace std;
namespace sdds {
	class MotorVehicle{
		char m_license[SIZEPLATE];
		char m_address[ADDRESS];
		int m_year;
	public:
		MotorVehicle();
		MotorVehicle(const char* number, int year);
		void moveTo(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& in) ;
	};
	std::istream& operator >> (istream& is,  MotorVehicle& motor);
	std::ostream& operator << (ostream& os, const MotorVehicle& motor);
}



#endif // !MOTORVEHICLE_H