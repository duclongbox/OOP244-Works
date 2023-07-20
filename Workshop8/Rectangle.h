#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}

#endif // !RECTANGLE_H
