#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"
using namespace std;
namespace sdds {
	class LblShape:public Shape{
		char* m_label{ nullptr };
	protected:
		const char* label() const;
	public:
		LblShape() {};
		LblShape(const char* m_label);
		~LblShape();
		LblShape(const LblShape& other)=delete;
		LblShape& operator=(const LblShape& other)=delete;
		void getSpecs(std::istream& istr);
	};

}

#endif // !LBLSHAPE_H
