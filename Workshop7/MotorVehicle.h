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
		ostream& write(ostream& os);
		istream& read(istream& in);
	};
	std::istream& operator >> (istream& is,  MotorVehicle& motor);
	std::ostream& operator << (ostream& os,  MotorVehicle& motor);
}



#endif // !MOTORVEHICLE_H