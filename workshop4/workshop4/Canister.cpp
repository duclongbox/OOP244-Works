/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P1)
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 6/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "../../workshop2/cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#include <cstring>
#define PI 3.14159265
using namespace std;
namespace sdds {
	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}
	bool Canister::isEmpty()const {
		if (m_contentVolume < 0.00001) {
			return true;
		}
	}
	bool Canister::hasSameContent(const Canister& C)const {
		int i = strCmp(m_contentName, C.m_contentName);
		bool result = false;
		if (m_contentName != nullptr && C.m_contentName != nullptr) {
			if (i == 0) {
				 result=true;
			}
		}
		else { return result; }
	}
	void Canister::setName(const char* Cstr) {
		//if the incoming argument is not null and usable
		if (Cstr != nullptr && m_usable) {
			//delete the current content name
			if (m_contentName) {
				delete[] m_contentName;
				m_contentName = nullptr;
			}
			//allocate memory to the length of Cstr (+1 for null) 
			m_contentName = new char[strLen(Cstr) + 1];
			//copies the Cstr into the newly allocated memory.
			strCpy(m_contentName, Cstr);
		}
	}
	//constructor set to default
	Canister::Canister() {
		setToDefault();
	}
	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		//The smallest Canister can have a height and diameter of 10.0 by 10.0 centimetres 
		//and the largest one can be 40 by 30 respectively.
		if ((height >= 10 && height <= 40) && (diameter >= 10 && diameter <= 30)) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			m_usable = true;
			setName(contentName);

			
		}
		else {
			// set the Canister unsuable
			m_usable = false;
		}
	}
	Canister::~Canister() {
		//Deallocates the dynamic memory 
		//pointed by the content name attribute.
		if (m_contentName) {
			delete[] m_contentName;
			m_contentName = nullptr;
		}
	}
	void Canister::clear() {
		//Clears an unusable Canister back to an empty Canister
		if (!m_usable) {
			if (m_contentName) {
				delete[] m_contentName;
				m_contentName = nullptr;
			}
			
			m_contentVolume = 0;
			m_usable = true;
		}
	}
	double Canister::capacity()const {
		//returns the capacity as stated in Calculating the capacity
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}
	double Canister::volume()const {
		return m_contentVolume;
	}
	Canister& Canister::setContent(const char* contentName) {
		//if the Canister is empty
		if (contentName == nullptr) {
			m_usable = false;
		}
		//if the Canister is empty
		else if (isEmpty()) { setName(contentName); }
		// if the name of the Canister is not the same as the contentName argument
		else if (!hasSameContent(contentName)) { m_usable = false; }
		return *this;
	}
	Canister& Canister::pour(double quantity) {
		//if the quantity fits in the Canister
		if (m_usable && quantity > 0 && (quantity + volume())<=capacity()) {
			// Canister& pour(double quantity);
			m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}
		return *this;
	}
	Canister& Canister::pour(Canister& C) {
		//Set the content name to the Canister argument
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume())) {
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else {
			//pour the content volume 
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}
	std::ostream& Canister::display()const {
		//In 7 spaces prints the capacity
		cout.width(7);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << capacity() << "cc (";
		cout << m_height << "x" << m_diameter << ") Canister";

		// check usable
		if (!m_usable) {
			cout << " of Unusable content, discard!" ;
		}
		// print the name if it is not null
		if(m_usable && m_contentName!=nullptr) {
			cout << " of ";
			cout.width(7);
			cout << volume();
			cout << "cc   " << m_contentName;
		}
		return cout;
	}
}