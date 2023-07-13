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
#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "MotorVehicle.h"
namespace sdds {
	class Truck: public MotorVehicle {
		double m_capacity;
		double m_currentCargo;
	public:
		Truck();
		Truck(const char* license, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	std::istream& operator >> (istream& is,  Truck& truck);
	std::ostream& operator << (ostream& os, const Truck& truck);
}





#endif // !TRUCK_H
