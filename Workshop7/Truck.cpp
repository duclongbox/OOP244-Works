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
#include <iostream>
#include "Truck.h"

using namespace std;
namespace sdds {
	// constructor
	Truck::Truck(){
		m_capacity = 0.0;
		m_currentCargo = 0.0;
	}
	//call constructor from based class 
	Truck::Truck(const char* license, int year, double capacity, const char* address) : MotorVehicle(license,year){
		m_currentCargo = 0;
		m_capacity = capacity;
		this->moveTo(address);
	}
	// add the weight to current cargo and return true if it change
	bool Truck::addCargo(double cargo) {
		bool result = false;
	
		if ((m_currentCargo + cargo) <= m_capacity) {
			m_currentCargo += cargo;			
			result = true;
		}
		else {
			if (m_currentCargo != m_capacity) {
				m_currentCargo = m_capacity;
				result = true;
			}
		}
		return result;
	}
	// unload the weight if it change, return true. 
	bool Truck::unloadCargo() {
		bool result = false;
		if (m_currentCargo != 0) {
			m_currentCargo = 0;
			result = true;
		}
		return result;
	}
	
	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os); 
		os << " | " << m_currentCargo<<"/"<< m_capacity;
		return os;
	}
	// read the user input
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_currentCargo;
		return in;
	}
	// helper function
	std::istream& operator >> (istream& is,  Truck &truck) {
		truck.read(is);
		return is;
	}
	std::ostream& operator << (ostream& os, const Truck& truck) {
		truck.write(os);
		return os;
	}

}