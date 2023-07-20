#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <string>
using namespace std;
namespace sdds {
	// return the unmodifiable value of m_label
	 const char* LblShape::label() const {
		return m_label;
	}
	 // allocate memory for m_label to hold incoming value
	 LblShape::LblShape(const char* label) {
		 if (label != nullptr) {
			 m_label = new char[strlen(label) + 1];
			 strcpy(m_label, label);
		 }
	 }
	 //destructor
	 LblShape::~LblShape() {
		 delete[] m_label;
	 }
	 // read and store the input stream
	 void  LblShape::getSpecs(std::istream& istr) {
		 string ch;
		
		 getline(istr,ch, ',');
		 // free the previous allocated memory 
		 delete[] m_label;
		 m_label = new char[strlen(ch.c_str()) + 1];
		 strcpy(m_label, ch.c_str());
	 }
}