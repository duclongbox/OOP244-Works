#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {
	//insert valid streamable object 
	ostream& operator <<(ostream& os, const Streamable& stream) {
		if (stream) {
			stream.write(os);
		}
		return os;
	}
	//extract streamable object from istream
	istream& operator >>(istream& is, Streamable& stream) {
		stream.read(is);
		return is;
	}

}