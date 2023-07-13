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

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"MotorVehicle.h"

using namespace std;
namespace sdds {
	// constructor 
	MotorVehicle::MotorVehicle() {
		m_license[0] = '\0';
		m_address[0] = '\0';
		m_year = 0;
	}
	MotorVehicle::MotorVehicle(const char* number, int year) {
		strcpy(m_license, number);
		m_year = year;
		strcpy(m_address,"Factory");
	}
	// move to new address
	void MotorVehicle::moveTo(const char* address) {
		if (strcmp(m_address,address)) {
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout.fill(' ');
			cout << m_license;
			cout << "| |";
			cout.setf(ios::right);
			cout.width(20);
			cout.fill(' ');
			cout << m_address << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout.fill(' ');
			cout << address << "|"<< endl;
			strcpy(m_address, address);
		}
	}

	ostream& MotorVehicle::write(ostream& os)const {
		os << "| " << m_year << " | " << m_license << " | " << m_address;
		return os;
	}
	// read from stream
	istream& MotorVehicle::read(istream& in) {
		cout << "Built Year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_license;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}
	// helper function to insert and extract motorvehicle
	std::istream& operator >> (istream& is,  MotorVehicle &motor) {
		 motor.read(is);
		 return is;
	}
	std::ostream& operator << (ostream& os, const MotorVehicle &motor) {
		 motor.write(os);
		 return os;
	}

}