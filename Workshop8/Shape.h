#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual ~Shape() {}; // empty virtual destructor
		virtual void draw(std::ostream& ostr)const =0;
		virtual void getSpecs(std::istream& istr)=0;
	};
	ostream& operator << (ostream& os, const Shape& shape);
	istream& operator >> (istream& is, Shape& shape);
}


#endif // !SHAPE_H
