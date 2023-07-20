#include "Line.h"

using namespace std;
namespace sdds {
	// set m_value and invoke default constructor  of base class
	Line::Line() : LblShape() {
		m_length = 0;
	}
	// set m_length and pass value by constructor
	Line::Line(const char* label, int length):LblShape(label) {
		m_length = length;
	}
	// read the valid m_length
	void Line::getSpecs(std::istream & istr) {
		bool flagged = false;
		int length;
		LblShape::getSpecs(istr);
		
		while (!flagged) {
			istr >> length;
			if (istr.fail()) {
				// clear errors
				istr.clear();
				// clear input buffer
				while (istr.get() != '\n') {}
			}
			else {
				while (istr.get() != '\n') {} 
				m_length = length;
				flagged = true;
			}
		}
	}

	void Line::draw(std::ostream& ostr)const {
		if (m_length > 0 && LblShape::label() != nullptr) {
			ostr << LblShape::label() << endl;
			for (int i = 0; i < m_length; i++) {
				cout << "=";
			}
			cout << endl;
		}
	}
}