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
		strCpy(m_license, number);
		m_year = year;
		strCpy(m_address,"Factory");
	}
	// move to new address
	void MotorVehicle::moveTo(const char* address) {
		if (!strCmp(m_address,address)) {
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout.fill(' ');
			cout << m_license;
			cout << "| |";
			cout.setf(ios::right);
			cout.width(20);
			cout.fill(' ');
			cout << m_address << " --->";
			cout.setf(ios::left);
			cout.width(20);
			cout.fill(' ');
			cout << address;
			strCpy(m_address, address);
		}
	}
	ostream& MotorVehicle::write(ostream& os) {
		os << "| " << m_year << " | " << m_license << " | " << m_address;
		return os;
	}
	istream& MotorVehicle::read(istream& in) {
		cout << "Built Year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_license;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}
	std::istream& operator >> (istream& is,  MotorVehicle& motor) {
		 motor.read(is);
		 return is;
	}
	std::ostream& operator << (ostream& os,  MotorVehicle& motor) {
		 motor.write(os);
		 return os;
	}

}