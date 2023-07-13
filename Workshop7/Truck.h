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
