#include "Shape.h"

using namespace std;
namespace sdds {
	// write shape object 
	ostream& operator << (ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	// read shape object
	istream& operator >> (istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}

}
