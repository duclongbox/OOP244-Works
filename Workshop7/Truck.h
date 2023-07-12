#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "../workshop2/cstring.h"
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
		ostream& write(ostream& os);
		istream& read(istream& in);

	};
	std::istream& operator >> (istream& is,  Truck& truck);
	std::ostream& operator << (ostream& os,  Truck& truck);
}





#endif // !TRUCK_H
